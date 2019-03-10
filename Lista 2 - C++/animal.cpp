#include <iostream>
#include "animal.hpp"
#include <string>

using namespace std;

    Animal::Animal(string nome, int idade): nome(nome), idade(idade) {}

    Animal::~Animal(){}

    void Animal::setNome(string nome){
        this->nome = nome;
    }

    void Animal::setIdade(int idade){
        this->idade = idade;
    }

    string Animal::getNome(){
        return nome;
    }

    int Animal::getIdade(){
        return idade;
    }

    void Animal::emitirSom(){
//        cout << " Animal emite som";
    }
