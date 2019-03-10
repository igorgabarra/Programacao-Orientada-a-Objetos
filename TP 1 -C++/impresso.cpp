//
// Created by igorg on 15/10/2018.
//

#include "impresso.h"
#include "livro.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

    Impresso::Impresso(vector<string> escritores, const string& titulo, vector<string> capitulos, const int& anoPublicacao, const string& idiomaOriginal, vector<string> keywords, vector<string> livrarias, const int& colunas): Livro(escritores, titulo, capitulos, anoPublicacao, idiomaOriginal, keywords) {
        this->colunas = colunas;
        setLivrarias(livrarias);
    }

    Impresso::~Impresso(){} //= default;

    vector<string> Impresso::getLivrarias() const{
        return livrarias;
    }

    void Impresso::setLivrarias(vector<string> livrarias){
        this->livrarias.insert(this->livrarias.begin(), livrarias.begin(), livrarias.end());
    }

    int Impresso::getColunas() const{
        return colunas;
    }

    void Impresso::setColunas(const int &colunas){
        this->colunas = colunas;
    }

    ostream& operator<<(ostream& output, Impresso& impresso) {
        Livro& livro = dynamic_cast<Livro&>(impresso);
        output << livro;

        unsigned int tam = impresso.getLivrarias().size();

        if(tam == 0)
            output << "Nenhuma | ";

        else if(tam <= 10)
            output << setfill(' ') << setw(10) << impresso.getLivrarias().at(0) << " | ";

        else
            output << impresso.getLivrarias().at(0).substr(0, 10) << " | ";


        return output;
    }