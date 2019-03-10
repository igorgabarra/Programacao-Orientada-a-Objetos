#ifndef livro_hpp
#define livro_hpp

#include <string>
#include <vector>
#include <set>

using namespace std;

class Livro {

protected:
    /* Variaveis private por default */
    vector<string> escritores;      //colecao de escritores
    string titulo;
    vector<string> capitulos;       //colecao de capitulos
    int anoPublicacao;
    string idiomaOriginal;
    vector<string> keywords;        //colecao de keywords

public:
    /* Metodos para manipulacao de dados da classe Livro */

    /* Construtor */
    Livro(vector<string>, const string&, vector<string>, const int&, const string&, vector<string>);

    /* Destrutor */
    virtual ~Livro();

    /* Getters e Setter de dados */

    vector<string> getEscritores() const;
    void setEscritores(vector<string>);

    string getTitulo() const;
    void setTitulo(const string&);

    vector<string> getCapitulos() const;
    void setCapitulos(vector<string>);

    int getAnoPublicacao() const;
    void setAnoPublicacao(const int&);

    string getIdiomaOriginal() const;
    void setIdiomaOriginal(const string&);

    vector<string> getKeywords() const;
    void setKeywords(vector<string>);

    /* Sobrecarga de operadores de entrada e saida */

    friend ostream& operator<< (ostream&, Livro&);
};

#endif /* Fim do cabecalho da classe */