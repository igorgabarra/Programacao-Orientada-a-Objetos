#ifndef pessoa_hpp
#define pessoa_hpp

#include <string>

using namespace std;

class Pessoa{
    string nome, endereco, telefone;

public:
    Pessoa(string = "", string = "", string = "");
    ~Pessoa();
    void setNome(string);
    void setEndereco(string);
    void setTelefone(string);
    string getNome();
    string getEndereco();
    string getTelefone();

    void exibeDados();
};

#endif
