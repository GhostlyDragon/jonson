/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:28:59 by aboulakr          #+#    #+#             */
/*   Updated: 2025/05/12 05:17:18 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <cctype>


void    f()
{
    system("leaks PmergeMe");
}
bool ft_isdigit(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    // atexit(f);
    if (ac == 1)
        return 0;
    else
    {
        int i = 0;
        std::string stream;
        PmergeMe  merge;
        while(av && av[++i])
        {
            stream = av[i];
            int i = -1;
            long val = 0;
            bool lock = 0;
            bool flag = 0;
            while(stream[++i])
            {
                if (!std::isdigit(stream[i]) && !std::isspace(stream[i]) && stream[i] != '\n')
                {
                    std::cout << '\'' << stream[i] << std::endl;
                    std::cerr << "Error1: Wrong stream\n";
                    return 1;
                }
                else
                {
                    if (std::isspace(stream[i]))
                    {
                        if (lock == 0 && flag == 1)
                        {
                            merge.insert(static_cast<int>(val));
                            val = 0;
                            lock = 1;
                        }
                        continue;
                    }
                    else
                    {
                        flag = 1;
                        val = val*10 + stream[i] - 48;
                        if (std::isspace(stream[i + 1]))
                            lock = 0;
                        if (val < 0 || val < -2147483648 || val > 2147483647)
                        {
                            std::cerr << "Error3: overflows\n";
                            return 1;
                        }
                        // std::cout << "val2-> " << val << '\n';
                    }
                }
            }
            merge.insert(static_cast<int>(val));
        }
        std::vector<int > sorted_list;
        // clock_t start = std::clock();
        sorted_list = recursion(merge.getVectors(), merge.vectors.size(), 1);
        // merge_insertion(sorted_list);
        merge.print(sorted_list);
        std::cout << "comparisons: " << comparisons << std::endl;
        if (!is_is_sorted(sorted_list))
        {
            std::cout << "Error4: not sorted : " ;
            merge.print(merge.getVectors());
            std::cout << std::endl;
            return 1;
        }
        // merge.print(merge.getVectors());
        // clock_t end = std::clock();
        // double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        // std::cout << duration;
        // std::cout << "Time to process a range of " << ac - 1 << " elements: ";
    }
    return 1;
}
