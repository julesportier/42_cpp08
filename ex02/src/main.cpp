#include "MutantStack.h"
#include <iostream>
#include <string>

static void printBold(std::string str)
{
    std::cout << "\e[1m" << str << "\e[0m\n";
}

int main(void)
{
	printBold("42 tests <deque>: ");
	std::deque<int> d;
	d.push_back(5);
	d.push_back(17);
	std::cout << d.back() << std::endl;
	d.pop_back();
	std::cout << d.size() << std::endl;
	d.push_back(3);
	d.push_back(5);
	d.push_back(737);
	//[...]
	d.push_back(0);
	std::deque<int>::iterator d_it = d.begin();
	std::deque<int>::iterator d_ite = d.end();
	++d_it;
	--d_it;
	while (d_it != d_ite)
	{
		std::cout << *d_it << std::endl;
		++d_it;
	}

	printBold("42 tests <MutantStack>: ");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	printBold("\nMy tests: ");
	MutantStack<int> m;
	m.push(1);
	m.push(3);
	printBold("top(): ");
	std::cout << m.top() << '\n';
	printBold("begin(): ");
	std::cout << *m.begin() << '\n';
	printBold("end() - 1: ");
	std::cout << *(m.end() - 1) << '\n';

	printBold("copy constructor:");
	MutantStack<int> cpy(m);
	printBold("top(): ");
	std::cout << cpy.top() << '\n';
	printBold("begin(): ");
	std::cout << *cpy.begin() << '\n';

	printBold("copy assignement:");
	MutantStack<int> a_cpy = m;
	printBold("top(): ");
	std::cout << a_cpy.top() << '\n';
	printBold("begin(): ");
	std::cout << *a_cpy.begin() << '\n';

	printBold("iterator:");
	MutantStack<int> is;
	is.push(1);
	is.push(2);
	is.push(3);
	it = is.begin();
	ite = is.end();
	while (it != ite)
	{
		std::cout << *it << '\n';
		*it += 1;
		std::cout << "*it + 1 == " << *it << '\n';
		*it -= 1;
		++it;
	}
	printBold("const iterator:");
	MutantStack<int>::const_iterator cit = is.begin();
	MutantStack<int>::const_iterator cite = is.end();
	while (cit != cite)
	{
		std::cout << *cit << '\n';
		// Can't change const iterator
		// *cit += 1;
		++cit;
	}
	printBold("reverse iterator:");
	MutantStack<int>::reverse_iterator rit = is.rbegin();
	MutantStack<int>::reverse_iterator rite = is.rend();
	while (rit != rite)
	{
		std::cout << *rit << '\n';
		*rit += 1;
		std::cout << "*rit + 1 == " << *rit << '\n';
		*rit -= 1;
		++rit;
	}
	printBold("const reverse iterator:");
	MutantStack<int>::const_reverse_iterator crit = is.rbegin();
	MutantStack<int>::const_reverse_iterator crite = is.rend();
	while (crit != crite)
	{
		std::cout << *crit << '\n';
		// Can't change const riterator
		// *crit += 1;
		++crit;
	}
	return (0);
}
