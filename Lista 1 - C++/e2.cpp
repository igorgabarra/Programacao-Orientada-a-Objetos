#include <iostream>
#include "pessoa.hpp"
#include <string>

using namespace std;

int main(){
    string nome, endereco, telefone;
    Pessoa aux("","","");

    cout << " Exercicio 2:" << endl << endl;

    cout << " Nome: ";
    getline(cin, nome);

    cout << " Endereco: ";
    getline(cin, endereco);

    cout << " Telefone: ";
    getline(cin, telefone);

    aux.setNome(nome);
    aux.setEndereco(endereco);
    aux.setTelefone(telefone);

    cout << endl;
    cout << " Dados fornecidos pelo teclado: " << endl;
    aux.exibeDados();

    Pessoa aux2("Jose", "Rua H", "33333333");
    cout << endl;
    cout << " Dados inseridos utilizando o construtor: " << endl;
    aux2.exibeDados();

    return 0;
}
