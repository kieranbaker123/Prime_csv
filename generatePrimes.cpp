// generatePrimes.cpp

#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "primes.csv"

bool isPrimeCandidate(long long int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    for (long long int i = 7; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void generateNextNPrimes(long long int count_needed) {
    if (count_needed <= 0) return;

    long long int last_prime = 1;
    std::ifstream file(FILE_NAME);
    if (check_file.is_open()) {
        long long int val;
        while (check_file >> val) {
            last_prime = val;
        }
        check_file.close();
    }
