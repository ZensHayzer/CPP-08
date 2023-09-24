/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:38:45 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/24 18:12:31 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)    {
    
}

Span::Span(unsigned int N) : _N(N)  {
    
}

Span::Span(Span const & src)    {
    *this = src;
}

Span::~Span()   {
    
}

Span    &Span::operator=(Span const & src)  {
    std::vector<int> tmp = src.getVec();
    
    if (this != &src)   {
        _N = src._N;
        for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)  {
            _vec.push_back(*it);
        }
    }
    
    return (*this);
}

std::vector<int>    Span::getVec() const  {
    return (_vec);
}

void    Span::addNumber(int const & nb) {
    if (_vec.size() < _N)
        _vec.push_back(nb);
    else
        throw IsFull();
}

int Span::between(int nb1, int nb2) {
    if (nb1 > nb2)
        return (nb1 - nb2);
    else if (nb1 < nb2)
        return (nb2 - nb1);
    else
        return (0);
}

int Span::shortestSpan()    {
    if (_vec.size() > 1)    {
        int ret = between(*_vec.begin(), *(_vec.begin() + 1));
        
        for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)   {
            for (std::vector<int>::iterator it1 = _vec.begin(); it1 != _vec.end(); ++it1)    {
                if (it != it1 && between(*it, *it1) < ret)
                    ret = between(*it, *it1);
            }
        }
        return (ret);
    }
    else
        throw NotEnought();
}

int Span::longestSpan()    {
    if (_vec.size() > 1)    {
        int ret = between(*_vec.begin(), *(_vec.begin() + 1));
        
        for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)   {
            for (std::vector<int>::iterator it1 = _vec.begin(); it1 != _vec.end(); ++it1)    {
                if (it != it1 && between(*it, *it1) > ret)
                    ret = between(*it, *it1);
            }
        }
        return (ret);
    }
    else
        throw NotEnought();
}

void    Span::addMultipleNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end)    {
    _vec.insert(_vec.end(), start, end);
}