/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:09:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/17 17:38:33 by ysoroko          ###   ########.fr       */
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
template< typename T>
int easyfind(T const& t, int n)
{
	// find returns the iterator to the element found or the last element's iterator
	return (std::find(t.begin(), t.end(), n) != t.end() ?
			*(std::find(t.begin(), t.end(), n)) : 
			throw(std::out_of_range("Element not found in given range")));
}


#endif