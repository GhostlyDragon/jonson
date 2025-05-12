/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:39:53 by aboulakr          #+#    #+#             */
/*   Updated: 2025/04/20 17:12:06 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>


class RNP
{
    private:
        std::stack<double > s;
        RNP();
    public:
        RNP(const RNP &src);
        RNP(std::string &stream);
        RNP &operator=(const RNP &src);
        ~RNP();
};