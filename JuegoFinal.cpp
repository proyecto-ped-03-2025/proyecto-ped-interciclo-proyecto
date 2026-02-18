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

    void insertar(string nombre, char id){

        Jugador* nuevo = new Jugador();
        nuevo->nombre = nombre;
        nuevo->id = id;
        nuevo->puntos = 0;

        if(vacia()){
            primero = nuevo;
            nuevo->sig = primero;
        }else{
            Jugador* aux = primero;

            while(aux->sig != primero){
                aux = aux->sig;
            }

            aux->sig = nuevo;
            nuevo->sig = primero;
        }
    }

    void mostrar(){

        if(vacia()){
            cout << "No hay jugadores" << endl;
            return;
        }

        Jugador* aux = primero;

        cout << "Jugadores inscritos" << endl;

        do{
            cout << aux->nombre << " ";
            cout << aux->id << " ";
            cout << aux->puntos << endl;
            aux = aux->sig;
        }while(aux != primero);
    }

    int jugar(){

        int opcion;

        do{
            cout << "1 Piedra" << endl;
            cout << "2 Papel" << endl;
            cout << "3 Tijera" << endl;
            cin >> opcion;
        }while(opcion < 1 || opcion > 3);

        return opcion;
    }

    int evaluar(int j1, int j2){

        if(j1 == j2)
            return 0;

        if((j1 == 1 && j2 == 3) ||
           (j1 == 2 && j2 == 1) ||
           (j1 == 3 && j2 == 2))
            return 1;
        else
            return 2;
    }

    void competencia(){

        if(vacia() || primero->sig == primero){
            cout << "Se necesitan al menos dos jugadores" << endl;
            return;
        }

        Jugador* i = primero;

        do{
            Jugador* j = i->sig;

            while(j != primero){

                cout << "Juegan ";
                cout << i->nombre;
                cout << " contra ";
                cout << j->nombre << endl;

                cout << i->nombre << " elija opcion" << endl;
                int r1 = jugar();

                cout << j->nombre << " elija opcion" << endl;
                int r2 = jugar();

                int resultado = evaluar(r1, r2);

                if(resultado == 1){
                    i->puntos += 3;
                    cout << i->nombre << " gana" << endl;
                }
                else if(resultado == 2){
                    j->puntos += 3;
                    cout << j->nombre << " gana" << endl;
                }
                else{
                    i->puntos += 1;
                    j->puntos += 1;
                    cout << "Empate" << endl;
                }

                j = j->sig;
            }

            i = i->sig;

        }while(i != primero);

        cout << "Competencia terminada" << endl;
    }

    void ganador(){

        if(vacia()){
            cout << "No hay jugadores" << endl;
            return;
        }

        Jugador* aux = primero;
        Jugador* mayor = primero;

        do{
            if(aux->puntos > mayor->puntos){
                mayor = aux;
            }
            aux = aux->sig;
        }while(aux != primero);

        cout << "Ganador: ";
        cout << mayor->nombre;
        cout << " con ";
        cout << mayor->puntos;
        cout << " puntos" << endl;
    }

    void ayuda(){
        cout << "1 Inscribir jugador" << endl;
        cout << "2 Mostrar jugadores" << endl;
        cout << "3 Iniciar competencia" << endl;
        cout << "4 Mostrar ganador" << endl;
        cout << "6 Integrantes" << endl;
    }

    void integrantes(){
        cout << "Integrantes del grupo" << endl;
        cout << "Nombre 1 - Carnet" << endl;
        cout << "Nombre 2 - Carnet" << endl;
        cout << "Nombre 3 - Carnet" << endl;
    }
};

int main(){

    ListaCircular lista;
    int op;
    string nombre;
    char id;

    do{
        cout << "Menu" << endl;
        cout << "1 Inscribir jugador" << endl;
        cout << "2 Mostrar jugadores" << endl;
        cout << "3 Iniciar competencia" << endl;
        cout << "4 Mostrar ganador" << endl;
        cout << "5 Ayuda" << endl;
        cout << "6 Integrantes" << endl;
        cout << "0 Salir" << endl;

        cin >> op;

        switch(op){

            case 1:
                cout << "Nombre: ";
                cin >> nombre;
                cout << "Caracter: ";
                cin >> id;
                lista.insertar(nombre,id);
                break;

            case 2:
                lista.mostrar();
                break;

            case 3:
                lista.competencia();
                break;

            case 4:
                lista.ganador();
                break;

            case 5:
                lista.ayuda();
                break;

            case 6:
                lista.integrantes();
                break;

            case 0:
                cout << "Fin" << endl;
                break;

            default:
                cout << "Opcion invalida" << endl;
        }

    }while(op != 0);

    return 0;
}
