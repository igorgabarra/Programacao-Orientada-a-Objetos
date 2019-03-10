#include <iostream>
#include "relogio.hpp"

using namespace std;

    Relogio::Relogio(int hora, int minuto, int segundo): hora(hora), minuto(minuto), segundo(segundo){}
    Relogio::~Relogio(){}

    void Relogio::setHora(int hora, int minuto, int segundo){
        this->hora = hora;
        this->minuto = minuto;
        this->segundo = segundo;
    }

    void Relogio::getHora(int& hora, int& minuto, int& segundo){
        hora = this->hora;
        minuto = this->minuto;
        segundo = this->segundo;
    }

    void Relogio::avancaSegundo(){
        if(++segundo > 59){
            segundo = 0;
            if(++minuto > 59){
                minuto = 0;
                if(++hora > 23)
                    hora = 0;
            }
        }
    }

    void Relogio::mostraHora() {
        cout << " " << hora << ":" << minuto << ":" << segundo << endl;
    }
