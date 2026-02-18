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
