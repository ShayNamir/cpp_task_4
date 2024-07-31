// ID: 207192246
// Mail: ShayNamir@gmail.com

#include <cmath>
#include <stdexcept>
#include "Complex.hpp"

// initializes the complex number to 0 + 0i
Complex::Complex() : real(0), imag(0) {}

// Parameterized constructor - initializes the complex number to real + imag*i
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Copy constructor - initializes the complex number to the same values as another complex number
Complex::Complex(const Complex &other) : real(other.real), imag(other.imag) {}

// Getter functions for the real and imaginary parts
double Complex::getReal() const { return real; }
double Complex::getImaginary() const { return imag; }

// Setter functions for the real and imaginary parts
void Complex::setReal(double r) { real = r; }
void Complex::setImaginary(double i) { imag = i; }

// add two complex numbers
Complex Complex::operator+(const Complex &other) const { return Complex(real + other.real, imag + other.imag); }

// subtract two complex numbers
Complex Complex::operator-(const Complex &other) const { return Complex(real - other.real, imag - other.imag);}

// multiply a complex number by a scalar
Complex Complex::operator*(double scalar) const { return Complex(real * scalar, imag * scalar);}

// divide a complex number by a scalar
Complex Complex::operator/(double scalar) const
{
    if (scalar == 0) // check if the scalar is zero
    {
        throw invalid_argument("Division by zero");
    }
    return Complex(real / scalar, imag / scalar);
}

// multiply two complex numbers
Complex Complex::operator*(const Complex &other) const
{
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

// divide two complex numbers by the rule : (a+bi)/(c+di) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
Complex Complex::operator/(const Complex &other) const
{
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) // check if the denominator is zero
    { 
        throw invalid_argument("Division by zero");
    }
    return Complex((real * other.real + imag * other.imag) / denominator,
                   (imag * other.real - real * other.imag) / denominator);
}

// equality operator
bool Complex::operator==(const Complex &other) const {return real == other.real && imag == other.imag;}

// inequality operator
bool Complex::operator!=(const Complex &other) const { return !(*this == other);}

// Calculate the magnitude using the formula: sqrt(real^2 + imag^2)
double Complex::magnitude() const { return sqrt(real * real + imag * imag);}

// less than operator by comparing the magnitude of the complex numbers
bool Complex::operator<(const Complex &other) const { return this->magnitude() < other.magnitude();}

// greater than operator by comparing the magnitude of the complex numbers
bool Complex::operator>(const Complex &other) const { return this->magnitude() > other.magnitude();}

// less than or equal operator by comparing the magnitude of the complex numbers
bool Complex::operator<=(const Complex &other) const { return this->magnitude() <= other.magnitude();}

// greater than or equal operator by comparing the magnitude of the complex numbers
bool Complex::operator>=(const Complex &other) const { return this->magnitude() >= other.magnitude();}

// Implementation of the friend function for the insertion operator <<
ostream &operator<<(ostream &os, const Complex &complex)
{
    os << complex.real; // print the real part
    if (complex.imag >= 0) // check if the imaginary part is positive
    {
        os << "+" << complex.imag << "i";
    }
    else // if the imaginary part is negative
    {
        os << complex.imag << "i";
    }
    return os;
}

// Method to convert Complex to string
string Complex::to_string()
{
    stringstream ss;
    ss << real << (imag >= 0 ? "+" : "") << imag << "i";
    return ss.str();
}
