//
// Created by igorg on 09/10/2018.
//

#include "livro.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

    Livro::Livro(vector<string> escritores, const string& titulo, vector<string> capitulos, const int& anoPublicacao, const string& idiomaOriginal, vector<string> keywords) {
        setEscritores(escritores);
        setTitulo(titulo);
        setCapitulos(capitulos);
        setAnoPublicacao(anoPublicacao);
        setIdiomaOriginal(idiomaOriginal);
        setKeywords(keywords);
    }

    Livro::~Livro(){}

    vector<string> Livro::getEscritores() const{
        return escritores;
    }

    void Livro::setEscritores(vector<string> escritores) {
        this->escritores.insert(this->escritores.begin(), escritores.begin(), escritores.end());
    }

    string Livro::getTitulo() const {
        return titulo;
    }

    void Livro::setTitulo(const string &titulo) {
        this->titulo = titulo;
    }

    vector<string> Livro::getCapitulos() const{
        return capitulos;
    }

    void Livro::setCapitulos(vector<string> capitulos){
        this->capitulos.insert(this->capitulos.begin(), capitulos.begin(), capitulos.end());
    }

    int Livro::getAnoPublicacao() const{
        return anoPublicacao;
    }

    void Livro::setAnoPublicacao(const int &anoPublicacao) {
        this->anoPublicacao = anoPublicacao;
    }

    string Livro::getIdiomaOriginal() const{
        return idiomaOriginal;
    }

    void Livro::setIdiomaOriginal(const string &idiomaOriginal) {
        this->idiomaOriginal = idiomaOriginal;
    }

    vector<string> Livro::getKeywords() const{
        return keywords;
    }

    void Livro::setKeywords(vector<string> keywords){
        for(unsigned int i=0; i!= keywords.size() ; i++)
            this->keywords.push_back(keywords.at(i));
    }

    ostream& operator<<(ostream& out, Livro& livro){
        unsigned int tam = livro.getTitulo().length();

        if(tam <= 30)
            out << left << setfill(' ') << setw(30) << livro.getTitulo();

        else
            out << livro.getTitulo().substr(0,30);

        out << " | ";

        if(livro.escritores.size() == 0)
            out << setfill(' ') << setw(10) << "Nenhum";

        else {
            tam = livro.escritores[0].length();

            if (tam <= 30)
                out << right << setfill(' ') << setw(30) << livro.escritores[0];

            else
                out << livro.escritores[0].substr(0, 30);
        }

        out << " | ";

        tam = livro.getIdiomaOriginal().length();

        if(tam <= 10)
            out << left << setfill(' ') << setw(10) << livro.getIdiomaOriginal();

        else
            out << livro.getIdiomaOriginal().substr(0,10);

        out << " | ";

        out << right << setfill('0') << setw(3) << livro.capitulos.size() << " | ";

        out << right << setfill('0') << setw(2) << livro.keywords.size() << " | ";

        return out;
    }