/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:36:37 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/18 10:57:29 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>
# include <cmath>

class Span
{
	public:
		// Canonic class methods
		Span(unsigned int n_ints);
		~Span();
		Span(Span const & ref);
		Span const & operator=(Span const & ref);

		// Getters
		unsigned int		getNInts( void );
		std::vector<int>	getVector( void );

		// Required functions
		void	addNumber( int n );
		int		longestSpan( void );
		int		shortestSpan( void );
		

	private:
		unsigned int		_n_ints;
		std::vector<int>	_vector;
};
#endif