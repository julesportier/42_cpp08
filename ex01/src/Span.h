#ifndef SPAN_H
# define SPAN_H

# include <vector>

using std::vector;
using std::size_t;

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(Span const& src);
	~Span();
	Span& operator=(Span const& src);
	void addNumber(int i);
	void addNumber(size_t count, const int value);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void printContainer() const;
	class ContainerOutOfRange : public std::exception {
		const char* what() const throw();
	};
	class InvalidContainerSize : public std::exception {
		const char* what() const throw();
	};
private:
	unsigned int m_size;
	vector<int> m_cont;
};

#endif
