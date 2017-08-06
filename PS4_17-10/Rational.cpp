#include "Rational.h"


int Rational::counter = 0;



using namespace std;

Rational::Rational(int nom, int denom) {

    set_nominator(nom);
    set_denominator(denom);

    set_counter(get_counter() + 1);


}
Rational::Rational() {

    set_counter(get_counter() + 1);


}
Rational::Rational(int nom):Rational(nom, 1) {

}

void Rational::toString() const {

    cout << "Rational Class: " << get_nominator() << " / " << get_denominator() << " = " << real() << endl;

}

int Rational::get_nominator()const {
    
    return nominator;
}

int Rational::get_denominator()const {
    return denominator;
}

void Rational::set_nominator(int nom) {
    nominator = nom;
    reduce();
}

void Rational::set_denominator(int denom) {

    if (0 != denom) {

        denominator = denom;
    } else {

        cout << "invalid denom!" << endl;
        denominator = 1;
    }

    reduce();
}

double Rational::real() const {

    return static_cast<double> (nominator) / denominator;

}

int Rational::gcd_wrapper(int a, int b) const {

    if (0 == b)
        return a;

    return gcd_wrapper(b, a % b);
}

int Rational::gcd() const {

    return gcd_wrapper(nominator, denominator);
}

void Rational::add(Rational other) {


    nominator *= other.denominator;
    other.nominator *= denominator;
    denominator *= other.denominator;


    nominator += other.nominator;


    reduce();

}

void Rational::reduce(){
    int gcd = gcd_wrapper(nominator, denominator);

    nominator /= gcd;
    denominator /= gcd;
}




