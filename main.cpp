#include <iostream>
#include <limits>
using namespace std;

// Function prototypes
int digitSum(int n);
int digitCount(int n);
int reverseDigits(int n, int accumulator);
bool isPalindrome(int n);

void displayMenu();
int getMenuChoice();
int getValidNumber();

// Recursive function for sum of digits
int digitSum(int n) {
    if (n == 0) {
        return 0;
    }

    return (n % 10) + digitSum(n / 10);
}

// Recursive function for counting digits
int digitCount(int n) {
    if (n < 10) {
        return 1;
    }

    return 1 + digitCount(n / 10);
}

// Recursive function for reversing digits
int reverseDigits(int n, int accumulator) {
    if (n == 0) {
        return accumulator;
    }

    return reverseDigits(
        n / 10,
        accumulator * 10 + n % 10
    );
}

// Function for checking palindrome
bool isPalindrome(int n) {
    return n == reverseDigits(n, 0);
}

// Display menu
void displayMenu() {
    cout << "\n====================================\n";
    cout << "       NUMBER ANALYSIS SYSTEM\n";
    cout << "====================================\n";
    cout << "1 - Sum of digits\n";
    cout << "2 - Count digits\n";
    cout << "3 - Reverse digits\n";
    cout << "4 - Check palindrome\n";
    cout << "0 - Exit\n";
    cout << "====================================\n";
}

// Validate menu choice
int getMenuChoice() {
    int choice;

    while (true) {
        cout << "Enter your choice: ";

        if (cin >> choice) {
            if (choice >= 0 && choice <= 4) {
                return choice;
            }

            cout << "Invalid choice! Please enter 0-4.\n";
        }
        else {
            cout << "Invalid input! Numbers only.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
        }
    }
}

// Validate number input
int getValidNumber() {
    int number;

    while (true) {
        cout << "Enter a number (0-999999): ";

        if (cin >> number) {
            if (number >= 0 && number <= 999999) {
                return number;
            }

            cout << "Invalid number; retry.\n";
        }
        else {
            cout << "Invalid number; retry.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
        }
    }
}

// Main function
int main() {
    int choice;
    int number;

    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {

            case 1:
                number = getValidNumber();
                cout << "Sum = " << digitSum(number) << endl;
                break;

            case 2:
                number = getValidNumber();
                cout << "Digits = "
                     << digitCount(number) << endl;
                break;

            case 3:
                number = getValidNumber();
                cout << "Reverse = "
                     << reverseDigits(number, 0) << endl;
                break;

            case 4:
                number = getValidNumber();

                if (isPalindrome(number)) {
                    cout << "Palindrome = Yes\n";
                }
                else {
                    cout << "Palindrome = No\n";
                }
                break;

            case 0:
            
             cout << "Exiting program...\n";
             break;
        }

    } while (choice != 0);

    return 0;
}