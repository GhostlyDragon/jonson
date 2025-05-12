/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:27:30 by aboulakr          #+#    #+#             */
/*   Updated: 2025/04/15 20:21:15 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    if (ac == 2)
    {
        BitcoinExchange bitcoinExchange;
        bitcoinExchange.readDataBase("data.csv");
        bitcoinExchange.readInputFile(av[1]);
    }
    else
    {
        std::cerr << "Error: too many arguments" << std::endl;
        return 1;
    }
    return 0;
}