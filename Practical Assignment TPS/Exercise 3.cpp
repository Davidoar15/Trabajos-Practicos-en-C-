// 3. Escribir una función Reemplazar en C++ que tenga como argumentos una pila con tipos
// de elementos int y dos valores int: Nuevo y Viejo; de forma que, si el segundo valor aparece
// en el lugar de la pila, sea reemplazado por el primero.

// * Respuesta:

#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo
{
    int dato;
    struct nodo *siguiente;
};
typedef nodo *Pila;

// Prototipos de Funciones:
void menu();
void push(Pila &, int);
void mostrarPila(Pila);
bool vacia(Pila);
void reemplazar(Pila &, int, int);
Pila p = NULL;

int main()
{
    int dato, datoNew, datoOld;
    menu();
    cout <<”\n”;
    system(“pause”);
    return 0;
}

// Función Menú:
void menu()
{
    int dato, datoNew, datoOld, opc;

    do
    {
        cout << "\t.:MENU:.\n";
        cout << "1. Apilar Numero a la PILA\n";
        cout << "2. Mostrar los Numeros de la PILA\n";
        cout << "3. Reemplazar Numero en PILA\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Inserte un numero para Apilar: ";
            cin >> dato;
            push(p, dato);
            cout << "\nNumero " << dato << " apilado...";
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "\nElementos en Pila: " << endl;
            if (p != NULL)
            {
                mostrarPila(p);
            }
            else
            {
                cout << "\nPila vacia..." << endl;
            }
            cout << "\n";
            system("pause");
            break;
        case 3:
            if (!vacia(p))
            {
                cout << "\nInserte el Numero que desea Reemplazar: ";
                cin >> datoOld;
                cout << "\nAhora, inserte el Nuevo Numero: ";
                cin >> datoNew;
                reemplazar(p, datoNew, datoOld);
            }
            else
            {
                cout << "\nPila vacia..." << endl;
            }
            cout << "\nReemplazo logrado";
            cout << "\n";
            system("pause");
            break;
        }
        system(“cls”);
    } while (opc != 4);
}

// Función Push, para Apilar:
void push(Pila &p, int valor)
{
    Pila aux;
    aux = new (struct nodo);
    aux->dato = valor;
    aux->siguiente = p;
    p = aux;
}

// Función Mostrar Pila:
void mostrarPila(Pila p)
{
    Pila aux;
    aux = p;
    while (aux != NULL)
    {
        cout << "\n"
             << aux->dato << endl;
        aux = aux->siguiente;
    }
}

// Función para Comprobar el Estado de la Pila (Vacía o no):
bool vacia(Pila p)
{
    return (p == NULL ? true : false);
}

// Función Requerida para Reemplazar los Número de la Pila:
void reemplazar(Pila &p, int nuevo, int viejo)
{
    Pila aux = new nodo();
    aux = NULL;
    if (p == NULL)
    {
        cout << "La PILA esta vacia\n";
    }
    else
    {
        while (p != NULL)
        {
            if (p->dato != viejo)
            {
                push(aux, p->dato);
            }
            else
            {
                p->dato = nuevo;
                break;
            }
            p = p->siguiente;
        }
        while (aux != NULL)
        {
            push(p, aux->dato);
            aux = aux->siguiente;
        }
    }
}
