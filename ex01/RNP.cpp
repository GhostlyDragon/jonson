/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:11:31 by aboulakr          #+#    #+#             */
/*   Updated: 2025/04/20 17:13:25 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"
#include <limits>

RNP::RNP()
{
}
RNP::RNP(const RNP &src)
{
    *this = src;
}
RNP::RNP(std::string &stream)
{
    int i = -1;
    int op;
    double a = 0;
    double b = 0;
    double t = 0;

   while(stream[++i])
    {
        if (std::isdigit(stream[i])
            || stream[i] == '+' || stream[i] == '-' || stream[i] == '/'
            || stream[i] == '*')
        {
            if (!std::isspace(stream[i +1]) && stream[i +1] != '\0')
            {
                std::cerr << "Error\n";
                while(!s.empty())
                    s.pop();
                std::exit(1);
            }
        }
        if (!std::isspace(stream[i]) && !std::isdigit(stream[i])
            && stream[i] != '+' && stream[i] != '-' && stream[i] != '/'
            && stream[i] != '*')
        {
            std::cerr << "Error\n";
            while(!s.empty())
                s.pop();
            std::exit(1);
        }
        if (std::isdigit(stream[i]))
        {
            a = stream[i] - 48;
            s.push(a);
        }
        if (stream[i] == '+' || stream[i] == '-' || stream[i] == '/'
            || stream[i] == '*')
        {

            op = stream[i];   
            if (s.size() < 2 || s.empty())
            {
                std::cerr << "Error\n";
                while(!s.empty())
                    s.pop();
                std::exit(1);
            }
            else
            {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                switch(op)
                {
                    case '+': t = b + a;break;
                    case '-': t = b - a;break;
                    case '*': t = b * a;break;
                    case '/': t = b / a;break;
                }
                s.push(t);
            }
            
        }
    }
    if (!s.empty() && s.size() > 1)
    {
        std::cerr << "Error\n";
        while(!s.empty())
            s.pop();
        std::exit(1);
    }
    std::cout << t << std::endl;
}
RNP &RNP::operator=(const RNP &src)
{
    if (this != &src)
    {
        this->s = src.s;
    }
    return *this;
}

RNP::~RNP()
{
    while(!s.empty())
        s.pop();
}
