#include <iostream>
#include "animal.hpp"
#include "veterinario.hpp"


using namespace std;

    Veterinario::Veterinario(){}
    Veterinario::~Veterinario(){}

    void Veterinario::examinar(Animal* animal){
        cout << " Examinando animal..." << endl;
        animal->emitirSom();
    }
