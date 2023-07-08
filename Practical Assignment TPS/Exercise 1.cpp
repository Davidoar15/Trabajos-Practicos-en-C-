// 1. Se requiere leer la temperatura todos los mediodías en la ciudad de Cabimas, durante
// un mes y luego informar la temperatura promedio mensual, así como el día más caluroso y
// el más frío. Sabiendo que la temperatura mínima de la tierra es de -90° Centígrados y la
// máxima es de 60° Centígrados, se pide:
// Haciendo uso de arreglos, hacer un programa en C++, que:
// a. Calcule el promedio mensual de la temperatura.
// b. La temperatura máxima y mínima registrada.

// * Respuesta:

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    float temps[100], mayor = 0, menor = 1000, sumatoria = 0, Promedio = 0;
    int n;
    cout << "Inserte el numero de dias del Mes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Dia " << i + 1 << ". Inserte la Temperatura, en Grados Centigrados: ";
        cin >> temps[i];
        if (temps[i] > mayor)
        {
            mayor = temps[i];
        }
        if (temps[i] < menor)
        {
            menor = temps[i];
        }
    }
    for (int x = 0; x < n; x++)
    {
        sumatoria += temps[x];
    }
    Promedio = sumatoria / n;
    cout << "\nEl Promedio Mensual de la Temperatura, en Grados Centigrados, es: 
            "<<Promedio<<endl;
        cout
         << "\nLa Maxima Temperatura registrada fue: " << mayor << endl;
    cout << "\nLa Minima Temperatura registrada fue: " << menor << endl;
    cout << "\n";
    system("pause");
    return 0;
}