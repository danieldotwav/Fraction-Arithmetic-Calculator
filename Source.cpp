#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    cout << "Welcome\n";

    Fraction num1, num2;
    int choice{ 1 };

    while (choice) {
        cout << "\nEnter the first fraction in the form  X / Y :\n";
        cin >> num1;

        cout << "\nEnter the second fraction in the form X / Y :\n";
        cin >> num2;
        cout << endl;

        cout << num1 << " + " << num2 << " = ";
        cout << num1 + num2 << endl << endl;

        cout << "Would you like to run the program again?\n";
        cout << "Enter 1 for YES\nEnter 0 to Exit\n";
        cin >> choice;
        cout << endl;

        while (choice != 1 && choice != 0) {
            cout << "Please enter a valid number\n";
            cout << "Enter 1 to restart the program\nEnter 0 to Exit\n";
            cin >> choice;
        }
    }

    cout << "Terminating Program...\n";
    cout << "*Sad computer noises*" << endl;

    return 0;
}