#include <iostream>
#include "Fraction.h"
#include "DivisionByZero.h"

int Fraction::count{0};

// Default Constructor
Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
    count++;
}

// Parametrized Constructor
Fraction::Fraction(double num, double denom) {
    numerator = num;
    denominator = denom;
    count++;
}

// Copy Constructor
Fraction::Fraction(const Fraction& RHS) {
    numerator = RHS.numerator;
    denominator = RHS.denominator;
    count++;
}

// Destructor
Fraction::~Fraction() {
    count--;
}

// Assignment Operator
Fraction Fraction::operator=(const Fraction& RHS) {
    numerator = RHS.numerator;
    denominator = RHS.denominator;

    return *this;
}

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Fraction& fraction) {
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}

// stream extraction operator overload
std::istream& operator>>(std::istream& input, Fraction& fraction) {
    char ch{ };

    try {
        input >> fraction.numerator;
        input >> ch; // skip the /
        input >> fraction.denominator;

        if (fraction.denominator == 0) {
            throw DivisionByZero();
        }
        if (fraction.numerator == 0) {
            throw "Numerator is zero";
        }
    }
    catch (DivisionByZero&) {
        while (fraction.denominator == 0) {
            std::cout << "\nDivision by 0 is invalid\n";

            // Loop for valid input
            std::cout << "\nEnter the fraction in the form  X / Y :\n";
            input >> fraction.numerator;
            input >> ch; // skip the /
            input >> fraction.denominator;
        }
    }
    catch (std::string) {
        std::cout << "\n***Note: A fraction with a numerator of zero will always result in zero\n";
    }
    catch (...) {
        std::cout << "\nThe default handler was executed\n";
    }

    return input;
}

// Returns an object of type Fraction (the sum in fraction form)
Fraction Fraction::operator+(Fraction& RHS) {
    Fraction temp;
    int LCM{ 0 };

    if (denominator == RHS.denominator) {
        temp.numerator = numerator + RHS.numerator;
        temp.denominator = denominator;
    }
    else {
        // Find Least Common Multiple
        LCM = findLCM(denominator, RHS.denominator);
        // Add numerators and set the new denominator to the LCM
        temp.numerator = numerator * (LCM / denominator)
            + RHS.numerator * (LCM / RHS.denominator);
        temp.denominator = LCM;
    }

    return temp;
}

//Add comments on functionality and make it more generic/modular
int Fraction::findLCM(int leftDenom, int rightDenom) {
    int LCM;

    for (LCM = (leftDenom > rightDenom) ? leftDenom : rightDenom; !((LCM % leftDenom == 0) && (LCM % rightDenom == 0)); LCM++);

    return LCM;

    // Another Algorithm
    /*
    int max { 0 };
    max = (leftDenom > rightDenom) ? leftDenom : rightDenom;
    while(true){
      if((max % leftDenom == 0) && (max % rightDenom == 0)){
        return max;
      }
      else{
        max++;
      }
    }
    */
}

void Fraction::printFraction() {
    std::cout << "(" << numerator << " / "
        << denominator << ")";
}

void Fraction::printSum() {
    std::cout << "Sum: " << numerator << " / " << denominator
        << std::endl;
}
