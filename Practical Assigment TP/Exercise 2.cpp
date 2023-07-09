// 2. Utilizando el método de ordenamiento por quicksort y dado un vector entero de 30
// elementos, los cuales son introducidos de forma aleatoria, ordenar dichos números enteros
// contenidos en él array.

// * Respuesta:

#include <iostream>
#include <stdlib.h>
using namespace std;

// Prototipos de Funciones:
void quicksort(float[], int, int);
void escribir(float[], int);

int main()
{
    int n;
    cout << "Inserte el numero de elementos que tendra el array/arreglo: ";
    cin >> n;
    float numeros[n];
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". Inserte un numero cualquiera: ";
        cin >> numeros[i];
    }
    cout << "\n";
    cout << "Array Ingresado: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|" << numeros[i] << "| ";
    }
    cout << endl;
    quicksort(numeros, 0, n - 1);
    escribir(numeros, n);
    cout << "\n";
    system("pause");
    return 0;
}

// Función Ordenamiento QuickSort:
void quicksort(float nros[], int first, int last)
{
    int mitad, i, j;
    float pivot;
    mitad = (first + last) / 2;
    pivot = nros[mitad];
    i = first;
    j = last;
    do
    {
        while (nros[i] < pivot)
        {
            i++;
        }
        while (nros[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            float aux;
            aux = nros[i];
            nros[i] = nros[j];
            nros[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (first < j)
    {
        quicksort(nros, first, j);
    }
    if (i < last)
    {
        quicksort(nros, i, last);
    }
}

void escribir(float nros[], int x)
{
    cout << "\nArray Resultante (Ordenado por Metodo QuickSort): " << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "|" << nros[i] << "| ";
    }
    cout << endl;
}
