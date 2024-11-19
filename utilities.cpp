#include "methods.h"

std::vector<Item> readItemsFromFile(const std::string& filename) 
{
    std::ifstream source; // Declare ifstream object
    std::vector<Item> items; // Declare the vector to store the items
    std::string line; // Declare the string to store each line

    source.open(filename); // Open the file

    if(source.is_open()){ // Check if the file is opened
        std::getline(source, line); // Skip the headlines of the file (age,type,origin,rarity)

        while(std::getline(source, line)){ // Read the file line by line
            std::stringstream ss(line); // Create a stringstream object
            Item item; // Create an empty item object
            std::string temp; // A temporary variable to store the age, type, origin, and rarity read from file

            std::getline(ss, temp, ',');  //Read the line until the first comma and save it into temp
            item.age = std::stoi(temp); // Convert the temp string to int and save it into age

            std::getline(ss, temp, ','); // Read the line until the second comma and save it into temp
            item.type = std::stoi(temp); // Convert the temp string to int and save it into type

            std::getline(ss, temp, ','); // Read the line until the third comma and save it into temp
            item.origin = std::stoi(temp); // Convert the temp string to int and save it into origin

            std::getline(ss, temp, ','); // Read the remaining line and save it into temp
            item.rarityScore = std::stof(temp); // Convert the temp string to float and save it into rarityScore

            items.push_back(item); // Add the item object to the items vector
        }
        source.close(); // Close the file
    }
    else{ // If the file is not opened
        std::cout << "Unable to open file" << std::endl; // Print error message 
    }

    return items; // Return the items vector


}

void writeItemsToFile(const std::string& filename, const std::vector<Item>& items) 
{
    std::ofstream destination; // Declare an empty ofstream object to write items into 
    destination.open(filename); // Open the file

    if(destination.is_open()){ // Check if the output file is opened
        destination << "age,type,origin,rarity" << std::endl; // Write the header to the file
        for(const Item& item : items){ // Iterate through the items vector
            destination << item.age << "," << item.type << "," << item.origin << "," << item.rarityScore << std::endl; // Write the age, type, origin, and rarity to the file
        }
        destination.close(); // Close the file
    }
    else{ // If the file is not opened
        std::cout << "Unable to open file" << std::endl; // Print error message
    }

}
