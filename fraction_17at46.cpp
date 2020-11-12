/*
 * fraction_17at46.cpp
 *
 *  Created on: Oct. 10, 2020
 *      Author: Areeya Techanitisawad 20107442
 */

#include <iostream>
#include <sstream>
#include <string>
#include "fraction_17at46.h"

using namespace std;

//fraction exception class
FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }
//Initialize numerator and denominator
Fraction::Fraction() {
	_numerator = 0;
	_denominator = 1;
}

Fraction::Fraction(int num) {
	_numerator = num;
	_denominator = 1;
}
//gcd recursion
int Fraction::gcd(int n, int m) {
	if (m == 0)
		return n;
	return gcd(m, n % m);
}


Fraction::Fraction(int num, int den) {
	//check for fractionexception
	if (den == 0){
		throw FractionException ("Give number more than 0");
	}
//simplify the fraction using gcd
	int gcdd = gcd(num, den);
	_numerator = num/gcdd;
	_denominator = den/gcdd;
// if less numerator or denominator is less than zero then change to negative number
	if (_numerator < 0 && _denominator < 0) {
		_numerator = -_numerator;
		_denominator = -_denominator;
	} else if (_denominator < 0 && _numerator > 0) {
		_numerator = -_numerator;
		_denominator = -_denominator;
	}
}
//numerator and denominator accessor
int Fraction::numerator() const
{
	return _numerator;
}

int Fraction::denominator() const
{
	return _denominator;
}

//unary operators

Fraction& Fraction::operator-() {
	_numerator = -_numerator; //negative number
	return *this;
}
//pre increment ++ for fraction
Fraction& Fraction::operator++(){
	_numerator += _denominator; // add numerator + denominator
	return *this;
}

//post increment ++ for fraction
Fraction  Fraction::operator++(int n){
	Fraction fraction(_numerator,_denominator);
	_numerator += _denominator; // add denominator
	return fraction;

}

Fraction& Fraction::operator+=(const Fraction& right){
    int num, den;
    num = (_numerator * right._denominator) + (right._numerator * _denominator);
    den = _denominator * right._denominator;
    int gcdd = gcd(num, den);
    num = num /gcdd;
    den = den /gcdd;
    return *this;
}

//binary operators

Fraction operator+(const Fraction& left, const Fraction& right){
    int num = (left.numerator() * right.denominator()) + (right.numerator() * left.denominator());
    int den = right.denominator() * left.denominator();
    return Fraction(num, den);
}

Fraction operator-(const Fraction& left, const Fraction& right){
    int num = (left.numerator() * right.denominator()) - (right.numerator() * left.denominator());
    int den = right.denominator() * left.denominator();
    return Fraction(num, den);
}

Fraction operator*(const Fraction& left, const Fraction& right){
    int num = left.numerator() * right.numerator();
    int den = left.denominator() * right.denominator();
    return Fraction(num, den);
}

Fraction operator/(const Fraction& left, const Fraction& right){
    int num = left.numerator() * right.denominator();
    int den = left.denominator() * right.numerator();
    return Fraction(num,den);
}


//boolean operators

bool operator<(const Fraction& left, const Fraction& right){
	if (left.numerator() / right.denominator() < left.denominator() / right.numerator()) {
		return true;
	} else {
		return false;
	}
}
bool operator>(const Fraction& left, const Fraction& right){
    if(left.numerator() / left.denominator() > right.numerator() / right.denominator()){
        return true;
    }else{
        return false;
    }
}
bool operator<=(const Fraction& left, const Fraction& right){
	if (left.numerator() * right.denominator() <= left.denominator() * right.numerator()) {
		return true;
	} else {
		return false;
	}
}
bool operator>=(const Fraction& left, const Fraction& right){
	if (left.numerator() * right.denominator() >= left.denominator() * right.numerator()) {
		return true;
	} else {
		return false;
	}
}
bool operator==(const Fraction& left, const Fraction& right){
	//check if left and right are equal
    if((left.numerator() == right.numerator()) && (left.denominator() == right.denominator())){
        return true;
    }else{
        return false;
    }
}
bool operator!=(const Fraction& left, const Fraction& right){
	//check if left and right are not equal
    if((left.numerator() != right.numerator()) || (left.denominator() != right.denominator())){
    	return true;
    }else{
    }   return false;
}

//input and output stream

ostream& operator<<(ostream& out, const Fraction& fraction) {
    out << fraction._numerator << "/" << fraction._denominator << endl;
    return out;
}

istream& operator>>(istream& in,const Fraction& fraction){
	in >> fraction._numerator >> fraction._denominator;
	int n;
	if(isdigit(n)){
		in >> fraction._denominator>> fraction._numerator;
	}
	return in;
}
