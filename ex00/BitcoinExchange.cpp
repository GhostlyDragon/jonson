/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:27:28 by aboulakr          #+#    #+#             */
/*   Updated: 2025/04/20 17:13:59 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}
BitcoinExchange::~BitcoinExchange()
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        this->data_base = src.data_base;
    }
    return *this;
}

void    BitcoinExchange::readDataBase(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open database file." << std::endl;
        std::exit(1);
    }
    std::string line;
    while(std::getline(file, line))
    {
        if (line == "date,exchange_rate")
            continue;
        size_t position = line.find(',');
        if (position == std::string::npos)
        {
            std::cout << "Error: Invalid line format in database file." << std::endl;
            std::exit(1);
        }
        float value = std::atof(line.substr(position + 1).c_str());
        data_base.insert(std::make_pair(line.substr(0, position), value));
    }
    file.close();
}
void    BitcoinExchange::readInputFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error: Could not open file." << std::endl;
        std::exit(1);
    }
    std::string line;
    while(std::getline(file, line))
    {
        size_t position = line.find('|');
        if (position == std::string::npos ||
            (position != std::string::npos && (line[position + 1] != ' ' || line[position - 1] != ' ')))
        {
            std::cout << "Error : bad input '|' => " << line << std::endl;
            continue;
        }
        //check '_'
        int k = 0;
        for (size_t i= 0; i < line.substr(0, position).length(); i++)
        {
            if (line[i] == '-')
                k++;
        }
        if (k != 2)
        {
            std::cout << "Error : bad input '-' => " << line << std::endl;
            continue;
        }
        //check date
        size_t pos1 = line.find('-');
        size_t pos2 = line.find('-', pos1 + 1);

        std::string year = line.substr(0, pos1);
        std::string month = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string day = line.substr(pos2 + 1, position - pos2 - 2);
        
        if (year.length() != 4 || month.length() != 2 || day.length() != 2 ||
            !alldigits(year) || !alldigits(month) || !alldigits(day))
        {
            std::cout << "Error : bad input 'Y-M-D' => " << line << std::endl;
            continue;
        }

        int monthInt = std::atoi(month.c_str());
        int dayInt = std::atoi(day.c_str());

        if (monthInt < 1 || monthInt > 12 || dayInt < 1 || dayInt > 31)
        {
            std::cout << "Error : bad input => " << line << std::endl;
            continue;
        }
        //check value
        std::string value = line.substr(position + 2);
        if (!isvalid(value, line))
        {
            continue;
        }
        float val = std::atof(value.c_str());
        if (val < 0 || val > 1000)
        {
            if (val < 0)
                std::cout << "Error : not a positive number " << std::endl;
            else
                std::cout << "Error : too large number " << std::endl;
            continue;
        }
        size_t pos_space = line.find(' ');
        std::multimap<std::string, float>::iterator it = data_base.lower_bound(line.substr(0, pos_space));
        if (it->first == line.substr(0, pos_space))
        {
            // std::cout << it->first << " => " << it->second << std::endl;
            std::cout << line.substr(0, pos_space) << " => " << val << " = " << val * it->second << std::endl;
        }
        else
        {
            if (it != data_base.begin())
                --it;
            // std::cout << it->first << " => " << it->second << std::endl;
            std::cout << line.substr(0, pos_space) << " => " << val << " = " << val * it->second << std::endl;
        }
    }
}

bool BitcoinExchange::alldigits(const std::string &str) const
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::isvalid(const std::string &str, const std::string &line) const
{
    int minisign = 0;
    int point = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
            minisign++;
        if (str[i] == '.')
            point++;
    }

    if (minisign > 1 || point > 1)
    {
        std::cerr << "Error : bad input => " << line << std::endl;
        return false;
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-')
        {
            std::cerr << "Error : bad input => " << line << std::endl;
            return false;
        }
    }
    return true;
}