#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <deque>
# include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack() {};
	MutantStack(const MutantStack& src) {
		if (*this != src)
			std::stack<T>::operator=(src);
	};
	~MutantStack() {};
	MutantStack& operator=(const MutantStack& src) {
		if (*this != src)
			std::stack<T>::operator=(src);
		return (*this);
	};

	typedef typename Container::iterator iterator;
	iterator begin() { return (std::stack<T, Container>::c.begin()); };
	iterator end() { return (std::stack<T, Container>::c.end()); };
	typedef typename Container::const_iterator const_iterator;
	const_iterator begin() const { return (std::stack<T, Container>::c.begin()); };
	const_iterator end() const { return (std::stack<T, Container>::c.end()); };
	typedef typename Container::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return (std::stack<T, Container>::c.rbegin()); };
	reverse_iterator rend() { return (std::stack<T, Container>::c.rend()); };
	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const { return (std::stack<T, Container>::c.rbegin()); };
	const_reverse_iterator rend() const { return (std::stack<T, Container>::c.rend()); };
};

#endif
