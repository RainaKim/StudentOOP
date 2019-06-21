#include <iostream>
#include <istream>
#include <iomanip>
#include <cmath>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
    if (abs((c1.get_real() - c2.get_real())) < 0.0001){
        if (abs((c2.get_imag() - c2.get_real())) < 0.0001)
            return true;
        else{
            return false;
        }

    }

    return false;  // temp!
}

ostream& operator<< (ostream& os, const Complex& c) {
    os << setprecision(3) << c.real << showpos << c.imag << "i" << noshowpos << endl;
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    cin >> c.real >> c.imag;
    return is;
}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::operator bool() const {
    if ((real != 0) || (imag != 0)){
        return true;
    }
    return false;
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex temp = Complex(*this);
    real++;
    return temp;
}

Complex& Complex::operator--(){
    --real;
    return *this;
}

    
Complex Complex::operator--(int dummy){
    Complex temp = Complex(*this);
    real--;
    return temp;
}

Complex operator+(const Complex& c1, const Complex& c2){
    double real_temp = c1.get_real()+c2.get_real();
    double imag_temp = c1.get_imag()+c2.get_imag();
    return Complex(real_temp, imag_temp);
}

Complex Complex::operator-=(const Complex& c){
    // Complex d(c.real-1, c.imag);
    // return d;
    real -=  c.real;
    imag -= c.imag;
    return *this;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator*(const int i) {
    return Complex(i * real, i * imag);
}