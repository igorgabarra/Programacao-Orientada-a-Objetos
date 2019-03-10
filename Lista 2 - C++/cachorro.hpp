#ifndef cachorro_hpp
#define cachorro_hpp

#include "animal.hpp"
#include <string>

using namespace std;

class Cachorro : public Animal{

public:
    Cachorro(string = "", int=0);
    virtual ~Cachorro();
    void emitirSom();
    void correr();

};

#endif
