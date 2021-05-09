COEN244.Assignment(1)    Due date: Feb. 1st, 2016

Calculators 
===========

Design & Implement one C++ program that allows the user to 
create & use of two types: a basic calculator and a scientific calculator. Use classes to implement the two types of calculators;
do not utilize inheritance (even if you know it).


(a) Basic Calculator 
--------------------

Create a basic calculator class, which allows you to create
any number of calculators and use them to: add, subtract, 
divide and multiply two numbers as well as find the square
root and the inverse (1/x) of a number (x). Invalid inputs
should be detected and an error (E) message returned.

Example1:

in the main program,

bcalculator C,D; // returns: "basic calculator created" twice
C.add(5,-2);     // returns: 3
C.sub(3,8);      // returns: 5
D.sqrt(-2);      // returns: E
D.inv(2);        // returns: 0.500

(b) Scientific Calculator
-------------------------

Create a scientific calculator with the same functionalities 
as the basic calculator in addition to: power, factorial and 
the trig functions: sin, cos and tan (in degrees).

Example2:

in the main program,

scalculator V;  // returns: "scientific calculator created"
V.sin(45);      // returns: 0.707
V.pow(3,2);     // returns: 9
V.fact(4);      // returns: 24
V.cos(90);      // returns: 0.000


It is important that you test your program so it does not crash
and it always returns correct outputs. 


// end.

