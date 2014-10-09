/************************************************************************
   Sa se construiasca cate un vector pentru fiecare zona a unei matrici
   patrate de ordinul n

   De exemplu, daca n = 5

   00 01 02 03 04
   10 11 12 13 14
   20 21 22 23 24
   30 31 32 33 34
   40 41 42 43 44

   N:  i < j && i + j <= n-2
   V:  i > j && i + j <= n-2
   S:  i > j && i + j >= n
   E:  i < j && i + j >= n
*************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

#define dmax 10

using namespace std;

void citire(int a[][dmax], int &n)
{
    int i, j;
    ifstream f("matrice.txt");
    f >> n;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            f >> a[i][j];
}

void afisareMatricePatrata(int a[][dmax], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cout << setw(4) << a[i][j] << "  ";
        cout << endl;
    }
}

void construiesteNVSE(int a[][dmax], int n, int N[], int V[], int S[], int E[], int &k)
{
    int i, j, k1 = 0, k2 = 0, k3 = 0;
    k = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            if(i < j && i + j <= n-2)
            {
                N[k] = a[i][j];
                k++;
            }
            if(i > j && i + j <= n-2)
            {
                V[k1] = a[i][j];
                k1++;
            }
            if(i > j && i + j >= n)
            {
                S[k2] = a[i][j];
                k2++;
            }
            if(i < j && i + j >= n)
            {
                E[k3] = a[i][j];
                k3++;
            }
        }
}

void afisareVector(int v[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cout << v[i] << "  ";
}

int main()
{
    int a[dmax][dmax], n, N[dmax*dmax], V[dmax*dmax], S[dmax*dmax], E[dmax*dmax], k;
    citire(a, n);
    afisareMatricePatrata(a, n);
    construiesteNVSE(a, n, N, V, S, E, k);
    cout << endl << "NORD: "; afisareVector(N, k);
    cout << endl << "VEST: "; afisareVector(V, k);
    cout << endl << "SUD: "; afisareVector(S, k);
    cout << endl << "EST: "; afisareVector(E, k);
    return 0;
}
