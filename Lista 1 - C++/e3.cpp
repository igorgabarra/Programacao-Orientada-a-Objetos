#include <iostream>
#include "relogio.hpp"

using namespace std;

int main(){
    int hora, minuto, segundo;

    cout << " Exercicio 3:" << endl << endl;

    do {
        cout << " Hora: ";
        cin >> hora;

        if(hora<0 || hora >24)
            cout << " Hora invalida! Tente novamente." << endl;
    }while(hora<0 || hora >24);

    do{
        cout << " Minuto: ";
        cin >> minuto;
        if(minuto<0 || minuto >59)
            cout << " Minuto invalido! Tente novamente." << endl;
    }while(minuto<0 || minuto >59);

    do {
        cout << " Segundo: ";
        cin >> segundo;

        if(segundo<0 || segundo > 59)
            cout << " Segundo invalido! Tente novamente." << endl;
    }while(segundo<0 || segundo > 59);

    Relogio aux(hora,minuto,segundo);

    cout << " Dados fornecidos pelo teclado: ";
    aux.mostraHora();

    cout << " Aumentando os segundos: ";
    aux.avancaSegundo();
    aux.mostraHora();

    cout << endl;
    cout << " Teste de verificacoes do construtor: " << endl;
    cout << " Antes: ";
    Relogio aux1(23,59,59);
    aux1.mostraHora();

    cout << " Depois: ";
    aux1.avancaSegundo();
    aux1.mostraHora();


    return 0;
}
