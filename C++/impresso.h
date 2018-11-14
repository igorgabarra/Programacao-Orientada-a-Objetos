#ifndef impresso_h
#define impresso_h

#include "livro.h"
#include <vector>
#include <string>

using namespace std;

class Impresso : public Livro{

    int colunas;
    vector<string> livrarias;

public:
    Impresso(vector<string>, const string&, vector<string>, const int&, const string&, vector<string>, vector<string>, const int&);
    virtual ~Impresso();

    vector<string> getLivrarias() const;
    void setLivrarias(vector<string>);

    int getColunas() const;
    void setColunas(const int&);

    //friend ostream& operator>> (ostream&, const Impresso&);

    friend ostream& operator<< (ostream&, Impresso&);
};


#endif