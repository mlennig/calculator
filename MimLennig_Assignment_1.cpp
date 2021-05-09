//  main.cpp
//  COEN244 Assign.1
//  Created by Mim Lennig on 2016-01-25.
//  Copyright © 2016 Mim Lennig . All rights reserved.
//
//  Basic and scientific calculator


#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
private:
    // a, b hold the parameters that the object is operating on
    double a;
    double b;
    
public:
    
    Calculator();   // the only defined constructor is the default constructor
    
    void sum(double, double);   // compute and print the sum
    void diff(double, double);  // compute and print the difference
    void quo(double, double);   // compute and print the quotient
    void mult(double, double);  // compute and print the product
    void sqr(double);           // compute and print the square root
    void invrs(double);         // compute and print the multiplicative inverse
    void setVariables(double&, double&);    // set value of a and b
    
};

class SCalculator {
private:
    // a, b hold the parameters that the object is operating on
    double a;
    double b;
    
public:
    
    SCalculator();  // the only defined constructor is the default constructor
    unsigned long long factorial(unsigned long long);   // compute the factorial
    void printfact(unsigned long long);                 // print the factorial
    void cosine(double);                                // compute and print the cosine
    void sine(double);                                  // compute and print the sine
    void tangent(double);                               // compute and print the tangent
    void power(double, double);                         // compute and print the exponentiation
};


Calculator::Calculator(){
    cout << "You've created a basic calculator. " << endl;
    a = 0;
    b = 0;
}

void Calculator::sum(double a, double b){
    cout << a << " + " << b << " = " << a+b << endl;
}

void Calculator::diff(double a, double b){
    cout << a << " - " << b << " = " << a-b << endl;
}

void Calculator::quo(double a, double b){
    cout << a << " / " << b << " = " << a/b << endl;
}

void Calculator::mult(double a, double b){
    cout << a << " * " << b << " = " << a*b << endl;
}

void Calculator::sqr(double a){
    if (a < 0)
        // if the argument is negative, the result is imaginary
        cout << "Square root of " << a << " = " << sqrt(-a) << "i" << endl;
    else
        cout << "Square root of " << a << " = " << sqrt(a) << endl;
}

void Calculator::invrs(double a){
    cout << "1/" << a <<  " = " << 1/a << endl;
}

void Calculator::setVariables(double& c, double& d){
    a = c;
    b = d;
}

SCalculator::SCalculator(){
    cout << "You've created a scientific calculator." << endl;
    a = 0;
    b = 0;
}

unsigned long long SCalculator::factorial(unsigned long long n){
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void SCalculator::printfact(unsigned long long n){
    cout << n << "! = " << factorial(n) << endl;
}

void SCalculator::cosine(double a){
    cout << "Cos(" << a << " degrees) = " << cos(a*M_PI/180) << endl;
}

void SCalculator::sine(double a){
    cout << "Sin(" << a << " degrees) = " << sin(a*M_PI/180) << endl;
}

bool tan_isdefined(int degrees){
    // tangent is undefined if the argument is an odd multiple of 90 degrees
    if (degrees % 90)
        return true;
    if ((degrees/90) % 2)
        return false;
    else
        return true;
}

void SCalculator::tangent(double a){
    while(true)
        if (tan_isdefined(a)){
            cout << "tan(" << a << " degrees) = " << tan(a*M_PI/180) << endl;
            break;
        }
        else {
            cout << "tan(" << a << " degrees) is a vertical asymptote. Therefore, the function is undefined at that point. Please input a value that is not an odd multiple of 90 degrees: ";
            cin >> a;
        }
}

void SCalculator::power(double a, double b){
    cout << a << "^" << b << " = " << pow(a,b) << endl;
}

double getnumeric(string prompt){
    // attempt to get a numeric input from the terminal
    // if user provides a nonnumeric input, reprompt
    double c;
    while (true){
        cout << prompt;
        cin >> c;
        if (cin.fail()){
            // input is nonnumeric
            cout << "Your input was nonnumeric." << endl;
            cin.clear();
            cin.ignore(100000,'\n');
        }
        else {
            // input is numeric
            cin.ignore(100000,'\n');
            break;
        }
    }
    return c;
}

int main() {
    
    Calculator calc;
    SCalculator scalc;
    string function;
    double c, d;
    
    c = getnumeric("Enter a numeric operand: ");
    
    calc.setVariables(c, d);

    cout << "Choose from the following list of operations {sum, difference, quotient, product, inverse, square root, power, factorial, trigonometric}: ";
    getline(cin, function);     // cin cannot handle embedded spaces without the help of getline
    
    while(function != "sum" && function != "difference" && function != "quotient" && function != "product" && function != "inverse" && function != "square root" && function != "factorial" && function != "trigonometric" && function != "power"){
        // Input was not a valid operation. Reprompt.
        cout << "Please enter a valid operation: ";
        getline(cin, function);
    }
    
    if(function == "sum" || function == "difference" || function == "quotient" || function == "product" || function == "power"){
        // Operation requires two operands
        d = getnumeric("Enter a 2nd numeric operand: ");
        
        calc.setVariables(c,d);
    
        if(function == "sum")
            calc.sum(c, d);
    
    
        else if(function == "difference")
            calc.diff(c, d);
    
    
        else if(function == "quotient"){
            if (d == 0){
                // Denominator was set to 0
                cout << "Please enter a nonzero divisor: ";
                cin >> d;
            }
            calc.quo(c, d);
        }
    
        else if (function == "product")
            calc.mult(c, d);
        
        else if (function == "power")
            scalc.power(c, d);
    }
    
    else if (function == "inverse")
        calc.invrs(c);
        
    else if (function == "square root")
        calc.sqr(c);
    
    else if (function == "factorial"){
        while (ceilf(c) != c || c < 0){
            // input is negative or noninteger
            cout << "Please enter a positive integer value: ";
            cin >> c;
        }
        
        scalc.printfact(c);
    }
    
    else if (function == "trigonometric"){
        string trigFunct;
        cout << "sine, cosine, or tangent? ";
        cin >> trigFunct;
        
        if (trigFunct != "sine" && trigFunct != "cosine" && trigFunct != "tangent"){
            // input is not a valid operation
            cout << "Please enter a valid trigonometric function: ";
            cin >> trigFunct;
        }
        
        if (trigFunct == "sine")
            scalc.sine(c);
        else if (trigFunct == "cosine")
            scalc.cosine(c);
        else if (trigFunct == "tangent")
            scalc.tangent(c);
        
    }
    
}