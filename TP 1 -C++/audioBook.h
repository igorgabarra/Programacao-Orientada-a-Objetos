//
// Created by igorg on 15/10/2018.
//

#ifndef audioBook_h
#define audioBook_h


#include "livro.h"
#include <string>
#include <vector>

using namespace std;

class AudioBook : public Livro {

    float duracao;
    string formatoAudio;

public:
    AudioBook(vector<string>, const string&, vector<string>, const int&, const string&, vector<string>, const float&, const string&);
    virtual ~AudioBook();

    float getDuracao() const;
    void setDuracao(const float&);
    string getFormatoAudio() const;
    void setFormatoAudio(const string&);

    friend ostream& operator<< (ostream&, AudioBook&);
};


#endif