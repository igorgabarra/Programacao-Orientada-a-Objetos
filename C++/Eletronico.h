#ifndef eletronico_h
#define eletronico_h

#include "livro.h"
#include <vector>
#include <string>

using namespace std;

class Eletronico : public Livro{

    string url;
    string formatoArquivo;

public:
    Eletronico(vector<string>, const string&, vector<string>, const int&, const string&, vector<string>, const string&, const string&);
    virtual ~Eletronico();

    string getUrl() const;
    void setUrl(const string&);
    string getFormatoArquivo() const;
    void setFormatoArquivo(const string&);

    friend ostream& operator<< (ostream&, Eletronico&);
};


#endif