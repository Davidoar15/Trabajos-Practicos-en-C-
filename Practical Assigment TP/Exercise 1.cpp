// 1. El Grafo que se presenta representa las conexiones de gas existentes
// entre algunos de los diferentes almacenes de la empresa SUPRAGAS. Sobre cada arco,
// se indica la capacidad máxima de transporte de GAS (en m³/horas) de las tuberías que
// conectan los almacenes.

/*
      ->[A]---->[D]---
     /           ^    \
    /           /      \(3)
(5)/        (1)/        \
  /  (3)      /          >
[I]------>[B]           [F]
  \           \          ^
(1)\        (3)\        /
    \           \      /(8)
     \     (3)   >    /
      ->[C]------->[E]

*/

// Se Pide:
// Utilizando el Algoritmo de Ford – Fulkerson

//  - Elabore un programa en C++ que calcule la máxima cantidad de gas que puede
// almacenarse en el Colector F.
//  - Determinar qué flujo debe circular por cada una de las tuberías para obtener el flujo
// máximo.

// * Respuesta:

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <stdlib.h>
using namespace std;

// Se definen el Número de Vértices (Almacenes) del grafo
#define V 7
bool bfs(int grafoRes[V][V], int i, int f, int cont[])
{
    bool visitado[V];
    memset(visitado, 0, sizeof(visitado));
    queue<int> q;
    q.push(i);
    visitado[i] = true;
    cont[i] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (visitado[v] == false && grafoRes[u][v] > 0)
            {
                q.push(v);
                cont[v] = u;
                visitado[v] = true;
            }
        }
    }
    return (visitado[f] == true);
}

/* Función del Algoritmo Ford – Fulkerson: Retorna el flujo máximo desde i (inicio) hasta f
(final) en el grafo dado */
int fordFulkerson(int grafo[V][V], int i, int f)
{
    int u, v;
    int grafoRes[V][V];
    for (u = 0; u < V; u++)
    {
        for (v = 0; v < V; v++)
        {
            grafoRes[u][v] = grafo[u][v];
        }
    }
    int cont[V];
    int flujoMax = 0;
    while (bfs(grafoRes, i, f, cont))
    {
        int rutaFlujo = INT_MAX;
        for (v = f; v != i; v = cont[v])
        {
            u = cont[v];
            rutaFlujo = min(rutaFlujo, grafoRes[u][v]);
        }
        for (v = f; v != i; v = cont[v])
        {
            u = cont[v];
            grafoRes[u][v] -= rutaFlujo;
            grafoRes[v][u] += rutaFlujo;
        }
        flujoMax += rutaFlujo;
    }
    return flujoMax;
}

int main()
{
    // Se insertan los datos correspondientes del grafo
    int grafo[V][V] = {
        {0, 5, 3, 1, 0, 0, 0}, // Almacén I para Almacenes: A, B y C. (INICIO)
        {0, 0, 0, 0, 3, 0, 0}, // Almacén A para Almacén D.
        {0, 0, 0, 0, 1, 3, 0}, // Almacén B para Almacenes: D y E.
        {0, 0, 0, 0, 0, 3, 0}, // Almacén C para Almacén E.
        {0, 0, 0, 0, 0, 0, 3}, // Almacén D para Almacén F.
        {0, 0, 0, 0, 0, 0, 8}, // Almacén E para Almacén F
        {0, 0, 0, 0, 0, 0, 0}  // Almacén F. (FINAL)
    };
    /*
        Como si fuera una matriz, cada Columna representa la capacidad de transporte que tiene
        cada vértice a otro; y cada Fila representa al vértice o almacén correspondiente. Ejemplo:
        {0, 5, 3, 1, 0, 0, 0} es el almacén I (inicio), que tiene tuberías de: capacidad 5 m³/horas hacia
        almacén A, capacidad 3 m³/horas hacia almacén B y capacidad 1 m³/horas hacia almacén
        C. Obviamente, tiene capacidad 0 para sí mismo y para los almacenes D, E y F, ya que no
        existen tuberías entre ellos.
        {0, 0, 0, 0, 3, 0, 0} A: tubería de capacidad 3 m³/horas hacia D.
        {0, 0, 0, 0, 1, 3, 0} B: tuberías de: capacidad 1 m³/horas hacia D y capacidad 3 m³/horas hacia E.
        {0, 0, 0, 0, 0, 3, 0} C: tubería de capacidad 3 m³/horas hacia E.
        {0, 0, 0, 0, 0, 0, 3} D: tubería de capacidad 3 m³/horas hacia F (final).
        {0, 0, 0, 0, 0, 0, 8} E: tubería de capacidad 8 m³/horas hacia F (final).
    */
    cout << "La Maxima Cantidad de gas en F es: " << fordFulkerson(grafo, 0, 6) << "\n";
    cout << "\n";
    system("pause");
    return 0;
}
