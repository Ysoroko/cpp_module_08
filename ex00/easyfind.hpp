/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:09:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/18 11:45:43 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <iterator>
# include <vector>
# include <array>

// T is a container of int
// Find the the first occurrence of the second parameter in the first parameter
template< typename T >
int easyfind(T const& t, int n)
{
	typename T::const_iterator end = t.end();

	// STL algorithm "find" returns the iterator to the element found if it finds it
	// otherwise it will return the t.end() pointer (a pointer to the element after last)
	typename T::const_iterator it = std::find(t.begin(), end, n);

	return (it == end ? throw(std::out_of_range("Element not found in given range")) : *it);
}


#endif