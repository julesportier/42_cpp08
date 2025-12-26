#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
# include <iostream>

template <typename T>
void print_found_iterator(T& c, typename T::iterator it)
{
	if (it != c.end())
		std::cout << *it << '\n';
	else
		std::cout << "end\n";
}

template <typename T>
typename T::iterator easyfind(T& c, int i)
{
	return (find(c.begin(), c.end(), i)); 
}

#endif
