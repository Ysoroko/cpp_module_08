/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:00:03 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/18 15:26:21 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
	// --------------------------------- INTS ---------------------------------
	std::cout << std::endl << "INTS:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	MutantStack<int> mstack;
	mstack.push(5); 
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl; // 17 at the top
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl; // 1 because 17 popped
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(-489);
	mstack.push(0);
	mstack.push(0);
	mstack.push(192);
	MutantStack<int>::iterator it = mstack.begin(); // stack is 5 3 5 737 -489 0 0 192
	std::cout << "Begin: " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl << "All the values in the stack: " << std::endl;
	std::cout << "--------------------------" << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl << std::endl << std::endl;

	// ----------------------------------- CHARS ------------------------------
	std::cout << "CHARS:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	MutantStack<char>	mcstack;
	mcstack.push('A'); 
	mcstack.push('B');
	std::cout << "Top: " << mcstack.top() << std::endl; // 17 at the top
	mcstack.pop();
	std::cout << "Size: " << mcstack.size() << std::endl; // 1 because 17 popped
	mcstack.push('C');
	mcstack.push('D');
	mcstack.push('E');
	mcstack.push('F');
	mcstack.push('G');
	mcstack.push('H');
	mcstack.push('I');
	MutantStack<char>::iterator it2 = mcstack.begin(); // stack is A C D E F G H I
	std::cout << "Begin: " << *it2 << std::endl;
	MutantStack<char>::iterator it2e = mcstack.end();
	++it2;
	--it2;
	std::cout << std::endl << "All the values in the stack: " << std::endl;
	std::cout << "--------------------------" << std::endl;
	while (it2 != it2e)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
}