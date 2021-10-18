/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:37:10 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/18 10:58:39 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "span.hpp"

// --------------------------- Canonic class functions ------------------------

static void ft_msg(std::string str)
{
	std::cout << str << std::endl;
}

Span::Span(unsigned int n_ints) : _n_ints(n_ints)
{
	ft_msg("Span has been constructed");
}

Span::~Span()
{
	ft_msg("Span has been destroyed");
}

Span::Span(Span const & ref) : _n_ints(ref._n_ints), _vector(ref._vector)
{
	ft_msg("Span has been constructed by copy");
}

Span const & Span::operator=(Span const & ref)
{
	this->_n_ints = ref._n_ints;
	this->_vector = ref._vector;
	ft_msg("Assignement operator called");
	return (*this);
}


// ----------------------------------- Getters ---------------------------------

unsigned int Span::getNInts( void )
{
	return (_n_ints);
}

std::vector<int>	Span::getVector( void )
{
	return (_vector);
}


// ------------------------------ Required functions ---------------------------

// Add a new number to our class
void	Span::addNumber( int n )
{
	if (_vector.size() >= _n_ints)
		throw(std::out_of_range("Cannot add any more elements"));
	_vector.push_back( n );
}

// Returns the longest span
// Using min/max_element from STL
int	Span::longestSpan( void )
{
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int	longuest_span = *max - *min;
	return (longuest_span);
}

// Returns the shortest span
// Use sort and max algorithms from STL
int	Span::shortestSpan( void )
{
	if (_vector.size() == 0 || _vector.size() == 1)
		return (0);
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int	shortest_span = *max;

	std::vector<int>	v = _vector;
	std::sort(v.begin(), v.end());
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (i && std::abs(v[i] - v[i - 1]) < shortest_span)
			shortest_span = std::abs(v[i] - v[i - 1]);
	}
	return (shortest_span);
}