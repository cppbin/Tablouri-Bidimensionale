/** Calculati produsul a doua matrice **/

#include <iostream>
#include <iomanip>
#define dmax 10
//Ma was here
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
            cout << setw(4) << a[i][j] << "  ";
        cout << endl;
    }
}

void produsMatrici(int a[][dmax], int b[][dmax], int c[][dmax], int m, int n, int p)
{
    int i, j, k;
    for(i = 0; i < m; i++)
        for(j =0; j < p; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int main()
{
    int a[dmax][dmax], b[dmax][dmax], c[dmax][dmax];
    int m, n, p;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    cout << "Introduceti elementele matricii A: \n";
    citireMatrice(a, m, n);
    cout << "p = "; cin >> p;
    cout << "\nIntroduceti elementele matricii B: \n";
    citireMatrice(b, n, p);
    produsMatrici(a,b,c,m,n,p);
    cout << "\nA x B = \n";
    afisareMatrice(c, m, p);
    return 0;
}
