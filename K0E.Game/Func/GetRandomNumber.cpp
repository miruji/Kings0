#include "GetRandomNumber.h"

// Get random number
int GetRandomNumber(int min, int max)
{
    // Random
    std::random_device rd;
    std::mt19937 mersenne(rd()); 

    srand(mersenne() / 10);
    // ...
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // ...
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}