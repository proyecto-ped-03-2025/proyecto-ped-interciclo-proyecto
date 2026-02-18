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
