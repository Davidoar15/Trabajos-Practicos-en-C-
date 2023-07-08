// 2. Implemente una función C++ que recibe una lista de enteros L y un número entero n de
// forma que modifique la lista mediante el borrado de todos los elementos de la lista que
// tengan este valor.

// * Respuesta:

#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

// Estructura de Lista
struct Nodo
{
    int dato;
    Nodo *siguiente;
};

// Prototipos de Funciones:
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
Nodo *eliminarElemento(Nodo *&, int);
Nodo *Lista = NULL;

int main()
{
    int dato;
    menu();
    cout << "\n";
    system("pause");
    return 0;
}

// Función Menú para Lista:
void menu()
{
    int opcion, dato;
    do
    {
        cout << "\t.:MENU:.\n";
        cout << "1. Insertar elemento a la LISTA\n";
        cout << "2. Mostrar los elementos de la LISTA\n";
        cout << "3. Eliminar un nodo de la LISTA\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Inserte un numero: ";
            cin >> dato;
            insertarLista(Lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 2:
            mostrarLista(Lista);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "\nInserte el elemento a eliminar: ";
            cin >> dato;
            eliminarElemento(Lista, dato);
            cout << "\n";
            system("pause");
            break;
        }
        system(“cls”);
    } while (opcion != 4);
}

// Función Insertar:
void insertarLista(Nodo *&Lista, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo *aux1 = Lista;
    Nodo *aux2;
    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (Lista == aux1)
    {
        Lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
    cout << "\tElemento " << n << " insertado a LISTA correctamente\n";
}

// Función Mostrar Lista:
void mostrarLista(Nodo *Lista)
{
    Nodo *actual = new Nodo();
    actual = Lista;
    while (actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
}

// Función Requerida para Eliminar:
Nodo *eliminarElemento(Nodo *&Lista, int n)
{
    Nodo *aEliminar;
    Nodo *aux = Lista;
    while (aux != NULL)
    {
        if (Lista->dato == n)
        {
            aEliminar = Lista;
            Lista = Lista->siguiente;
            aux = aux->siguiente;
            delete aEliminar;
        }
        else
        {
            if ((aux->siguiente != NULL) && (aux->siguiente->dato == n))
            {
                aEliminar = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete aEliminar;
            }
            else
            {
                aux = aux->siguiente;
            }
        }
    }
    return Lista;
}