#ifndef relogio_hpp
#define relogio_hpp

class Relogio{
    int hora, minuto, segundo;

public:
    Relogio(int=0, int=0, int=0);
    ~Relogio();

    void setHora(int, int, int);
    void getHora(int&, int&, int&);
    void avancaSegundo();
    void mostraHora();

};

#endif
