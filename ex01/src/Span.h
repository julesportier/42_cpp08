#ifndef SPAN_H
# define SPAN_H

# include <vector>

class Span {
public:
	Span();
	Span(const unsigned int n);
	Span(const Span& src);
	~Span();
	Span& operator=(const Span& src);
	void addNumber(const int i);
	void addNumber(const unsigned int count, const int value);
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
	std::vector<int> m_cont;
};

#endif
