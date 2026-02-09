#include "Span.h"
#include <algorithm>
#include <iostream>
#include <numeric>

/**************************
* CONSTRUCTORS/DESTRUCTOR *
**************************/
Span::Span() : m_size(0) {};

Span::Span(unsigned int n) : m_size(n) {};

Span::Span(const Span& src)
	: m_size(src.m_size)
	, m_cont(src.m_cont)
{};

Span::~Span() {};

/************
* OPERATORS *
************/
Span& Span::operator=(const Span& src)
{
	if (this != &src) {
		m_size = src.m_size;
		m_cont = src.m_cont;
	}
	return (*this);
}

/**********
* METHODS *
**********/
void Span::addNumber(const int i)
{
	if (m_cont.size() >= m_size)
		throw Span::ContainerOutOfRange();
	m_cont.push_back(i);
}

void Span::addNumber(const unsigned int count, const int value)
{
	if (m_cont.size() + count > m_size) 
		throw Span::ContainerOutOfRange();
	m_cont.insert(m_cont.end(), count, value);
}

unsigned int Span::shortestSpan() const
{
	if (m_size < 2)
		throw Span::InvalidContainerSize();
	std::vector<int> diff = m_cont;
	std::sort(diff.begin(), diff.end());
	std::adjacent_difference(diff.begin(), diff.end(), diff.begin());
	return (*std::min_element(diff.begin() + 1, diff.end()));
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
	std::for_each(m_cont.begin(), m_cont.end(), printInt);
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
