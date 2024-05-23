/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:36:21 by mmomeni           #+#    #+#             */
/*   Updated: 2024/05/19 18:13:50 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <string> // stoi
#include <iostream>
#include <stdexcept>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{

    if (argc == 1)
    {
        std::cerr << "Provide the numbers to sort\n";
        return (1);
    }
    std::vector<int> nums;
    for (int i = 1; i < argc; i++)
    {
        try
        {
            int n = std::stoi(argv[i]);
            if (n < 0)
                throw std::invalid_argument("Negative numbers are not allowed");
            nums.push_back(n);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error on parsing: " << e.what() << std::endl;
            return (1);
        }
    }
    std::cout << "Before:\t";
    for (size_t i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;

    PmergeMe<std::vector<int>> p;
    clock_t s1 = clock();
    std::vector<int> vecSorted = p.sort(nums);
    clock_t e1 = clock();

    PmergeMe<std::deque<int>> p2;
    clock_t s2 = clock();
    std::deque<int> deqSorted = p2.sort(nums);
    clock_t e2 = clock();

    std::cout << "After:\t";
    for (size_t i = 0; i < vecSorted.size(); i++)
        std::cout << vecSorted[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << nums.size() << " elements with std::vector: " << (e1 - s1) * 1e6 / CLOCKS_PER_SEC << "µs" << std::endl;
    std::cout << "Time to process a range of " << nums.size() << " elements with std::deque: " << (e2 - s2) * 1e6 / CLOCKS_PER_SEC << "µs" << std::endl;
    return (0);
}
