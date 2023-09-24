/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:11:48 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/24 20:34:43 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T> class MutantStack : public std::stack<T>    {

    public:
        typedef typename std::stack<T>::container_type::iterator    iterator;
        typedef typename std::stack<T>::container_type::const_iterator    const_iterator;
        
        iterator    begin() {
            return (std::stack<T>::c.begin());
        }
        
        iterator    end() {
            return (std::stack<T>::c.end());
        }

        const_iterator    begin() const {
            return (std::stack<T>::c.begin());
        }
        
        const_iterator    end() const {
            return (std::stack<T>::c.end());
        }
};

#endif