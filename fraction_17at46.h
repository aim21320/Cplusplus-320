/*
 * fraction_17at46.h
 *
 *  Created on: Oct. 10, 2020
 *      Author: Areeya Techanitisawad 20107442
 */


#pragma once

using namespace std;
#include <iostream>

class Fraction{
private:
	int _numerator;
	int _denominator;
public:

	Fraction(); //Fraction constructor
	Fraction(int num);// constructor
	Fraction(int num ,int den); //Numerator and denominator constructor
	int numerator() const;//getter
	int denominator() const;//getter
	int gcd(int n, int m);//gcd function

	//unary operators

	Fraction& operator-();
	Fraction& operator++();//pre increment
	Fraction  operator++(int);//post increment
	Fraction& operator+=(const Fraction& right);

	//binary operators

	friend Fraction operator+(const Fraction& left, const Fraction& right);
	friend Fraction operator-(const Fraction& left, const Fraction& right);
	friend Fraction operator*(const Fraction& left, const Fraction& right);
	friend Fraction operator/(const Fraction& left, const Fraction& right);

	friend bool operator<(const Fraction& left, const Fraction& right);
	friend bool operator>(const Fraction& left, const Fraction& right);
	friend bool operator<=(const Fraction& left, const Fraction& right);
	friend bool operator>=(const Fraction& left, const Fraction& right);
	friend bool operator==(const Fraction& left, const Fraction& right);
	friend bool operator!=(const Fraction& left, const Fraction& right);

//input and output stream
	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	friend istream& operator>>(istream& in, const Fraction& fracion);

};

//fraction exception class
class FractionException {
	public:
		FractionException(const string& message);
		string& what();
	private:
		string message;
};
