#include <iostream>
#include "pessoa.hpp"

using namespace std;

    Pessoa::Pessoa(string nome, string endereco, string telefone): nome(nome), endereco(endereco), telefone(telefone){}

    Pessoa::~Pessoa(){}

    void Pessoa::setNome(string nome){
        this->nome = nome;
    }

    void Pessoa::setEndereco(string endereco){
        this->endereco = endereco;
    }

    void Pessoa::setTelefone(string telefone){
        this->telefone = telefone;
    }

    string Pessoa::getNome(){
        return nome;
    }

    string Pessoa::getEndereco(){
        return endereco;
    }

    string Pessoa::getTelefone(){
        return telefone;
    }

    void Pessoa::exibeDados(){
        cout << " Nome: " << getNome() << endl;
        cout << " Endereco: " << getEndereco() << endl;
        cout << " Telefone: " << getTelefone() << endl;
    }
