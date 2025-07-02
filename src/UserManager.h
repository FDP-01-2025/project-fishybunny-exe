#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <vector>

// Carga y guarda usuarios
void loadUsers();
void saveUsers();

// Muestra lista de usuarios
void showUsers();

// Selecciona un usuario (retorna índice o -1 para gestionar)
int selectUser();

// Crea y borra usuarios
int createUser(const std::string &name);
void deleteUser(int index);

// Consulta nombre y lista interna
std::string getUserName(int index);
const std::vector<std::string>& getUsers();

#endif