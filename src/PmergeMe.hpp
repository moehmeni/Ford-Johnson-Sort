/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:57:39 by mmomeni           #+#    #+#             */
/*   Updated: 2024/05/19 18:06:52 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <utility> // make_pair, swap

template <typename T>
class PmergeMe
{
private:
    PmergeMe(const PmergeMe &src) { *this = src; };
    PmergeMe &operator=(const PmergeMe &rhs)
    {
        if (this != &rhs)
            *this = rhs;
        return (*this);
    };

public:
    PmergeMe(){};
    ~PmergeMe(){};
    

    T sort(std::vector<int> &v) const
    {
        std::vector<std::pair<int, int> > pairs;
        T s; // contains the bigger nums of each pair
        T jacobsthal;
        for (size_t i = 0; i < v.size(); i += 2)
        {
            if (i + 1 < v.size())
            {
                std::pair<int, int> p = std::make_pair(v[i], v[i + 1]);
                if (p.first < p.second)
                    std::swap(p.first, p.second); // sort the pair
                pairs.push_back(p);
                s.push_back(p.first); // append the bigger
            }
            else
                break; // leave the last element
        }
        if (v.size() % 2 > 0)
            s.push_back(v.back());     // append the last element
        std::sort(s.begin(), s.end()); // sort s
        jacobsthal.push_back(0);
        jacobsthal.push_back(1);
        while (jacobsthal.back() < static_cast<int>(s.size()))
            jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
        for (size_t i = 0; i < pairs.size(); i++)
        {
            for (size_t j = 0; j < jacobsthal.size(); j++)
            {
                int k = jacobsthal[j];
                if (k >= static_cast<int>(s.size()))
                    k = s.size() - 1;
                if (pairs[i].second < s[k])
                {
                    while (k >= 0 && pairs[i].second < s[k])
                        k--; // find the right place to insert
                    s.insert(s.begin() + k + 1, pairs[i].second);
                    break;
                }
                if (pairs[i].second > s[s.size() - 1]) // if the num is bigger than all the elements
                    s.push_back(pairs[i].second);
            }
        }
        return (s);
    };
};
