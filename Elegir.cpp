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
