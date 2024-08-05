#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to perform modular exponentiation
// It returns (base^exponent) % mod
unsigned long long modularExponentiation(unsigned long long base, unsigned long long exponent, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1; // exponent = exponent / 2
        base = (base * base) % mod;
    }

    return result;
}

// Function to check primality using Fermat's Little Theorem
bool isPrimeFermat(unsigned long long n, int iterations = 5) {
    // Edge cases
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;

    // Perform the test multiple times to reduce the probability of a false positive
    for (int i = 0; i < iterations; i++) {
        unsigned long long a = 2 + std::rand() % (n - 3);
        if (modularExponentiation(a, n - 1, n) != 1) {
            return false;
        }
    }

    return true;
}

int main() {
    std::srand(std::time(0)); // Seed for random number generation

    unsigned long long number;
    std::cout << "Enter a number to check for primality: ";
    std::cin >> number;

    if (isPrimeFermat(number)) {
        std::cout << number << " is probably a prime number." << std::endl;
    } else {
        std::cout << number << " is not a prime number." << std::endl;
    }

    return 0;
}

