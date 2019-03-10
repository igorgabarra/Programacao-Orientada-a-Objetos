#include <iostream>
#include "NumeroRacional.hpp"

using namespace std;

int main(){

    NumeroRacional racional1;
    NumeroRacional racional2(8,10), racional3(3,9);

    cout << " Digite numerador e denominador: ";
    cin >> racional1;
    cout << " Racional digitado: " << racional1 << endl;

    cout << " Soma entre " << racional2 << " e " << racional3 << " eh: " << racional2+racional3 << endl;
    cout << " Subtracao entre " << racional2 << " e " << racional3 << " eh: " << racional2-racional3 << endl;
    cout << " Multiplicacao entre " << racional2 << " e " << racional3 << " eh: " << racional2*racional3 << endl;
    cout << " Divisao entre " << racional2 << " e " << racional3 << " eh: " << racional2/racional3 << endl;

    return 0;
}