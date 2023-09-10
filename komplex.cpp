#include "komplex.h"
#include <cmath>
#define M_PI 3.14159265358979323846
Komplex::Komplex(double real /*=1.0*/, double imag /*=0.0*/):Real(real), Imag(imag){}

Komplex::Komplex(bool grad, double Abs, double Arg)
{
    if(grad==0)
    {

        Real = Abs* cos(Arg);
        Imag = Abs* sin(Arg);
    }else
    {

        Arg = Arg*(M_PI/180);
        Real = Abs* cos(Arg);
        Imag = Abs* sin(Arg);
    }
}

void Komplex::print(std::ostream& out)
{
    out << "(" << std::noshowpos << Real << std::showpos << Imag << "j" << ")" << '\n';
}

double Komplex::getRe() const
{
    return Real;
}

double Komplex::getIm() const
{
    return Imag;
}

double Komplex::getAbs()
{
    return sqrt((getRe()*getRe()) + (getIm()*getIm()));
}

double Komplex::getArg(bool grad) const
{
    double temp = atan2(getIm(),getRe());
    if(grad==1)
    {
        return temp*(180/M_PI);
    }else
    {
        return temp;
    }
}

void Komplex::print(std::ostream& out, bool grad)
{
    out << "(" << std::noshowpos << getAbs() << ", " << getArg(grad) << ")";
}

std::ostream& operator<<(std::ostream& out, Komplex kom)
{
    out << "(" << std::noshowpos << kom.getRe() << std::showpos << kom.getIm() << "j)" ;
    return out;
}

Komplex Komplex::operator-() const
{
    Komplex k;
    k.Real = -(this->Real);
    k.Imag = -(this->Imag);
    return k;
}

Komplex Komplex::operator~() const
{
    Komplex k;
    k.Real = this->Real;
    k.Imag = -(this->Imag);
    return k;
}

Komplex Komplex::operator*(const Komplex& rhs) const
{
    Komplex k;
    k.Real = (Real*rhs.Real) - (Imag*rhs.Imag);
    k.Imag = (Real*rhs.Imag) + (Imag*rhs.Real);
    return k;
}

Komplex Komplex::operator*(double& rhs) const
{
    Komplex k;
    k.Real = rhs*this->Real;
    k.Imag = rhs*this->Imag;
    return k;
}

void Komplex::setRe(double r)
{
    Real = r;
}

void Komplex::setIm(double i)
{
    Imag = i;
}

Komplex operator*(const double& lhs, const Komplex& kom)
{
    Komplex k;
    k.setRe(lhs*kom.getRe());
    k.setIm(lhs*kom.getIm());
    return k;
}

Komplex& operator*=(Komplex& z1, Komplex z2)
{
    z1 = z1*z2;
    return z1;
}

bool Komplex::operator<(const Komplex& rhs) const
{
    if(Real<rhs.getRe() && Imag<rhs.getIm())
    {
        return true;
    }else
    {
        return false;
    }
}

Komplex& Komplex::operator++()
{
    Komplex k = Komplex(getRe(), getIm());
    setRe(getRe()+1);
    return *this;
}

Komplex Komplex::operator++(int dummy)
{
    Komplex k = Komplex(getRe(), getIm());
    setRe(getRe()+1);
    return k;
}

Komplex sqrt(Komplex z)
{
    Komplex k;
    double w = z.getArg(0)/2;
    double r = sqrt(z.getAbs());
    k.setRe(r*cos(w));
    k.setIm(r*sin(w));
    return k;
}

Komplex pow(Komplex z, int i)
{
    Komplex k;
    double w = z.getArg(0)*i;
    double r = pow(z.getAbs(), i);
    k.setRe(r*cos(w));
    k.setIm(r*sin(w));
    return k;
}
