/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:36:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/11/29 14:50:14 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

void	ft_print_line( void )
{
	std::cout << "--------------------------------------------------------" << std::endl;
}

int main(void)
{
	// Subject main
	Span	sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	ft_print_line();
	std::cout << sp;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 5 - 3 or 11 - 9 = 2
	std::cout << "Longest span:  " << sp.longestSpan() << std::endl; // 17 - 3 = 14
	ft_print_line();

	// My tests
	// ---------------------------------------------
	// A "Span" which has elements:
	// - starting at '0'
	// - going up to '10'
	// - with a difference of '1' between each element
	Span	sp1(1, 10, 1);
	std::cout << sp1;
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl; // 10, it's in the constructor
	std::cout << "Longest span:  " << sp1.longestSpan() << std::endl; // 2000001 - 10 = 1999990
	ft_print_line();

	// A "Span" which has elements:
	// - starting at '1'
	// - going up to '2000000'
	// - with a difference of '10' between each element
	Span	sp2(1, 2000000, 10);
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl; // 10, it's in the constructor
	std::cout << "Longest span:  " << sp2.longestSpan() << std::endl; // 2000001 - 10 = 1999990
	ft_print_line();

	Span	sp3 = Span(30);
	my_iter a = sp1.getVector().begin();
	my_iter b = sp1.getVector().end();
	// Add "1 2 3 4 5 6 7 8 9" to sp3
	sp3.addNumber(a, b);
	sp3.addNumber(a, b);
	std::cout << sp3;
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl; // 5 - 3 or 11 - 9 = 2
	std::cout << "Longest span:  " << sp3.longestSpan() << std::endl; // 17 - 3 = 14
	ft_print_line();

	// Span with max 0 elements
	Span	sp4(0);
	std::cout << sp4;
	// Add an element to it
	try
	{
		sp4.addNumber(5); // out of range exception
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	// Its shortest span
	try
	{
		sp4.shortestSpan(); // out of range exception
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	// Its longest span
	try
	{
		sp4.longestSpan(); // out of range exception
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	ft_print_line();
	return (0);
}

