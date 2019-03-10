#ifndef animal_hpp
#define animal_hpp

#include <string>
#include <vector>


using namespace std;

class Animal{
    string nome;
    int idade;

public:
    Animal(string = "", int = 0);
    virtual ~Animal();

    vector<Animal*> animal;

    void setNome(string);
    void setIdade(int);
    string getNome();
    int getIdade();

    virtual void emitirSom() =0;

};

#endif
