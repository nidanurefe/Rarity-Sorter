#include "methods.h"

int getMax(std::vector<Item>& items, const std::string& attribute)
{
    int max = 0; // Initialize the maximum value to 0
    
    if(attribute != "age" && attribute != "type" && attribute != "origin" && attribute != "rarity"){ // Check if the attribute is valid
        std::cout << "Invalid attribute" << std::endl; // Print error message
        return -1; // Return -1
    }
    else {
        if(attribute == "age"){
            for(const Item& item : items){ // Iterate through the items vector
                if(item.age > max){ // Check if the age of the current item is greater than the current maximum
                    max = item.age; // Update the maximum value
                }
            }
        }
        else if(attribute == "type"){ // Check if the attribute is type
            for(const Item& item : items){ // Iterate through the items vector
                if(item.type > max){ // Check if the type of the current item is greater than the current maximum
                    max = item.type; // Update the maximum value
                }
            }
        }
        else if(attribute == "origin"){ // Check if the attribute is origin
            for(const Item& item : items){ // Iterate through the items vector
                if(item.origin > max){ // Check if the origin of the current item is greater than the current maximum
                    max = item.origin; // Update the maximum value
                }
            }
        }
        else if(attribute == "rarity"){ // Check if the attribute is rarity
            for(const Item& item : items){ // Iterate through the items vector
                if(item.rarityScore > max){ // Check if the rarity of the current item is greater than the current maximum
                    max = item.rarityScore; // Update the maximum value
                }
            }
        }

    }

    
    return max; // Return the maximum value
}

// min = age - ageWindow
// max = age + ageWindow
// rarityScore = (1 - probability) * (1 + item.age/ageMax)
void calculateRarityScores(std::vector<Item>& items, int ageWindow)
{
    int ageMax = getMax(items, "age"); // Get the maximum age value
    int n = items.size(); // Get the size of the items vector

    for(Item& item : items){ // Iterate through the items vector
        int min = item.age - ageWindow; // Calculate the minimum age
        int max = item.age + ageWindow; // Calculate the maximum age
        double probability = 0.0; // Initialize the probability to 0 for each item

        for(const Item& rest : items){ // Iterate through the items vector
            if(rest.age >= min && rest.age <= max){ // Check if the age of the other item is within the range
                probability += 1.0; // Increment the probability
            }
        }

        probability = probability/n; // Calculate the probability
        item.rarityScore = (1 - probability) * (1 + item.age / ageMax); // Calculate the rarity score
    }



}
