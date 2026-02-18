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

            cout << i->nombre << " elija" << endl;
            int r1 = jugar();

            cout << j->nombre << " elija" << endl;
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
