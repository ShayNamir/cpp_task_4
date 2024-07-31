// ID: 207192246
// Mail: ShayNamir@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Complex
{
    private:
        double real; // Real part of the complex number
        double imag; // Imaginary part of the complex number

    public:
        // Default constructor - initializes the complex number to 0 + 0i
        Complex();

        // Parameterized constructor - initializes the complex number to real + imag*i
        Complex(double r, double i);

        // Copy constructor
        Complex(const Complex &other);

        // Getter functions for the real and imaginary parts
        double getReal() const;
        double getImaginary() const;

        // Setter functions for the real and imaginary parts
        void setReal(double r);
        void setImaginary(double i);

        // operators overloading
        Complex operator+(const Complex &other) const; 
        Complex operator-(const Complex &other) const; 
        Complex operator*(double scalar) const; 
        Complex operator/(double scalar) const; 
        Complex operator*(const Complex &other) const; 
        Complex operator/(const Complex &other) const; 

        // Comparison operators
        bool operator==(const Complex &other) const;
        bool operator!=(const Complex &other) const;
        bool operator<(const Complex &other) const;
        bool operator>(const Complex& other) const;
        bool operator<=(const Complex& other) const;
        bool operator>=(const Complex& other) const;

        // Method to calculate the magnitude of the complex number
        double magnitude() const;

        // Method to convert Complex to string
        string to_string();

        // Friend function for the insertion operator <<
        friend ostream &operator<<(ostream &os, const Complex &complex);
};

#endif 
