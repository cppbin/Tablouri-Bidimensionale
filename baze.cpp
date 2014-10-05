/** Dat fiind un numar in baza 10 sa se transforme in baza data b
    DEC 25 = OCT 31
**/

#include <iostream>
#define dmax 10

using namespace std;

int transforma(int x, int b, int v[])
{
    int i = 0;
    while(x > 0)
    {
        v[i] = x % b;
        x /= b;
        i++;
    }
    return i;
}

void afiseazaVector(int v[], int n)
{
    int i;
    for(i = n-1; i >= 0; i--)
        cout << v[i];
}

int main()
{
    int x, b, v[dmax];
    cout << "x = "; cin >> x;
    cout << "in ce baza transformam? "; cin >> b;
    int n = transforma(x, b, v);
    afiseazaVector(v, n);
}


