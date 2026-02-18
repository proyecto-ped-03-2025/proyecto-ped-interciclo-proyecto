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
