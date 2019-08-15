#include <iostream>
#include <string>
using namespace std;

//This function takes in a string that is the given number.
//The function will return true if the string is an integer.
bool isNumber(string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}

//This function takes in the given number and returns the
//additive persistence.
int additivePersistence(string s) {
    string digit;
    int count = 0;

    while (stoi(s) > 9) {
        int currentSum = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            digit = s[i];
            int x = stoi(digit);
            currentSum += x;
        }
        s = to_string(currentSum);
        ++count;
    }
    return count;
}

//This function takes in the given number and returs the
//multiplicative persistence
int multiplicativePersistence(string s) {
    string digit;
    int count = 0;

    while (stoi(s) > 9) {
        int currentProduct = 1;
        for (size_t i = 0; i < s.length(); ++i) {
            digit = s[i];
            int x = stoi(digit);
            currentProduct *= x;
        }
        s = to_string(currentProduct);
        ++count;
    }
    return count;
}

int main() {
    cout << "This program will tell you the additive and multiplicative"
        << " persistences for a given number." << endl;

    cout << endl;


    string input;

    //Ask the user for a number.
    cout << "Enter a positive integer: ";
    cin >> input;

    //Error checking to make sure input is a positive number.
    while (isNumber(input) == false || stoi(input) < 0) {
        cout << "Error! You must enter a positive integer." << endl;
        cout << "Enter an integer: ";
        cin >> input;
    }


    int add = additivePersistence(input);
    int mult = multiplicativePersistence(input);

 
    cout << "The additive persistence is " << add << "." << endl;
    cout << "The multiplicative presistence is " << mult << "." << endl;
}