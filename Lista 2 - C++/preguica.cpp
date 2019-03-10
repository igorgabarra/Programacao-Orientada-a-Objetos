#include <iostream>
#include <string>
#include "animal.hpp"
#include "preguica.hpp"

using namespace std;

    Preguica::Preguica(string nome, int idade): Animal(nome, idade) {}
    Preguica::~Preguica(){}

    void Preguica::emitirSom(){
        cout << "Espreguicando";
    }

    void Preguica::subirArvore(){
        cout << " Subindo árvore ";
    }
