


#ifndef _RATIONAL_H__
#define _RATIONAL_H__

#include <iostream>

class Rational {
public:
    Rational();
    Rational(int nom);
    Rational(int nom, int denom);

    int get_nominator() const ;
    int get_denominator()const ;

    void set_nominator( int );
    void set_denominator( int );


    void toString() const;
    
    double real() const;
    
    
    void add( Rational other );
    
    static int get_counter() { return counter;}
    
    

private:

    static void set_counter( int p_counter ){  
        counter = p_counter;
    }
    
    void reduce();
    
    int gcd() const;
    
    int gcd_wrapper( int a, int b ) const;
    
    int nominator=5;
    int denominator=5;

    static int counter;
    
};




#endif

