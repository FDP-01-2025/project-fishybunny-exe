#include "Utils.h"
#include <iostream>
#include <limits>

// getIntInput: solicita hasta que el usuario introduce un entero válido entre min y max
int getIntInput(int min, int max)
{
    int v;
    while (true)
    {
        if (!(std::cin >> v))
        {
            std::cin.clear();
        }
    }
}