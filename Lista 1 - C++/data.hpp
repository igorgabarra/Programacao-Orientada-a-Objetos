#ifndef data_hpp
#define data_hpp

class Data{
    int dia, mes, ano;

public:
    Data(int dia=0, int mes=0, int ano=0);
    ~Data();
    void setDia(int);
    void setMes(int);
    void setAno(int);
    int getDia();
    int getMes();
    int getAno();

    void exibeData();
};

#endif
