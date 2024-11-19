#include "methods.h"
// #include <chrono>


int main() 
{
  
  std::vector<Item> items = readItemsFromFile("data/items_l.csv");
  std::vector<Item> sorted = countingSort(items, "age", true);
  writeItemsToFile("data/items_l_sorted.csv", sorted);
  calculateRarityScores(sorted, 10);
  writeItemsToFile("data/items_l_rarity.csv", sorted);
  sorted = heapSortByRarity(sorted, true);
  writeItemsToFile("data/items_l_rarity_sorted.csv", sorted);



  // This section is used to measure durations for the report
  /*
  auto start = std::chrono::high_resolution_clock::now();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration;
  
  std::vector<Item> itemsL = readItemsFromFile("data/items_l.csv");
  std::vector<Item> itemsM = readItemsFromFile("data/items_m.csv");
  std::vector<Item> itemsS = readItemsFromFile("data/items_s.csv");

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sortedL = countingSort(itemsL, "age", true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;

  std::cout << "Duration for counting sort on large dataset: " <<  duration.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sortedM = countingSort(itemsM, "age", true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "Duration for counting sort on medium dataset: " << duration.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sortedS = countingSort(itemsS, "age", true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "Duration for counting sort on small dataset: " << duration.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  sortedS = heapSortByRarity(sortedS, true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "Duration for counting sort on small dataset: " << duration.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  sortedM = heapSortByRarity(sortedM, true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "Duration for counting sort on medium dataset: " << duration.count() << std::endl;

  start = std::chrono::high_resolution_clock::now();
  sortedL = heapSortByRarity(sortedL, true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "Duration for counting sort on large dataset: " << duration.count() << std::endl;
  */

  return 0;
}