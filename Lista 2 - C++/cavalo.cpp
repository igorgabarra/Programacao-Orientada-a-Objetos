#include <iostream>
#include <string>
#include "animal.hpp"
#include "cavalo.hpp"

using namespace std;

    Cavalo::Cavalo(string nome, int idade): Animal(nome, idade) {}
    Cavalo::~Cavalo(){}

    void Cavalo::emitirSom(){
        cout << " IH ONNN";
    }

    void Cavalo::correr(){
        cout << " Corre cavalo! ";
    }
