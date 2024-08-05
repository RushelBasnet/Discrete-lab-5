#include <iostream>
#include <vector>
#include <algorithm>

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to reverse the elements of a vector from start to end
void reverse(std::vector<int> &nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

// Function to find the next permutation
bool nextPermutation(std::vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first decreasing element
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // If no such element is found, the sequence is the last permutation
    if (i < 0) {
        return false;
    }

    // Find the element just larger than nums[i]
    int j = n - 1;
    while (nums[j] <= nums[i]) {
        j--;
    }

    // Swap the elements
    swap(nums[i], nums[j]);

    // Reverse the sequence from i+1 to the end
    reverse(nums, i + 1, n - 1);

    return true;
}

int main() {
    std::vector<int> nums = {1, 2, 3};

    std::cout << "Current permutation: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    if (nextPermutation(nums)) {
        std::cout << "Next permutation: ";
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No next permutation available." << std::endl;
    }

    return 0;
}

