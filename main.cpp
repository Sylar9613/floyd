#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nodes;//Cantidad de vertices del grafo
//Este algoritmo sirve para n<=100

int const constanteMax=100;
//Es igual a la distancia mayor posible de un vertice hacia otro aumentado en uno
//O sea, es un valor ponderado que jamas tendra, simula el infinito

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>nodes;
    int floyd[nodes][nodes];
    int dist[nodes][nodes];
    //Para almacenar los datos en dist
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            cin>>dist[i][j];
        }
    }
    //Para copiar los datos de dist para floyd
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            floyd[i][j]=dist[i][j];
        }
        floyd[i][i]=0;
    }

    //Algoritmo de Floyd
    for(int k=1;k<=nodes;k++)
    {
        for(int i=1;i<=nodes;i++)
        {
            for(int j=1;j<=nodes;j++)
            {
                if(floyd[i][j]>floyd[i][k]+floyd[k][j])
                {
                    floyd[i][j]=floyd[i][k]+floyd[k][j];
                }
            }
        }
    }







    //Para mostrar el floyd
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            cout<<floyd[i][j]<<"\t";
            //Para verificar si hay camino o no
    if(floyd[i][j]==constanteMax)
    {
        cout<<"No hay camino";
    }
        }
        cout<<"\n";
    }







    return 0;
}
