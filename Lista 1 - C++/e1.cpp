#include <iostream>
#include "data.hpp"

using namespace std;

int main(){
    int dia, mes, ano;
    Data aux;
    cout << " Exercicio 1: " << endl << endl;

    cout << " Dia: ";
    cin >> dia;
    aux.setDia(dia);

    cout << " Mes: ";
    cin >> mes;
    aux.setMes(mes);

    cout << " Ano: ";
    cin >> ano;
    aux.setAno(ano);

    cout << " Data, usando entradas de teclado: ";
    aux.exibeData();

    cout << endl;
    cout << " Data, usando o metodo construtor: ";
    Data constr(5, 10, 12);
    constr.exibeData();

    return 0;
}
