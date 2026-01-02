#include "Span.h"
#include <iostream>
#include <string>

static void printBold(std::string str)
{
    std::cout << "\e[1m" << str << "\e[0m\n";
}

static void printException(std::exception const& e)
{
	std::cout << "Error: " << e.what() << '\n';
}

int main(void)
{
	printBold("Default constructor addNumber()");
	try {
		Span s;
		printBold("addNumber()");
		s.addNumber(1);
	} catch (std::exception const& e) {
		printException(e);
	}


	printBold("\nConstructor:");
	try {
		Span s(3);
		printBold("addNumber()");
		for (int i = 0; i < 3; ++i)
			s.addNumber(i);
		printBold("printContainer()");
		s.printContainer();
		printBold("max capacity");
		s.addNumber(4);
	} catch (std::exception const& e) {
		printException(e);
	}

	printBold("\nCopy constructor:");
	try {
		Span s(3);
		for (int i = 0; i < 2; ++i)
			s.addNumber(i);
		s.printContainer();
		Span cpy(s);
		cpy.printContainer();
		cpy.addNumber(3);
		cpy.printContainer();
		s.printContainer();
	} catch (std::exception const& e) {
		printException(e);
	}

	printBold("\nCopy assigment operator:");
	try {
		Span s(3);
		for (int i = 0; i < 2; ++i)
			s.addNumber(i);
		s.printContainer();
		Span cpy(3);
		cpy = s;
		cpy.printContainer();
		cpy.addNumber(3);
		cpy.printContainer();
		s.printContainer();
	} catch (std::exception const& e) {
		printException(e);
	}

	printBold("\naddNumber() with Range:");
	try {
		printBold("ten numbers");
		Span s(10);
		s.addNumber(10, 1);
		printBold("printContainer()");
		s.printContainer();
	} catch (std::exception const& e) {
		printException(e);
	}
	try {
		printBold("thousand thousand numbers (no print)");
		Span s(100000);
		s.addNumber(100000, 1);
		printBold("-> ok");
	} catch (std::exception const& e) {
		printException(e);
	}
	try {
		printBold("too much numbers");
		Span s(10);
		s.addNumber(11, 1);
	} catch (std::exception const& e) {
		printException(e);
	}

	printBold("\nlongestSpan():");
	try {
		Span s(5);
		s.addNumber(0);
		s.addNumber(6);
		s.addNumber(3);
		s.printContainer();
		std::cout << s.longestSpan() << '\n';
		s.addNumber(7);
		s.printContainer();
		std::cout << s.longestSpan() << '\n';
		s.addNumber(-7);
		s.printContainer();
		std::cout << s.longestSpan() << '\n';
	} catch (std::exception const& e) {
		printException(e);
	}

	printBold("\nlongestSpan() except:");
	try {
		Span s(0);
		std::cout << s.longestSpan() << '\n';
	} catch (std::exception const& e) {
		printException(e);
	}
	try {
		Span s(1);
		s.addNumber(6);
		s.printContainer();
		std::cout << s.longestSpan() << '\n';
	} catch (std::exception const& e) {
		printException(e);
	}

	printBold("\nshortestSpan():");
	try {
		Span s(6);
		s.addNumber(0);
		s.addNumber(3);
		s.printContainer();
		std::cout << s.shortestSpan() << '\n';
		s.addNumber(7);
		s.printContainer();
		std::cout << s.shortestSpan() << '\n';
		s.addNumber(-7);
		s.printContainer();
		std::cout << s.shortestSpan() << '\n';
		s.addNumber(-1);
		s.printContainer();
		std::cout << s.shortestSpan() << '\n';
		s.addNumber(-7);
		s.printContainer();
		std::cout << s.shortestSpan() << '\n';
	} catch (std::exception const& e) {
		printException(e);
	}

	printBold("\nshortestSpan() except:");
	try {
		Span s(0);
		std::cout << s.shortestSpan() << '\n';
	} catch (std::exception const& e) {
		printException(e);
	}
	try {
		Span s(1);
		s.addNumber(6);
		s.printContainer();
		std::cout << s.shortestSpan() << '\n';
	} catch (std::exception const& e) {
		printException(e);
	}
	return (0);
}
