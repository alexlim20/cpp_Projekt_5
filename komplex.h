#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <fstream>
#include <iostream>
#include "string.h"
class Komplex
{
private:
    double Real;
    double Imag;
public:
    Komplex(bool grad, double Abs=1.0, double Arg=0.0);
    Komplex(double real = 1.0, double imag = 0.0);
    double getRe() const;
    double getIm() const;
    void setRe(double r);
    void setIm(double i);
    double getAbs();
    double getArg(bool grad=0) const;
    void print(std::ostream& out);
    void print(std::ostream& out, bool grad);
    friend std::ostream& operator<<(std::ostream& out, Komplex kom);
    Komplex operator-()const;
    Komplex operator~()const;
    Komplex operator*(double& rhs) const;
    Komplex operator*(const Komplex& rhs) const;
    bool operator<(const Komplex& rhs)const;\
    Komplex& operator++();
    Komplex operator++(int dummy);
};

Komplex& operator*=(Komplex& z1, const Komplex z2);
Komplex operator*(const double& lhs, const Komplex& kom);
Komplex sqrt(Komplex z);
Komplex pow(Komplex z, int i);
#endif // KOMPLEX_H
