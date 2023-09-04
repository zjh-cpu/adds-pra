#include <iostream>
#include <sstream>
#include <vector>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::string line;
    getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> numbers;
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    QuickSort qSort;
    numbers = qSort.sort(numbers);
    RecursiveBinarySearch rbSearch;
    bool found = rbSearch.search(numbers, 1);
    std::cout << (found ? "true" : "false") << " ";
    for (int i : numbers) {
        std::cout << i << " ";
    }
    return 0;
}
