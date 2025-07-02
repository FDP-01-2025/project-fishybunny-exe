#include "Utils.h"
#include <iostream>
#include <limits>

// getIntInput: solicita hasta que el usuario introduce un entero válido entre min y max
int getIntInput(int min, int max) {
    int v;
    while (true) {
        if (!(std::cin >> v)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number between " << min << " and " << max << ": ";
            continue;
        }
        if (v < min || v > max) {
            std::cout << "Please enter a value between " << min << " and " << max << ": ";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return v;
    }
}

// getCharInput: lee el siguiente carácter no ignorando saltos de línea
char getCharInput() {
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return c;
}

// splitString: divide s en trozos según delimiter
std::vector<std::string> splitString(const std::string &s, char delimiter) {
    std::vector<std::string> parts;
    std::string cur;
    for (char ch : s) {
        if (ch == delimiter) {
            parts.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(ch);
        }
    }
    parts.push_back(cur);
    return parts;
}

// getTypeMultiplier: ejemplo básico de fortalezas/debilidades
float getTypeMultiplier(int atkType, int defType) {
    if (atkType == defType) return 1.0f;
    switch (atkType) {
        case 0: if (defType == 5) return 2.0f; if (defType == 1) return 0.5f; break;
        case 1: if (defType == 0) return 2.0f; if (defType == 4) return 0.5f; break;
        case 2: if (defType == 4) return 2.0f; if (defType == 3) return 0.5f; break;
        case 3: if (defType == 2) return 2.0f; if (defType == 17) return 0.5f; break;
        case 4: if (defType == 1) return 2.0f; if (defType == 2) return 0.5f; break;
        // añade más si expandes tipos
        default: break;
    }
    return 1.0f;
}

// getTypeName: convierte un ID en su nombre textual
std::string getTypeName(int typeID) {
    static const std::vector<std::string> names = {
        "Fire","Water","Earth","Air","Lightning","Ice",
        "Metal","Beast","Mystic","Undead","Holy","Dark",
        "Nature","Poison","Psychic","Dragon","Normal","Rock"
    };
    if (typeID >= 0 && typeID < (int)names.size()) {
        return names[typeID];
    }
    return "Unknown";
}