#include <iostream>
#include <string>
#include <vector>

#include "animal.hpp"
#include "cachorro.hpp"
#include "cavalo.hpp"
#include "preguica.hpp"
#include "veterinario.hpp"

using namespace std;

int main(){

    Animal* p[3] = {
        new Cachorro(),
        new Cavalo(),
        new Preguica()
    };
    Veterinario a;

    cout << "Exercícios 1 e 2:" << endl;

    for(int i=0; i<3; i++)
        p[i]->emitirSom();

    cout << "Exercício 3:" << endl;

    for(int i=0; i<3; i++)
                a.examinar(p[i]);

    for(int i=0; i<3; i++)
        delete p[i];


    cout << "Exercício 4:" << endl;

    for(int i=0; i<10; i++){
        if(i%3==0)
            animal.push_back(new Cachorro());
        else if(i%3==1)
            animal.push_back(new Cavalo());
        else if(i%3==2)
            animal.push_back(new Preguica());
    }


    for (auto elem : vec){ 
        cout << elem->emitirSom(); 
    } 


    return 0;

}
