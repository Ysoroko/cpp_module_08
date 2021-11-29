/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:36:37 by ysoroko           #+#    #+#             */
/*   Updated: 2021/11/29 13:56:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm> 
# include <vector>
# include <iterator>
# include <cmath> //for abs

class Span
{
	public:
		// Canonic class methods
		Span(unsigned int n_ints);
		~Span();
		Span(Span const & ref);
		Span const & operator=(Span const & ref);

		// A better constructor
		Span(int first, int last, int jump);

		// Getters
		unsigned int		getNInts( void ) const;
		std::vector<int>	getVector( void ) const;
		unsigned int		getNContents(void) const;

		// Required functions
		void	addNumber( int n );
		int		longestSpan( void );
		int		shortestSpan( void );
		

	private:
		unsigned int		_n_ints;
		unsigned int		_n_contents;
		std::vector<int>	_vector;
};

std::ostream & operator<<( std::ostream & o, Span const & rhs);

#endif