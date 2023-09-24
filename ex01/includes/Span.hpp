/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:35:12 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/24 18:10:35 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span  {
    public:
        Span();
        Span(unsigned int N);
        Span(Span const & src);
        ~Span();
        
        Span    &operator=(Span const & src);

        std::vector<int>    getVec() const;
        
        void    addNumber(int const & nb);
        int     between(int nb1, int nb2);
        int     shortestSpan();
        int     longestSpan();
        void    addMultipleNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);

        class IsFull : public std::exception {
            public:
                virtual const char* what() const throw()  {
                    return ("Span is full.");
                }
        };
    
        class NotEnought : public std::exception {
            public:
                virtual const char* what() const throw()  {
                    return ("Not enought numbers in Span.");
                }
        };
        
    private:
        unsigned int        _N;
        std::vector<int>    _vec;
        
};

#endif