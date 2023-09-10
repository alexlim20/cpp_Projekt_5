/*
 * Tests fuer die Klasse Komplex
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "testlevel.h"
#include "komplex.h"

#define STABILITYTEST(testexpression) {\
    cout << "Stabilität: " \
         << ((testexpression) ? "OK" : "##Fehler: Operator darf Parameter nicht ändern!") \
         << endl << endl;}

#define REFERENCETEST(operator) {\
    cout << "Test auf Referenzen: " \
         << ( &tmp == &(tmp operator c) ? "OK" : "## Fehler! Referenzparamater bzw. Rückgabewerte fehlerhaft verwendet!") \
         << endl << endl;}

#define REFERENCETESTUNARY(testexpression) {\
    cout << "Test auf Referenzen: " \
         << ( (testexpression) ? "OK" : "## Fehler! Referenzparamater bzw. Rückgabewerte fehlerhaft verwendet!") \
         << endl << endl;}


using namespace std;

int main()
{
    {
	cout<<"---->Test: Verwendung von Konstruktor und Print\n";
	Komplex a;
	a.print(cout);
	Komplex b(1.0,-2.0);
	b.print(cout);
	cout<<"\n(1+0j)(1-2j) = Zeile darueber\n\n";
    }


#if test_level >0
    {
	cout<<"---->Test: Get Methoden fuer Re, Im, Abs und Arg" << endl;
	Komplex a(1.0,2.0);
	a.print(cout);
	cout << setprecision(6);
	cout << ": " << a.getRe() << " | " << a.getIm() << " | "
	    << a.getAbs() << " | " << a.getArg() << " | " << a.getArg(false)
	    << " | " << a.getArg(true) << endl;
	cout<<"(1+2j): 1 | 2 | 2.23607 | 1.10715 | 1.10715 | 63.4349 = Zeile darueber" << endl << endl;
	Komplex b(-1.0,-2.0);
	b.print(cout);
	cout << ": " << b.getRe() << " | " << b.getIm() << " | "
	    << b.getAbs() << " | " << b.getArg() << " | " << b.getArg(false)
	    << " | " << b.getArg(true) << endl;
	cout<<"(-1-2j): -1 | -2 | 2.23607 | -2.03444 | -2.03444 | -116.565 = Zeile darueber" << endl << endl;
	Komplex c(1.25,2.25);
	c.print(cout);
	cout << ": " << c.getRe() << " | " << c.getIm() << " | "
	    << c.getAbs() << " | " << c.getArg() << " | " << c.getArg(false)
	    << " | " << c.getArg(true) << endl;
	cout<<"(1.25+2.25j): 1.25 | 2.25 | 2.57391 | 1.0637 | 1.0637 | 60.9454 = Zeile darueber" << endl << endl;
    }
#endif

#if test_level >1
    {
	cout<<"---->Test: Ueberladene print-Methode " << endl;
	Komplex a(1.0,2.0);
	a.print(cout);
	cout << ": "; a.print(cout, true);
	cout << " | "; a.print(cout, false);
	cout << endl;
	cout<<"(1+2j): (2.23607;63.4349) | (2.23607;1.10715) = Zeile darueber" << endl << endl;
    }
#endif

#if test_level >2
    {
	cout<<"---->Test: Ueberladener Konstruktor " << endl;
	Komplex a(true,1.0,60.0);
	a.print(cout);
	cout << endl;
	cout<<"(0.5+0.866025j) = Zeile darueber" << endl << endl;
	Komplex b(true,1.0,-60.0);
	b.print(cout);
	cout << endl;
	cout<<"(0.5-0.866025j) = Zeile darueber" << endl << endl;
	Komplex c(true,1.0,-120.0);
	c.print(cout);
	cout << endl;
	cout<<"(-0.5-0.866025j) = Zeile darueber" << endl << endl;
	Komplex d(true,1.0,120.0);
	d.print(cout);
	cout << endl;
	cout<<"(-0.5+0.866025j) = Zeile darueber" << endl << endl;
	Komplex e(false,2.0,M_PI/4);
	e.print(cout);
	cout << endl;
	cout<<"(1.41421+1.41421j) = Zeile darueber" << endl << endl;
    }
#endif


#if test_level >3
    {
	Komplex b1(3.0, 4.0);
	Komplex b2(2.2, 6.5);
	Komplex b3(b1);
	cout << "---->Test fuer ueberladenen Ausgabeoperator " << endl << endl;
	cout << b1 << " --- ";
	cout << b2 << " --- ";
	cout << Komplex(0.0, 1.0) << endl;
	cout << "(3+4j) --- (2.2+6.5j) --- (0+1j) = Zeile darueber" << endl << endl;
    }
#endif // test_level

#if test_level >4
    {
    const Komplex b1(3.0,4.0);
    //Komplex tmp=b1;
    cout << "---->Test fuer ueberladene Arithmetikoperatoren" << endl << endl;
    cout << "Vorzeichen" << endl;
    cout << -b1 << endl;
    cout << "(-3-4j) = Zeile darueber" << endl;
    //STABILITYTEST(tmp==b1);
    cout << "Konjugation" << endl;
    cout << ~b1 << endl;
    cout << "(3-4j) = Zeile darueber" << endl;
    //STABILITYTEST(tmp==b1);
    }
#endif

#if test_level >5
    {
	const Komplex b1(3.0,4.0);
	const Komplex b2(-2.0,-3.0);
	//Komplex tmp=b1;
	//Komplex tmp2=b2;
	cout << "Multiplikation" << endl;
	cout << b1 << " * " << b2 << " = " << b1 * b2 << endl;
	cout << b1 << " * " << b2 << " = "
	    << "(6-17j) = Zeile darueber"  << endl;
	cout << b1 << " * 2.5 = " << b1 * 2.5 << endl;
	cout << b1 << " * 2.5 = "
	    << "(7.5+10j) = Zeile darueber" << endl << endl;
	cout << "2.5 * " << b2 << " = " << 2.5 * b2 << endl;
	cout << "2.5 * " << b2 << " = "
	    << "(-5-7.5j) = Zeile darueber" << endl << endl;
	//STABILITYTEST(tmp==b1 && tmp2==b2);
    }
#endif

#if test_level >6
    {
	Komplex c(3.0,4.0);
	Komplex tmp=c;
    cout << "---->Test fuer ueberladene Zuweisungsoperatoren" << endl << endl;

    cout << "Zuweisung" << endl;
    cout << "*=" << endl;
    c *= Komplex(1.0,2.0);
    cout << c << endl;
    cout << "(-5+10j) = Zeile darueber" << endl;
    REFERENCETEST(*=)
    }
#endif

#if test_level >7
    {
    const Komplex c(1.0, 2.0), d(2.0, 3.0), e(2.0, 3.0);
    cout << "---->Test fuer ueberladene Vergleichsoperatoren" << endl << endl;

//    cout << "==" << endl;
//    cout << (c==d) << " --- " << (d==e) << endl;
//    cout << "0 --- 1 = Zeile darueber" << endl << endl;
    cout << "<" << endl;
    cout << (c<d) << " --- " << (d<e) << " --- " << (e<c)<< endl;
    cout << "1 --- 0 --- 0 = Zeile darueber" << endl << endl;
}
#endif


#if test_level >8
    {
	Komplex c(3.0, 4.0);
	Komplex tmp=c;
	cout << "---->Test: Inkrement" << endl;
	cout << c++; cout << " --- " << c << endl;
	cout << "(3+4j) --- (4+4j) = Zeile darueber" << endl << endl;
	cout << ++c;
	cout << " --- " << c << endl;
	cout << "(5+4j) --- (5+4j) = Zeile darueber" << endl;
	REFERENCETESTUNARY(&tmp==&(++tmp));
    }
#endif

#if test_level >9
{
    const Komplex c(6.0, 8.0) ;
    Komplex d;
    cout << "---->Test: Wurzel ziehen" << endl;
    d = sqrt(c);
    cout << "sqrt(" << c << ") = " << d << endl;
    cout << "sqrt((6+8j)) = (2.82843+1.41421j) = Zeile darueber" << endl << endl;
}
#endif

#if test_level >10
{
    const Komplex e(6.0, 8.0);
    Komplex f;
    cout << "---->Test: Potenz berechnen" << endl;
    f = pow(e, 4);
    cout << e << "^4 = " << f << endl;
    cout << "(6+8j)^4 = (-8432-5376j) = Zeile darueber" << endl << endl;
}
#endif

    cout << "ENDE: Testlevel " << test_level << endl;

    return 0;
}


