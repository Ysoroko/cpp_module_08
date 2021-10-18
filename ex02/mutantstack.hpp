/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:59:38 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/18 15:14:58 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef	T*	iterator;
		typedef	T const *	const_iterator;

		iterator begin()
		{
			std::vector<T>	v;
			T				top;
			iterator		ret;
			int				n = 0;
			while (!this->empty())
			{
				top = this->top();
				v.push_back(top);
				this->pop();
				n++;
				
			}
			this->push(v[n - 1]);
			n--;
			ret = &(this->top());
			while (n--)
				this->push(v[n]);
			return (ret);
		} //5 3 5 737 0

		iterator end() { return (&this->top() + 1); }
};

#endif