/** Sa se descompuna un numar dat in suma de numere
    care fac parte din sirul lui Fibbonacci
    0 1 1 2 3 5 8 13 21 34 55 89

    De exemplu:
    25 = 21 + 3 + 1

    nr = 25, max_fib = 21
    nr = 25 - 21 = 4
    nr = 4, max_fib = 3
    nr = 4 - 3 = 1
    nr = 1, max _fib = 1
    nr = 1 - 1 = 0
    **/

#include <iostream>

using namespace std;

//aflam cel mai mare numar fibbonacci mai mic decat numarul dat
int max_fib(int nr)
{
    int a, b, c;
    a = 0; b = 1;
    while(b <= nr)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int nr, fib;
    cout << "nr = "; cin >> nr;
    cout << "nr = ";
    while(nr > 0)
    {
        fib = max_fib(nr);
        cout << fib << " + ";
        nr -= fib;
    }
    cout << "\b\b\b  ";
}



