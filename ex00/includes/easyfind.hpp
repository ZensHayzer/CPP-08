/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:16:42 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/24 15:22:27 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>

class NotFind : public std::exception {
    public:
        virtual const char* what() const throw()  {
            return ("Arg not found in container.");
        }
};

template <typename T>
typename T::iterator    easyfind(T &vec, int nb) {
    typename T::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)  {
        if (*it == nb)
            return (it);
    }
    throw NotFind();
}


#endif