#include "Span.h"
#include <algorithm>
#include <iostream>
#include <limits>

using std::numeric_limits;

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
Span::Span() : m_size(0) {};

Span::Span(unsigned int n) : m_size(n) {};

Span::Span(Span const& src)
	: m_size(src.m_size)
	, m_cont(src.m_cont)
{};

Span::~Span() {};

/************
* OPERATORS *
************/
Span& Span::operator=(Span const& src)
{
	if (this == &src)
		return (*this);
	m_size = src.m_size;
	m_cont = src.m_cont;
	return (*this);
}

/**********
* METHODS *
**********/
void Span::addNumber(int i)
{
	if (m_cont.size() >= m_size)
		throw Span::ContainerOutOfRange();
	m_cont.push_back(i);
}

void Span::addNumber(size_t count, const int value)
{
	if (m_cont.size() + count > m_size) 
		throw Span::ContainerOutOfRange();
	m_cont.insert(m_cont.end(), count, value);
}

unsigned int Span::shortestSpan() const
{
	if (m_size < 2)
		throw Span::InvalidContainerSize();
	unsigned int span = numeric_limits<unsigned int>::max();
	vector<int>::const_iterator end = m_cont.end();
	for (vector<int>::const_iterator f_it = m_cont.begin(); f_it != end; ++f_it) {
		for (vector<int>::const_iterator e_it = f_it + 1; e_it != end; ++e_it) {
			if (*f_it == *e_it)
				return (0);
			else if (static_cast<unsigned int>(abs(*f_it - *e_it)) < span)
				span = abs(*f_it - *e_it);
		}
	}
	return (span);
}

unsigned int Span::longestSpan() const
{
	if (m_size < 2)
		throw Span::InvalidContainerSize();
	return (
		*std::max_element(m_cont.begin(), m_cont.end())
		- *std::min_element(m_cont.begin(), m_cont.end())
	);
}

static void printInt(const int n)
{
	std::cout << n << ' ';
}

void Span::printContainer() const
{
	std::for_each(
		m_cont.begin(),
		m_cont.end(),
		printInt
	);
	std::cout << '\n';
}

/*************
* EXCEPTIONS *
*************/
const char* Span::ContainerOutOfRange::what() const throw()
{
	return ("Max Span's container capacity reached");
}

const char* Span::InvalidContainerSize::what() const throw()
{
	return ("Invalid Span's container size for operation");
}
