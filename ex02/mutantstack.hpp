/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:59:38 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/18 12:29:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef	T*	iterator;
		typedef	T const *	const_iterator;
		//using iterator = T *;

		//using const_iterator = T const *;
		iterator begin() { return (&this->top()); }
		iterator end() { return (&(this->top()) + this->size()); }
		const_iterator begin() const { return this->top(); }
		const_iterator end() const { return this->top() + this->size(); }
};

#endif