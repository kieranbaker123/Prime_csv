// generatePrimes.cpp

#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "primes.csv"

bool isPrimeCandidate(long long int n)
{
    if (n <= 1) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    for (long long int i = 7; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void generateNextNPrimes(long long int countNeeded) 
{
    if (countNeeded <= 0) return;

    long long int lastPrime = 1;
    std::ifstream inFile(FILE_NAME);
    if (inFile.is_open()) 
    {
        long long int val;
        while (inFile >> val) 
        {
            lastPrime = val;
        }
        inFile.close();
    }

    std::ofstream file(FILE_NAME, std::ios::app);
    if (!file.is_open()) 
    {
        std::cout << "Error: Could not open file for writing." << std::endl;
        return;
    }
    
    long long int countAdded = 0;

    if (lastPrime < 2 && countAdded < countNeeded) 
    { 
        file << "2 "; 
        lastPrime = 2; 
        countAdded++; 
    }
    if (lastPrime < 3 && countAdded < countNeeded) 
    { 
        file << "3 "; 
        lastPrime = 3; 
        countAdded++; 
    }
    if (lastPrime < 5 && countAdded < countNeeded) 
    { 
        file << "5 "; 
        lastPrime = 5;     
        countAdded++; 
    }

    const int wheel[] = {1, 7, 11, 13, 17, 19, 23, 29};
    long long int start = (lastPrime / 30) * 30;
    long long int num;    

    for ( long long int base = start; countAdded < countNeeded; base += 30 )
    {
        for ( int i = 0; i < 8; i++ )
        {
            num = base + wheel[i];

            if ( num <= lastPrime )
            {
                continue;
            }

            if ( isPrimeCandidate(num) )
            {
            file << num << " ";
            countAdded++;
            }

            if (countAdded == countNeeded) 
            {
                break;
            }
        }
    }
    file.close();
    std::cout << "Successfully added next " << countNeeded << " primes to " << FILE_NAME << std::endl;
}

int main(int argc, char* argv[])
{
    long long int n = std::stoll(argv[1]);

    generateNextNPrimes(n);

    return 0;
}
