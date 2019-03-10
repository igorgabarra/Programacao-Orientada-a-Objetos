#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "livro.h"
#include "audioBook.h"

using namespace std;

    //olhar quais conteiners valem mais a pena para cada tipo
    AudioBook::AudioBook(vector<string> escritores, const string& titulo, vector<string> capitulos, const int& anoPublicacao, const string& idiomaOriginal, vector<string> keywords, const float& duracao, const string& formatoAudio): Livro(escritores, titulo, capitulos, anoPublicacao, idiomaOriginal, keywords), duracao(duracao), formatoAudio(formatoAudio){}
    AudioBook::~AudioBook(){}

    float AudioBook::getDuracao() const{
        return duracao;
    }

    void AudioBook::setDuracao(const float &duracao) {
        this->duracao = duracao;
    }

    string AudioBook::getFormatoAudio() const{
        return formatoAudio;
    }

    void AudioBook::setFormatoAudio(const string &formato) {
        formatoAudio = formato;
    }

    ostream& operator<<(ostream& output, AudioBook& audioBook){
        Livro& livro = dynamic_cast<Livro&>(audioBook);
        output << livro;

        output << fixed << setfill(' ') << setw(10) << setprecision(2) << audioBook.getDuracao();
        output << " | ";

        return output;
    }
