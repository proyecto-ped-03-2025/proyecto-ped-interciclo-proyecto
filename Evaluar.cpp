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
