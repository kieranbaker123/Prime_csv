// primes.cpp

#include <iostream>
#include <fstream>
#include <vector>

#define FILE_NAME "primes.csv" // already generated primes, csv seperated by ' '

bool isItPrime(long long int a)
{
    int c = a % 30;

    switch (c) // can be prime?
    {
        case 1:   case 29: // 30 +- 1
        case 7:   case 23: // 30 +- 7
        case 11:  case 19: // 30 +- 11
        case 13:  case 17: // 30 +- 13
            break;
        default:
            if ( a == 2 || a == 3 || a == 5 )
            {
                return 1;
            }
            return 0;
    }

    std::ifstream file(FILE_NAME);
    
    if (!file.is_open()) 
    {
        std::cout << "Error: Could not open the file." << std::endl;
        return -1;
    }

    std::vector<long long int> primes;

    long long int value = 31;

    while ( file >> value )
    {
        if ( value == a )
        {
            file.close();
            return 1;
        }
        if ( a % value == 0 )
        {
            file.close();
            return 0;
        }
        primes.push_back(value);
        if ( value * value > a )
        {
            file.close();
            return 1;
        }
    }
    
    file.close();

    for (long long int i = value; i * i <= a; i += 2) 
    {
        if (a % i == 0) return false;
    }

    return true;
}
