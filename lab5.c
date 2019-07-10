#include "labo 4.h"
#include "labo 5.h"
int main(){
    int h;
    FILE *p;
    p=fopen("string.txt","r");
    nodo *unArbol;
    unArbol=malloc(sizeof(struct struct_arbol));
    unArbol=creaArbol(p);
    fclose(p);
    char *arreglo;
    arreglo=crearArbolEnArreglo(unArbol);

    h=alturaArbol(unArbol);
    int tamano;
    tamano=(pow(2,h+2)-1);
    imprimirArreglo(tamano,arreglo);

    muestraArbolEnTerminal(unArbol);


}
