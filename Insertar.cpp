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
