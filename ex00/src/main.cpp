#include "easyfind.h"
#include <deque>
#include <vector>

static void print_bold(std::string str)
{
	std::cout << "\e[1m" << str << "\e[0m\n";
}

int main(void)
{
	print_bold("vector:");
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::vector<int>::iterator it = easyfind(v, 1);
	print_found_iterator(v, it);
	it = easyfind(v, 2);
	print_found_iterator(v, it);
	it = easyfind(v, 3);
	print_found_iterator(v, it);
	it = easyfind(v, 4);
	print_found_iterator(v, it);
	it = easyfind(v, 0);
	print_found_iterator(v, it);
	it = easyfind(v, -1);
	print_found_iterator(v, it);

	print_bold("deque:");
	std::deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	std::deque<int>::iterator d_it = easyfind(d, 1);
	print_found_iterator(d, d_it);
	d_it = easyfind(d, 2);
	print_found_iterator(d, d_it);
	d_it = easyfind(d, 3);
	print_found_iterator(d, d_it);
	d_it = easyfind(d, 4);
	print_found_iterator(d, d_it);
	d_it = easyfind(d, 0);
	print_found_iterator(d, d_it);
	d_it = easyfind(d, -1);
	print_found_iterator(d, d_it);

	return (0);
}
