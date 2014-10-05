/*****************************************************************
1. Calculati media aritmetica a elementelor unei matrici
A de dimensiune m x n
2. Construiti un vector cu elementele strict pozitive
ale matricii
3. Construiti de la dreapta spre stanga si de jos in sus
o matrice cu m*n elemente impare
4. Sortati crescator liniile unei matrici date de la tastatura
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include "iomatrix.h"

float medieAritmetica(int a[][dmax], int m, int n)
{
    float ma;
    int s = 0, i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            s += a[i][j];
    ma = (float)s / (m * n);
    return ma;
}

int construiesteVectorPozitive(int a[][dmax], int m, int n, int v[])
{
    int k = 0, i ,j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
                if(a[i][j] > 0)
                {
                    v[k] = a[i][j];
                    k++;
                }   v[k] = a[i][j];

    return k;
}

void construiesteMatrice(int a[][dmax], int m, int n)
{
    int i, j, k = 1;
    for(i = m - 1; i >= 0; i--)
        for(j = n - 1; j >= 0; j--)
        {
            a[i][j] = k;
            k +=2;
        }
}

void interschimbare(int v[], int n)
{
    int i, j, aux;
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
           if (v[i] > v[j])
           {
              aux = v[i];
              v[i] = v[j];
              v[j] = aux;
           }
}
void sortareLiniiMatrice(int a[][dmax], int m, int n)
{
    int i;
    for(i = 0; i < m; i++)
        interschimbare(a[i], n);
}

int main()
{
    int a[dmax][dmax], b[dmax][dmax], m, n, k, v[dmax];
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    citireMatrice(a, m, n);
    afisareMatrice(a, m, n);

    //1
    cout << "\nMedia aritmetica a elementelor = " << medieAritmetica(a, m, n);
    k = construiesteVectorPozitive(a, m, n, v);

    //2
    cout << "\nElementele pozitive : ";
    afisareVector(v, k);

    //3
   construiesteMatrice(b, m, n);
   cout << "\nMatricea construita cu elemente impare: \n";
   afisareMatrice(b, m, n);

   //4
   sortareLiniiMatrice (a, m, n);
   cout << "\nMatricea A, cu liniile sortate:\n";
   afisareMatrice(a, m, n);

   return 0;
}


