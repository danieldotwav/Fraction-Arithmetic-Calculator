#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{

private:
	int numerator;
	int denominator;
	static int count;

public:
	// Default Constructor
	Fraction();
	// Parametrized Constructor
	Fraction(double num, double denom);
	// Copy Constructor
	Fraction(const Fraction& RHS);
	// Destructor
	~Fraction();
	// Operator Overloads
	Fraction operator=(const Fraction& RHS);
	Fraction operator+(Fraction& RHS);
	friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& input, Fraction& fraction);

	double getNumerator() { return numerator; }
	static int getFractionCount() { return count; }
	int findLCM(int leftDenom, int rightDenom);
	void printSum();
	void printFraction();
};


#endif