#ifndef NumeroRacional_hpp
#define NumeroRacional_hpp

class NumeroRacional{

public:
    double numerador, denominador;
    NumeroRacional(double numerador = 1, double denominador = 1);
    ~NumeroRacional();

    NumeroRacional operator+(const NumeroRacional&) const;
    NumeroRacional operator-(const NumeroRacional&) const;
    NumeroRacional operator*(const NumeroRacional&) const;
    NumeroRacional operator/(const NumeroRacional&) const;

    friend std::ostream& operator<<(std::ostream&, const NumeroRacional&);
    friend std::istream& operator>>(std::istream&, NumeroRacional&);
};

#endif
