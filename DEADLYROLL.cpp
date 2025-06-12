#include <iostream> //Bibliotecas
using namespace std;
int main()
{
    string usuario, decision;
    cout << "Bienvenido al Desafio de Dados" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Te enfrentas a un enemigo en un duelo por turnos donde la suerte y la estrategia" << endl;
    cout << "decidiran tu destino." << endl
         << endl;

    cout << "Cada ronda, lanzaras un dado contra tu rival. Quien saque el numero mas alto" << endl;
    cout << "decide si ataca, se defiende, usa una habilidad especial o guarda puntos para" << endl;
    cout << "un movimiento mas poderoso en el futuro." << endl
         << endl;
    cout << "----------------------------------------" << endl;

    cout << "Ya tienes un usuario creado?, si ya tienes uno ingresa S, si no ingresa N" << endl;
    cin >> decision;
    if (decision == "S")
    {
        cout << "Perfecto, ahora elige cual es tu usuario." << endl;
    }
    else if (decision == "N")
    {
        cout << "Ingresa el nombre de usuario que deseas." << endl;
        cin >> usuario;
    }

    return 0;
}
