#include "UserManager.h"
#include "FileManager.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
static vector<string> users;// Lista de usuarios guardada en memoria
static const string USERS_FILE = "users.txt"; // Nombre del archivo donde se guardan los usuarios

void loadUsers() { //Carga los usuarios
    users.clear();//Limpia
    vector<string> lines; // Lista para guardar las líneas del archivo
    if (readFileLines(USERS_FILE, lines)) { //Verifica que se abre el archivo
        for (auto &l : lines) //Recorre cada linea
            if (!l.empty()) //Si la linea no esta vacia
                users.push_back(l); //Agrega el usuario al archivo
    }
}

void saveUsers() { //Guarda los usuarios
    writeFileLines(USERS_FILE, users); //Escribe en el archivo la lista de usuarios
}

void showUsers() { //Muestra los usuarios
    cout << "\nUsers:\n";
    for (size_t i = 0; i < users.size(); ++i)
        cout << i+1 << ") " << users[i] << "\n"; //Muestra cada usuario con su numero
}

int selectUser() { // Selecciona los usuarios
    if (users.empty()) return -1;// Si no hay usuarios, retorna -1
    showUsers();// Muestra los usuarios
    cout << "Select user (#) or 0 to manage: "; // Pide número válido
    int c = getIntInput(0, (int)users.size());
    return c ? c - 1 : -1;  // Si eligió 0, retorna -1; si no, devuelve índice
}

int createUser(const string &name) { // Crea los usuarios
    if (users.size() >= 3) {
        cout << "Max 3 users.\n"; // Solo se permiten 3 usuarios
        return -1;
    }
    users.push_back(name); // Agrega el nuevo usuario
    saveUsers(); // Guarda la lista actualizada
    return (int)users.size() - 1; // Retorna el índice del nuevo usuario
}

void deleteUser(int idx) { //Elimina los usuarios
    if (idx >= 0 && idx < (int)users.size()) { // Verifica que el índice sea válido
        users.erase(users.begin() + idx);// Borra al usuario
        saveUsers(); // Guarda la lista actualizada
    }
}

string getUserName(int idx) { // Devuelve el nombre del usuario según su índice
    return (idx >= 0 && idx < (int)users.size()) ? users[idx] : "";
}

const vector<string>& getUsers() { // Devuelve la lista completa de usuarios
    return users;
}

