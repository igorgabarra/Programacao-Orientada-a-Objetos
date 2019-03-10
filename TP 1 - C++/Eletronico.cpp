#include "livro.h"
#include "Eletronico.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


    Eletronico::Eletronico(vector<string> escritores, const string& titulo, vector<string> capitulos, const int& anoPublicacao, const string& idiomaOriginal, vector<string> keywords, const string& x, const string& y): Livro(escritores, titulo, capitulos, anoPublicacao, idiomaOriginal, keywords), url(x), formatoArquivo(y) {}
    Eletronico::~Eletronico() {}

    string Eletronico::getUrl() const{
        return url;
    }

    void Eletronico::setUrl(const string &url) {
        this->url = url;
    }

    string Eletronico::getFormatoArquivo() const{
        return formatoArquivo;
    }

    void Eletronico::setFormatoArquivo(const string &formato) {
        this->formatoArquivo = formato;
    }

    ostream& operator<<(ostream& output, Eletronico& eletronico){
        Livro& livro = dynamic_cast<Livro&>(eletronico);

        output << livro;

        unsigned int x = eletronico.getFormatoArquivo().length();

        if(x <= 10)
            output << setfill(' ') << setw(10) << eletronico.getFormatoArquivo();

        else
            output << eletronico.getFormatoArquivo().substr(0, 10);

        output << " | ";

    return output;
    }

