#include "methods.h"

std::vector<Item> countingSort(std::vector<Item>& items, const std::string& attribute, bool ascending)
{
    if(attribute != "age" && attribute != "type" && attribute != "origin" && attribute != "rarityScore"){ // Check if the attribute is valid
        std::cout << "Invalid attribute" << std::endl; // Print error message
        return items; // Return the items vector as it is
    }

    int n = items.size(); // Get the size of the items vector

    int max = getMax(items, attribute); // Get the maximum value of the attribute

    int countArray[max + 1] = {0}; // Create an array to store the count of each element

    for(int i = 0; i < n; i++){ // Iterate through the items vector
        if(attribute == "age"){ // Check if the attribute is age
            countArray[items[i].age]++; // Increment the count of the age of the current item
        }
        else if(attribute == "type"){ // Check if the attribute is type
            countArray[items[i].type]++; // Increment the count of the type of the current item
        }
        else if(attribute == "origin"){ // Check if the attribute is origin
            countArray[items[i].origin]++; // Increment the count of the origin of the current item
        }
        else if(attribute == "rarity"){ // Check if the attribute is rarity
            countArray[(int)items[i].rarityScore]++; // Increment the count of the rarity of the current item
        }
    }

    for(int i = 1; i <= max; i++){ // Iterate through the count array
        countArray[i] += countArray[i - 1]; // Update the count array
    }

    std::vector<Item> sorted(n); // Create a vector to store the sorted items

    for(int i = n - 1; i >= 0; i--){ // Iterate through the items vector in reverse order
        if(attribute == "age"){ // Check if the attribute is age
            sorted[countArray[items[i].age] - 1] = items[i]; // Add the item to the sorted vector
            countArray[items[i].age]--; // Decrement the count of the age of the current item
        }
        else if(attribute == "type"){ // Check if the attribute is type
            sorted[countArray[items[i].type] - 1] = items[i]; // Add the item to the sorted vector
            countArray[items[i].type]--; // Decrement the count of the type of the current item
        }
        else if(attribute == "origin"){ // Check if the attribute is origin
            sorted[countArray[items[i].origin] - 1] = items[i]; // Add the item to the sorted vector
            countArray[items[i].origin]--; // Decrement the count of the origin of the current item
        }
        else if(attribute == "rarityScore"){ // Check if the attribute is rarity
            sorted[countArray[(int)items[i].rarityScore] - 1] = items[i]; // Add the item to the sorted vector
            countArray[(int)items[i].rarityScore]--; // Decrement the count of the rarity of the current item
        }
    }

    if(ascending){ // Check if the sorting order is ascending
        return sorted; // Return the sorted vector
    }
    else{ // If the sorting order is descending, reverse the sorted array
        std::vector<Item> descending(n); // Create a vector to store the descending sorted items
        for(int i = 0; i < n; i++){ // Iterate through the items vector
            descending[i] = sorted[n - i - 1]; // Add the item to the descending sorted vector
        }
        return descending; // Return the descending sorted vector
    }
}

// Function to heapify a subtree rooted with node i in the array of items
void heapify(std::vector<Item>& items, int n, int i, bool descending)
{
    int left = 2 * i + 1 ;   // left child
    int right = 2 * i + 2; // right child
    int largest = i; // Initialize largest as root

    if(left < n && (descending ? items[left].rarityScore > items[largest].rarityScore : items[left].rarityScore < items[largest].rarityScore)){ // If left child is larger than root
        largest = left; // Set largest to left
    }
    if(right < n && (descending ? items[right].rarityScore > items[largest].rarityScore : items[right].rarityScore < items[largest].rarityScore)){ // If right child is larger than largest so far
        largest = right; // Set largest to right
    }
    if(largest != i){ // If largest is not root
        std::swap(items[i], items[largest]); // Swap items[i] with items[largest]
        heapify(items, n, largest, descending); // Recursively heapify the affected sub-tree
    }
    
    
}

// Function to perform heap sort on rarityScore scores of items
std::vector<Item> heapSortByRarity(std::vector<Item>& items, bool descending)
{
    int n = items.size(); // Get the size of the items vector

    for(int i = n / 2 - 1; i >= 0; i--){ // Build heap (rearrange array)
        
        heapify(items, n, i, !descending); // Heapify the subtree rooted at index i
    }

    for(int i = n - 1; i >= 0; i--){ // One by one extract an element from heap
        std::swap(items[0], items[i]); // Move current root to end
        heapify(items, i, 0, !descending); // Call max heapify on the reduced heap
    }
  
    return items; // Return the sorted items vector

}
