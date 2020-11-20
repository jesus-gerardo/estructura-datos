#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char *nombre;
    struct nodo * siguiente;
}Nodo;

// sirve para crear y asignarle memoria al nodo
Nodo* crearNodo(){
    Nodo *NuevoNodo = NULL;
    NuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    NuevoNodo->nombre = NULL;
    NuevoNodo->siguiente = NULL;
    return NuevoNodo;
}

// debido a que lo estoy pasando por referencia, este recibe un doble apuntado para acceder a la direccion de la lista
void NuevoNodo(Nodo **lista, char *nombre){
    Nodo * nuevo = NULL;
    nuevo = crearNodo();
    nuevo->nombre = nombre;
    nuevo->siguiente = NULL;
    // si la lista esta vacia, hago que el nuevo nodo sea el primer valor
    if (*lista == NULL){
        *lista = nuevo; // asigno a lista la referencia a nuevo
    }else{
        // creo una variable auxiliar para de nodo en nodo hasta el ultimo agregado, este apunta a lista es la misma variables
        Nodo * aux = (*lista);
        while(aux->siguiente != NULL){
            aux = aux->siguiente; // paso al siguiente nodo de la lista
        }
        aux->siguiente = nuevo; //agrego el nuevo nodo en el final de la lista
    }
}

int main(){
    Nodo * lista = NULL;
    // lista = crearNodo();
    // le mando por referencia la lista del nodo
    NuevoNodo(&lista, "hola");
    NuevoNodo(&lista, "mundo");
    NuevoNodo(&lista, "en");
    NuevoNodo(&lista, "nodos");

    // verifico que la lista no sea nula, eso aplica para el final de la lista
    while(lista != NULL){
        printf("%s -> ", lista->nombre);
        printf("%p\n", lista->siguiente);
        lista = lista->siguiente; // salto al otro nodo de la lista asignandole la direccion del memoria
    }
    return 0;
}