/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:27:25 by aboulakr          #+#    #+#             */
/*   Updated: 2025/04/15 20:23:36 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>


class BitcoinExchange
{
    private:
        std::multimap<std::string, float> data_base;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &src);
        void readDataBase(const std::string &filename);
        void readInputFile(const std::string &filename);
        bool alldigits(const std::string &str) const;
        bool isvalid(const std::string &str, const std::string &line) const;
};