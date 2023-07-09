// 3. Realice un Programa en C++ que implemente la búsqueda binaria de un elemento
// determinado dentro de un array (ordenado en formato descendente) de N elementos.

// * Respuesta:

#include <iostream>
#include <stdlib.h>
using namespace std;

// Prototipos de Funciones:
void quicksort(float[], int, int);
void escribir(float[], int);
void busBinaria(float[], int, int);

int main()
{
    int n;
    cout << "Inserte el numero de elementos que tendra el array/arreglo: ";
    cin >> n;
    float Elementos[n];
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". Inserte un numero cualquiera: ";
        cin >> Elementos[i];
    }
    cout << "\n";
    quicksort(Elementos, 0, n - 1);
    busBinaria(Elementos, 0, n - 1);
    escribir(Elementos, n);
    cout << "\n";
    cout << "Gracias. Feliz dia." << endl;
    cout << "\n";
    system("pause");
    return 0;
}

// Función Ordenamiento QuickSort Inverso:
void quicksort(float elementos[], int first, int last)
{
    int mitad, i, j;
    float pivot;
    mitad = (first + last) / 2;
    pivot = elementos[mitad];
    i = first;
    j = last;
    do
    {
        while (elementos[i] > pivot)
        {
            i++;
        }
        while (elementos[j] < pivot)
        {
            j--;
        }
        if (i <= j)
        {
            float aux;
            aux = elementos[i];
            elementos[i] = elementos[j];
            elementos[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (first < j)
    {
        quicksort(elementos, first, j);
    }
    if (i < last)
    {
        quicksort(elementos, i, last);
    }
}

void escribir(float elementos[], int x)
{
    cout << "\nArray Ordenado (de forma Descendente): " << endl;
    cout << "\n";
    for (int i = 0; i < x; i++)
    {
        cout << "|" << elementos[i] << "| ";
    }
    cout << endl;
}

// Función de Búsqueda Binaria:
void busBinaria(float elementos[], int first, int last)
{
    int a = 0, z = 0, mitad, dato;
    char BOOL = 'F';
    a = first;
    z = last + 1;
    cout << "\nInserte el elemento que desea buscar: ";
    cin >> dato;
    while (a <= z)
    {
        mitad = (a + z) / 2;
        if (elementos[mitad] == dato)
        {
            BOOL = 'V';
            break;
        }
        if (elementos[mitad] < dato)
        {
            z = mitad - 1;
            mitad = (a + z) / 2;
        }
        if (elementos[mitad] > dato)
        {
            a = mitad + 1;
            mitad = (a + z) / 2;
        }
    }
    if (BOOL == 'V')
    {
        cout << "\nEl elemento " << dato << " ha sido encontrado en la posicion: " << mitad + 1 << endl;
    }
    else
    {
        cout << "\n";
        cout << "\nEl elemento ingresado NO ha sido encontrado" << endl;
    }
    system("pause");
}