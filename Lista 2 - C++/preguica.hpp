#ifndef preguica_hpp
#define preguica_hpp

#include "animal.hpp"
#include <string>

using namespace std;

class Preguica : public Animal{

public:
    Preguica(string = "", int=0);
    ~Preguica();
    void emitirSom();
    void subirArvore();
};

#endif
