/************************************************************
 Pentru a matrice data de dimensiune m x n cu elemente
 doar cifre binare, afisati liniile complementare
 ************************************************************/

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
            cout << "a["<<i<<"]["<<j<<"]=";
        cout << endl;
    }
}

int verificaLiniiComplementare(int a[][dmax], int m, int n, int line1, int line2)
{
    int j;
    for(j = 0; j < n; j++)
            if(a[line1][j] + a[line2][j] != 1)
                return 0;
    return 1;
}

void afiseazaLiniiComplementare(int a[][dmax], int m, int n)
{
    int i, j, c = 0;
    for(i = 0; i < m; i++)
    {
        for(j = i + 1; j < m; j++)
            if(verificaLiniiComplementare(a,m,n,i,j))
            {
                cout << "\nLiniile " << i << " si " << j << " sunt complementare";
                c = 1;
            }
    }
    if(c == 0) cout << "Nu exista linii complementare";
}

int main()
{
    int a[dmax][dmax], m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    citireMatrice(a, m, n);
    afisareMatrice(a, m, n);
    afiseazaLiniiComplementare(a, m, n);
    return 0;
}
