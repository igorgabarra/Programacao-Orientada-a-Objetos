#include <iostream>
#include "data.hpp"

using namespace std;


    Data::Data(int dia, int mes, int ano): dia(dia), mes(mes), ano(ano) {}
    Data::~Data(){}

    void Data::setDia(int dia){
        this->dia = dia;
    }

    void Data::setMes(int mes){
        this->mes = mes;
    }

    void Data::setAno(int ano){
        this->ano = ano;
    }

    int Data::getDia(){
        return dia;
    }

    int Data::getMes(){
        return mes;
    }

    int Data::getAno(){
        return ano;
    }

    void Data::exibeData(){
        cout << dia << "/" << mes << "/" << ano << endl;
    }
