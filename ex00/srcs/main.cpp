/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:31:42 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/24 16:36:17 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()  {
    
    std::vector<int>::iterator  ret;
    std::vector<int>            vec;
    
    try
    {
        ret = easyfind(vec, 32);
        std::cout << *ret << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    vec.push_back(18);
    vec.push_back(32);
    
    try
    {
        ret = easyfind(vec, 32);
        std::cout << *ret << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::vector<int>    vec1 = vec;
    
    try
    {
        ret = easyfind(vec1, 32);
        std::cout << *ret << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}