#ifndef cavalo_hpp
#define cavalo_hpp

#include "animal.hpp"
#include <string>

using namespace std;

class Cavalo : public Animal{

public:
    Cavalo(string = "", int=0);
    ~Cavalo();
    void emitirSom();
    void correr();
};

#endif
