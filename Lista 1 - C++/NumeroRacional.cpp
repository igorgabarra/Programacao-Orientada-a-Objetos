#include <iostream>
#include "NumeroRacional.hpp"

using namespace std;

    NumeroRacional::NumeroRacional(double numerador, double denominador) {
        this->numerador = numerador;

        if(denominador<=0)
            denominador = 1.0;

        this->denominador = denominador;
    }

    NumeroRacional::~NumeroRacional(){}

    NumeroRacional NumeroRacional::operator+(const NumeroRacional& x) const{
        NumeroRacional aux;
        aux.numerador = (this->numerador * x.denominador) + (this->denominador * x.numerador);
        aux.denominador = this->denominador * x.denominador;

        return aux;
    }

    NumeroRacional NumeroRacional::operator-(const NumeroRacional& x) const{
        NumeroRacional aux;
        aux.numerador = (this->numerador * x.denominador) - (this->denominador * x.numerador);
        aux.denominador = this->denominador * x.denominador;

        return aux;
    }

    NumeroRacional NumeroRacional::operator*(const NumeroRacional& x) const{
        NumeroRacional aux;
        aux.numerador = this->numerador * x.numerador;
        aux.denominador = this->denominador * x.denominador;

        return aux;
    }

    NumeroRacional NumeroRacional::operator/(const NumeroRacional& x) const{
        NumeroRacional aux;
        aux.numerador = this->numerador / x.numerador;
        aux.denominador = this->denominador / x.denominador;

        return aux;
    }

    istream& operator>>(istream& entrada, NumeroRacional& x){
        entrada >> x.numerador >> x.denominador;
        return entrada;
    }

    std::ostream& operator<<(std::ostream& saida, const NumeroRacional& aux){
        saida << aux.numerador << "/" << aux.denominador;
        return saida;
    }
