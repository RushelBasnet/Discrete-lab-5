Write a program to generate the next r combination in lexicographic order.
#include <iostream>
#include <vector>
#include <algorithm>

// Function to generate the next combination
bool nextCombination(std::vector<int> &comb, int n, int r) {
    // Find the first element that can be increased
    int i = r - 1;
    while (i >= 0 && comb[i] == n - r + i) {
        i--;
    }

    // If no such element is found, we are at the last combination
    if (i < 0) {
        return false;
    }

    // Increase this element
    comb[i]++;

    // Adjust the remaining elements
    for (int j = i + 1; j < r; j++) {
        comb[j] = comb[j - 1] + 1;
    }

    return true;
}

int main() {
    int n = 5; // Total elements
    int r = 3; // Number of elements in the combination

    // Initialize the first combination
    std::vector<int> combination(r);
    for (int i = 0; i < r; ++i) {
        combination[i] = i;
    }

    std::cout << "Current combination: ";
    for (int i = 0; i < r; ++i) {
        std::cout << combination[i] << " ";
    }
    std::cout << std::endl;

    // Generate the next combination
    if (nextCombination(combination, n, r)) {
        std::cout << "Next combination: ";
        for (int i = 0; i < r; ++i) {
            std::cout << combination[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No next combination available." << std::endl;
    }

    return 0;
}

