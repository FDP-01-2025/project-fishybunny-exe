#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <vector>
using namespace std;
// Carga y guarda usuarios
void loadUsers();
void saveUsers();

// Muestra lista de usuarios
void showUsers();

// Selecciona un usuario (retorna índice o -1 para gestionar)
int selectUser();

// Crea y borra usuarios
int createUser(const string &name);
void deleteUser(int index);

// Consulta nombre y lista interna
string getUserName(int index);
const vector<string>& getUsers();

#endif

