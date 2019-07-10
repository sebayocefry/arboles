#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *crearArbolEnArreglo(nodo *);
int alturaArbol(nodo *);
int max(int,int);
void copiarArbolenArreglo(nodo *,int,char *,int);
void vaciarArreglo(int,char *);
void imprimirArreglo(int,char *);
int muestraArbolEnTerminal(nodo *);

int muestraArbolEnTerminal(nodo *unArbol){
	char *arreglo;
	int h;
	arreglo=crearArbolEnArreglo(unArbol);
	h=alturaArbol(unArbol);
	int tamano;
	tamano=(pow(2,h+2)-1);

	int contador=0,nivelActual=0,nodosEnNivel=0,nodoActual=0;
							//contador es un indice que recorre los nodos actuales de un nivel
							//mientras que niveles es otro indice recorre los niveles que tiene el arbol
							//nodosEnNivel se usa porque no me deja usar el pow en un if
							//nodoActual es un indice que recorre TODOS los nodos actuales

	while(nivelActual<h+2){
			nodosEnNivel=pow(2,nivelActual);
			contador=0;
			while(contador<nodosEnNivel){
				printf("%c",arreglo[nodoActual]);
				contador++;
				nodoActual++;
			}
			printf("\n");
			nivelActual++;
	}


}

void imprimirArreglo(int tamano,char arreglo[tamano]){
	int i=0;
	while(i<31){
		printf("\narreglo[%i]=%c",i,arreglo[i]);
		i++;
		if(i==1 || i==3 || i==7 || i==15 || i==31){
			printf("\n");
		}
	}
}
void vaciarArreglo(int tamano,char arreglo[tamano]){
	int i=0;
	while(i<tamano){
		arreglo[i]='\0';
		i++;
	}
}

void copiarArbolenArreglo(nodo *unArbol,int tamano,char arreglo[tamano],int pos){
	if(unArbol==NULL){
		arreglo[pos]='N';
		return;
	}
	arreglo[pos]=unArbol->valor;
	copiarArbolenArreglo(unArbol->hizq,tamano,arreglo,2*pos+1);
	copiarArbolenArreglo(unArbol->hder,tamano,arreglo,2*pos+2);
}

char *crearArbolEnArreglo(nodo *unArbol){
	int h;
	h=alturaArbol(unArbol);
	int tamano;
	tamano=(pow(2,h+2)-1);		//tamaño maximo de nodo que puede haber en un arbol de altura h
	char *arreglo=malloc(sizeof(char)*tamano);
	vaciarArreglo(tamano,arreglo);
	copiarArbolenArreglo(unArbol,tamano,arreglo,0);

	return arreglo;

}

int alturaArbol(nodo *unArbol){
	if(unArbol==NULL){
		return (-1);
	}
	return (1+max(alturaArbol(unArbol->hizq),alturaArbol(unArbol->hder)));
}

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
