// 4. Se dispone de un árbol binario de elementos de tipo entero. Escriba las funciones en
// C ++ que calculen:
// a) La suma de sus elementos.
// b) La suma de sus elementos múltiplos de 3.

// * Respuesta:

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *der;
    Nodo *izq;
};

Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
int suma(Nodo *);
int sumaMultiplo(Nodo *);
void mostrarArbol(Nodo *, int);
Nodo *arbol = NULL;

int main()
{
    int dato, contador = 0;
    char opc;
    do
    {
        cout << "Inserte un numero: ";
        cin >> dato;
        insertarNodo(arbol, dato);
        cout << "\nInsertar otro numero? S/N: ";
        cin >> opc;
        opc = toupper(opc);
        system("cls");
    } while (opc != 'N');
    cout << "\nLa Sumatoria de los Numeros del Arbol es: " << suma(arbol) << endl;
    cout << "\nLa Suma de los Numeros del Arbol, Multiplos de 3, es: 
            "<<sumaMultiplo(arbol)<<endl;
        cout
         << "\nMostrando el ARBOL completo:\n\n";
    mostrarArbol(arbol, contador);
    cout << "\n";
    system("pause");
    return 0;
}

// Función Crear Nodo:
Nodo *crearNodo(int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}

// Función Insertar:
void insertarNodo(Nodo *&arbol, int n)
{
    if (arbol == NULL)
    {
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else
    {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz)
        {
            insertarNodo(arbol->izq, n);
        }
        else
        {
            insertarNodo(arbol->der, n);
        }
    }
}

// Función Requerida de Sumatoria:
int suma(Nodo *arbol)
{
    int sumatoria = 0;
    if (arbol == NULL)
    {
        sumatoria = 0;
    }
    else
    {
        sumatoria = arbol->dato + suma(arbol->der) + suma(arbol->izq);
    }
    return sumatoria;
}

// Función Requerida de Sumatoria de Múltiplos:
int sumaMultiplo(Nodo *arbol)
{
    int sm = 0;
    if (arbol == NULL)
    {
        sm = 0;
    }
    else
    {
        if ((arbol->dato) % 3 == 0)
        {
            sm = arbol->dato + sumaMultiplo(arbol->der) + sumaMultiplo(arbol->izq);
        }
        else
        {
            sm = sumaMultiplo(arbol->der) + sumaMultiplo(arbol->izq);
        }
    }
    return sm;
}

// Función Mostrar de forma Completa:
void mostrarArbol(Nodo *arbol, int cont)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++)
        {
            cout << " ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}
