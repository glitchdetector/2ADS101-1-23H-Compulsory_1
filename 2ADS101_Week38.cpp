#include <iostream>
#include <iomanip>
/*
	Vegard M' Bendiktsen
	2ADS101
	Week 38 (21.08.2023)
	Recursion with Factorial and Fibonacci

	This was written in the first lecture
	Will likely be the compulsory 1 delivery

	Notes from testing the program
	Factorial n > 170 is infinity
	Fibonacci n > 1476 is infinity
*/

// Basic implementation of Factorial
// Handles cases of n = 1, n = 0 and n < 0
// Uses double type to handle more cases of n > 12
double factorial(double n) {
	if (n > 1)
		return n * factorial(n - 1);
	return 1;
}

// Basic implementation of Fibonacci
// Slow implementation, has to traverse the entire remaining sequence for every step
// Returns the resulting sum at the specified location in the sequence
// Handles the base case of n < 0, n = 0 and n = 1
// Uses double type to handle more cases of n > 46
double fibonacci(double n) {
	if (n > 1)
		return fibonacci(n - 1) + fibonacci(n - 2);
	if (n < 0) 
		return 0;
	return n;
}

// Prints the sequence as it is calculated
// Uses the function above, so it is very slow at high cases
double fibonacci_seq(double n, double target) {
	std::cout << fibonacci(n) << " ";
	if (n >= target) 
		return fibonacci(target);
	return fibonacci_seq(n + 1, target);
}

// A fast as FUCK approach with memory!
// Only traverses the sequence once
// Can calculate the entire 1476 sequence (seemingly) instantly
// Console output appears to be the slowdown, not the calculation :skull:
double fibonacci_memory(double n, double n_minus_one, double n_minus_two, double target) {
	
	// Default cases
	if (n <= 0) {
		n_minus_one = 0;
		n_minus_two = 0;
	} else if (n <= 2) {
		n_minus_two = 0;
		n_minus_one = 1;
	}

	if (n > target) 
		return n_minus_one;

	double sum = (n_minus_one + n_minus_two);
	std::cout << sum << " ";
	return fibonacci_memory(n + 1, sum, n_minus_one, target);
}

int main()
{
	// Take user input
	double n;
	std::cout << "Enter a number " << std::endl << "> ";
	std::cin >> n;
	std::cout << std::endl;

	// Prevent scientific notation and remove decimals
	std::cout << std::fixed << std::setprecision(0);

	// Check if user input is a number
	if (std::cin.fail())
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}

	std::cout << "Results:" << std::endl;

	// Calculate the Fibonacci sequence
	double fib_fast = fibonacci_memory(0, 0, 0, n);
	std::cout << std::endl << "> Fibonacci sequence index " << n << " is " << fib_fast << std::endl;

	// Slow approach, but simple
	// std::cout << "Simple fibonacci approach, may be slow:" << std::endl;
	// double fib = fibonacci_seq(0, n);
	// std::cout << std::endl << "> Fibonacci sequence index " << n << " is " << fib << std::endl;

	// Calculate the factorial
	double fac = factorial(n);
	std::cout << "> " << n << "! = " << fac << std::endl;

	std::cout << std::endl;
	

	// Recursive main function!!
	main();
}