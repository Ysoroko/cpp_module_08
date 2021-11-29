/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:37:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/11/29 14:48:26 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// --------------------------- Canonic class functions ------------------------

static void ft_msg(std::string str)
{
	std::cout << str << std::endl;
}

Span::Span(unsigned int n_ints) : _n_ints(n_ints)
{
	_vector.reserve(n_ints);
	_n_contents = 0;
	//ft_msg("Span has been constructed");
}

Span::~Span()
{
	//ft_msg("Span has been destroyed");
}

Span::Span(Span const &ref) : _n_ints(ref._n_ints), _vector(ref._vector)
{
	_n_contents = ref._vector.size();
	ft_msg("Span has been constructed by copy");
}

Span const &Span::operator=(Span const &ref)
{
	this->_n_ints = ref._n_ints;
	this->_vector = ref._vector;
	this->_n_contents = ref._vector.size();
	ft_msg("Assignement operator called");
	return (*this);
}

// A better constructor
Span::Span(int first, int last, int jump)
{
	int f, l;
	if (last > first)
	{
		f = first;
		l = last;
	}
	else
	{
		f = last;
		l = first;
	}
	_n_ints = std::abs((last - first) / jump);
	_vector.reserve(_n_ints);
	for (int i = f; i < l; i += jump)
		_vector.push_back(i);
	_n_contents = _n_ints;
	//ft_msg("Span has been constructed with range");
}

// ----------------------------------- Getters ---------------------------------

unsigned int Span::getNInts(void) const
{
	return (_n_ints);
}

unsigned int Span::getNContents(void) const
{
	return (_n_contents);
}

std::vector<int> Span::getVector(void) const
{
	return (_vector);
}

// ------------------------------ Required functions ---------------------------

// Add a new number to our class
void Span::addNumber(int n)
{
	if (_vector.size() >= _n_ints || _n_contents >= _n_ints)
		throw(std::out_of_range("Cannot add any more elements"));
	_vector.push_back(n);
	_n_contents++;
}

void	Span::addNumber(my_iter start, my_iter end)
{
	// Avoid the infinite loop
	if (end < start)
		return ;
	for (my_iter i = start; i != end; i++)
		addNumber(*i);
}

// Returns the longest span
// Using min/max_element from STL
int Span::longestSpan(void)
{
	if (_n_contents == 0 || _n_contents == 1)
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int longuest_span = *max - *min;
	return (longuest_span);
}

// Returns the shortest span
// Use sort and max algorithms from STL
int Span::shortestSpan(void)
{
	if (_n_contents == 0 || _n_contents == 1)
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int shortest_span = *max;

	std::vector<int> v = _vector;
	std::sort(v.begin(), v.end());
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (i && std::abs(v[i] - v[i - 1]) < shortest_span)
			shortest_span = std::abs(v[i] - v[i - 1]);
	}
	return (shortest_span);
}

// << operator overload (not a member function!)
std::ostream & operator<<( std::ostream & o, Span const & rhs)
{
	std::cout << "Span contents: ";
	for (unsigned int i = 0; i < rhs.getNContents(); i++)
		std::cout << (rhs.getVector())[i] << " ";
	std::cout << std::endl;
	return (o);
}