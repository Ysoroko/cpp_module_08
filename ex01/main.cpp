/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:36:17 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/18 11:58:47 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	// Subject main
	Span	sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl; // 5 - 3 or 11 - 9 = 2
	std::cout << sp.longestSpan() << std::endl; // 17 - 3 = 14
	std::cout << "--------------------------" << std::endl;

	// My tests
	Span	sp2(1, 2000000, 10);
	std::cout << sp2.shortestSpan() << std::endl; // 10, it's in the constructor
	std::cout << sp2.longestSpan() << std::endl; // 20000 - 10 = 1999990
	std::cout << "--------------------------" << std::endl;

	Span	sp3(0);
	try
	{
		sp3.addNumber(5); // out of range exception
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "--------------------------" << std::endl;
	return (0);
}

