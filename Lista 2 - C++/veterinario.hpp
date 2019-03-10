#ifndef veterinario_hpp
#define veterinario_hpp

#include "animal.hpp"

class Veterinario{

public:
    Veterinario();
    virtual ~Veterinario();

    void examinar(Animal*);
};


#endif
