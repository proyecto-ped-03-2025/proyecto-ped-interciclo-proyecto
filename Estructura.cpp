#include <iostream>
#include <string>

using namespace std;

struct Jugador{
    string nombre;
    char id;
    int puntos;
    Jugador* sig;
};

class ListaCircular{
private:
    Jugador* primero;

public:
    ListaCircular(){
        primero = NULL;
    }

    bool vacia(){
        return primero == NULL;
    }
};
