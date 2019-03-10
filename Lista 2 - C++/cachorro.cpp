#include <iostream>
#include <string>
#include "animal.hpp"
#include "cachorro.hpp"

using namespace std;

    Cachorro::Cachorro(string nome, int idade): Animal(nome, idade) {}
    Cachorro::~Cachorro(){}

    void Cachorro::emitirSom() const{
        cout << "Au au";
    }

    void Cachorro::correr() const{
        cout << " Corrennndo ";
    }
