/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:45:24 by aboulakr          #+#    #+#             */
/*   Updated: 2025/04/20 17:15:14 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"
#include <string>


int main(int ac, char **av)
{
    if (ac == 1)
        return 0;
    if (ac == 2)
    {
        std::string stream = av[1];

        if (stream.size() < 2)
        {
            std::cerr << "Erorr\n";
            return 1;
        }
        RNP  polish(stream);
    }
    else
        return 1;
}