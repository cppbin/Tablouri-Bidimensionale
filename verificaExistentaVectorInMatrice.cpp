/****************************************************************
    Data fiind o matrice de dimensiune m x n cu
    elemente numere intregi si un vector
    de numere intregi, verificati daca elementele
    vectorului se suprapun peste vreo linie a matricii.
    Afisati indicii liniilor care contin vectorul, respectiv
    un mesaj "NU EXISTA" daca elementele vectorului nu se
    suprapun peste nicio linie a matricii.
******************************************************************/

#include <iostream>
#define dmax 10

using namespace std;

void citireMatrice(int a[][dmax], int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            cout << "a["<<i<<"]["<<j<<"]=";
            cin >> a[i][j];
        }
}

void afisareMatrice(int a[][dmax], int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void citireVector(int v[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cin >> v[i];
}

int verificaVectorInMatrice(int a[][dmax], int m, int n, int v[], int line)
{
    int i;
    for(i = 0; i < n; i++)
        if(v[i] != a[line][i])
            return 0;
    return 1;
}

void afiseazaLinii(int a[][dmax], int m, int n, int v[])
{
    int i, c = 0;
    for(i = 0; i < m; i++)
        if(verificaVectorInMatrice(a,m,n,v,i))
        {
            cout << "\nLinia: " << i;
            c = 1;
        }
    if(c == 0) cout << "\nVectorul nu se suprapune peste nicio linie a matricii";
}

int main()
{
    int a[dmax][dmax], m, n, v[dmax];
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    citireMatrice(a, m, n);
    afisareMatrice(a, m, n);
    citireVector(v,n);
    afiseazaLinii(a,m,n,v);
    return 0;
}

