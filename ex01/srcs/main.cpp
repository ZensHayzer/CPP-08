/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:16:40 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/24 18:26:55 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "stdlib.h"
#include "time.h"

int main()  {
    Span    sp;
    
    srand(time(NULL));
    
    std::cout << "Test with empty span : " << std::endl;
    
    try
    {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nTest with 10 000 numbers : " << std::endl;

    Span    sp1(10000);
    
    for (int i = 0; i < 10000; i++)
    {
        sp1.addNumber(rand() % 1000000);
    }
    
    try
    {
        std::cout << sp1.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << sp1.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nTest with a small span : " << std::endl;

    Span    sp2(5);
    sp2.addNumber(15);
    sp2.addNumber(23);
    sp2.addNumber(57);
    sp2.addNumber(32);

    try
    {
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nMultiple insert function : " << std::endl;
    
    Span    spMulti(10);
    Span    spMulti1(10);
    
    for (int i = 0; i < 10; i++)
    {
        spMulti.addNumber(rand() % 1000000);
    }
    
    std::vector<int>    tmp = spMulti.getVec();

    try
    {
        spMulti1.addMultipleNumbers(tmp.begin(), tmp.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::vector<int>    tmp1 = spMulti1.getVec();

    std::cout << "\nspMulti : " << std::endl;
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)    {
        std::cout << *it << std::endl;
    }

    std::cout << "\nspMulti1 : " << std::endl;
    for (std::vector<int>::iterator it = tmp1.begin(); it != tmp1.end(); ++it)    {
        std::cout << *it << std::endl;
    }
    
    std::cout << "\nCopy testing : " << std::endl;

    Span    sp3 = sp2;
    
    try
    {
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << sp3.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nTest out of range Span : " << std::endl;

    Span    sp4;

    try
    {
        sp4.addNumber(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nSubject tests : " << std::endl;
    
    Span sp5 = Span(5);
    sp5.addNumber(6);
    sp5.addNumber(3);
    sp5.addNumber(17);
    sp5.addNumber(9);
    sp5.addNumber(11);
    std::cout << sp5.shortestSpan() << std::endl;
    std::cout << sp5.longestSpan() << std::endl;
}