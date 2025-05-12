/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:23:05 by aboulakr          #+#    #+#             */
/*   Updated: 2025/05/12 06:29:47 by aboulakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <queue>

int comparisons = 0;

class PmergeMe
{
    public:
        std::vector<int> vectors;
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        void    insert(int val);
        std::vector<int> &getVectors();
        void    print(std::vector<int> vectors);
};

std::vector<int> generate_jacobsthal_numbers(int limit) {
    std::vector<int> jacobsthal_numbers;
    int previous = 1, current = 3;
    
    jacobsthal_numbers.push_back(previous);
    if (current <= limit) {
        jacobsthal_numbers.push_back(current);
    }

    while (current <= limit) {
        int next = 2 * current + 1;
        jacobsthal_numbers.push_back(next);
        previous = current;
        current = next;
    }

    return jacobsthal_numbers;
}

int jacobsthal(int index)
{
    if (index == 0)
        return 1;
    else if (index == 1)
        return 1;
    else
        return (pow(2, index) - jacobsthal(index - 1));
}

void binary_insert(std::vector<int>& main, int val)
{
    size_t left = 0;
    size_t right = main.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (val < main[mid])
            right = mid;
        else
            left = mid + 1;
    }
    main.insert(main.begin() + left, val);
}

std::vector<int> jhonson_algo(std::vector<int> &sequence, int x)
{
    std::vector<std::vector<int> > main;
    std::vector<std::vector<int> > pend;
    std::vector<int> tmp;
    std::vector<int> jacob_numbers;
    std::vector<int> jacobsthal_real_one;
    int tmp2    = 0;

    std::cout <<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<std::endl << "x-> " << x << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; i < sequence.size(); i += x)
    {
        if (i == 0)
        {
            i += x;
            continue ;
        }
        tmp2 = x;
        if (i +x > sequence.size())
        {
            tmp.clear();
            break ;
        }
        while(tmp2 > 0)
        {
            tmp.push_back(sequence[i]);
            tmp2--;
            i++;
        }
        pend.push_back(tmp);
        tmp.clear();
    }
    for(size_t i = 0; i < sequence.size(); i += x)
    {
        tmp2 = x;
        if (i == 0)
        {
            int l = 0;
            while(l < x)
            {
                tmp.push_back(sequence[l]);
                l++;
            }
            main.push_back(tmp);
            tmp.clear();
        }
        else
        {
            if (i +x > sequence.size())
            {
                tmp.clear();
                break ;
            }
            while(tmp2 > 0)
            {
                tmp.push_back(sequence[i]);
                tmp2--;
                i++;
            }
            main.push_back(tmp);
            tmp.clear();
        }
    }
    if (pend.size() == 1)
    {
        //print pend
        for (size_t i = 0; i < pend.size(); i++)
        {
            for (size_t j = 0; j < pend[i].size(); j++)
            {
                std::cout <<"pend[" <<pend[i][j] << "] ";
            }
        }
        std::cout << std::endl;
        //print main
        for (size_t i = 0; i < main.size(); i++)
        {
            for (size_t j = 0; j < main[i].size(); j++)
            {
                std::cout << "main["<<main[i][j] << "] ";
            }
        }
        std::cout << std::endl;
        int left = 0;
        int right = main.size();
        while (left < right)
        {
            int middle = (left + right) / 2;
            if (main[middle][x -1] < pend[0][x-1])
            {
                comparisons++;
                left = middle + 1;
            }
            else
            {
                comparisons++;
                right = middle;
            }
        }
        main.insert(main.begin() + left, pend[0]);
    }
    else if (!pend.empty() && pend.size() > 1)
    {
        int tmp3 = x;
        while(tmp3 > 0)
        {
            tmp.push_back(-1);
            tmp3--;
        }
        pend.insert(pend.begin(), tmp);
        tmp.clear();
        std::vector<int> jacobsthal_sequence;
        int i = 1;
        while ((size_t)jacobsthal(i) <= pend.size())
        {
            int j = jacobsthal(i);
            if (j > (int)(pend.size())) break;
            jacobsthal_sequence.push_back(j);
            jacobsthal_real_one.push_back(j);
            if (i != 0)
            {
                int prev_j = jacobsthal(i - 1);
                for (int k = j - 1; k > prev_j; --k)
                {
                    if ((int)jacobsthal_sequence.size() > (int)pend.size()) break;
                    jacobsthal_sequence.push_back(k);
                }
            }
            i++;
        }
        for (int k = 0; jacobsthal_sequence.size() < pend.size(); ++k)
        {
            if (std::find(jacobsthal_sequence.begin(), jacobsthal_sequence.end(), k) == jacobsthal_sequence.end())
            {
                if (k == 0)
                    continue ;
                jacobsthal_sequence.push_back(k);
            }
        }
        jacob_numbers = generate_jacobsthal_numbers(pend.size());
        int must_insert = 0;
        int right =0;
        size_t j = 1;
        size_t k = 1;
        int flag =0;
        //print pend
        for (size_t i = 0; i < pend.size(); i++)
        {
            for (size_t j = 0; j < pend[i].size(); j++)
            {
                std::cout <<"pend[" <<pend[i][j] << "] ";
            }
        }
        std::cout << std::endl;
        //print main
        for (size_t i = 0; i < main.size(); i++)
        {
            for (size_t j = 0; j < main[i].size(); j++)
            {
                std::cout << "main["<<main[i][j] << "] ";
            }
        }
        std::cout << std::endl;
        //print jacobsthal_sequence
        for (size_t i = 0; i < jacobsthal_sequence.size(); i++)
        {
            std::cout << "jacobsthal_sequence["<<jacobsthal_sequence[i] << "] ";
        }
        std::cout << std::endl;
        //print jacob_numbers
        for (size_t i = 0; i < jacob_numbers.size(); i++)
        {
            std::cout << "jacob_numbers["<<jacob_numbers[i] << "] ";
        }
        std::cout << std::endl;
        //print jacobsthal_real_one
        for (size_t i = 0; i < jacobsthal_real_one.size(); i++)
        {
            std::cout << "jacobsthal_real_one["<<jacobsthal_real_one[i] << "] ";
        }
        std::cout << std::endl;
        //clear jacobsthal_sequence and fill it with indices from 0 to pend.size()
        // jacobsthal_sequence.clear();
        // for (size_t i = 0; i < pend.size(); i++)
        // {
        //     jacobsthal_sequence.push_back(i);
        // }
        
        while(j < jacobsthal_sequence.size())
        {
            std::cout << "j-> " << j << std::endl;
            if (right > (int)main.size() || k >= jacob_numbers.size())
                right = main.size();
            else
                right = jacob_numbers[k];
            if (flag == 0)
            {
                if (k >= jacobsthal_real_one.size())
                    must_insert = pend.size();
                else
                    must_insert = jacobsthal_real_one[k] - jacobsthal_real_one[k -1];
                flag = 1;
            }
            if (must_insert == 0 && k <= jacob_numbers.size())
            {
                flag = 0;
                k++;
            }
            else
            {
                std::cout << "k -> " << k << std::endl;
                int left = 0;
                std::cout << "left-> " << left << " right-> " << right << std::endl;
                std::cout << "must_insert-> " << must_insert << std::endl;
                std::cout <<"need to insert-> " << pend[jacobsthal_sequence[j] -1].back() << std::endl;
                while (left < right && must_insert > 0)
                {
                    int middle = (left + right)  / 2;
                    if (main[middle].back() < pend[jacobsthal_sequence[j]-1].back())
                    {
                        comparisons++;
                        left = middle +1;
                    }
                    else
                    {
                        comparisons++;
                        right = middle;
                    }
                }
                main.insert(main.begin() + left, pend[jacobsthal_sequence[j]-1]);
                must_insert--;
                j++;
            }
        }
        jacobsthal_sequence.clear();
    }
    for (size_t i = 0; i < main.size(); i++)
    {
        for (size_t j = 0; j < main[i].size(); j++)
        {
            tmp.push_back(main[i][j]);
        }
    }
    for (size_t i = 0; i < sequence.size(); i++)
    {
        if (std::find(tmp.begin(), tmp.end(), sequence[i]) == tmp.end())
        {
            tmp.push_back(sequence[i]);
        }
    }
    main.clear();
    pend.clear();
    jacob_numbers.clear();
    jacobsthal_real_one.clear();
    return tmp;
}


std::vector<int> recursion(std::vector<int> sequence, size_t num_of_pairs, int x)
{
    if (num_of_pairs == 1 || (x > 1 && (size_t)x > sequence.size() /2))
        return sequence;
    for (size_t i = 0; i + 2 * x <= sequence.size(); i += 2 * x)
    {
        std::vector<int> group1;
        std::vector<int> group2;
        for (size_t j = i; j < i + x && j < sequence.size(); ++j)
        {
            group1.push_back(sequence[j]);
        }
        for (size_t j = i + x; j < i + 2 * x && j < sequence.size(); ++j)
        {
            group2.push_back(sequence[j]);
        }
        if (group1.back() > group2.back())
        {
            comparisons++;
            for (size_t j = 0; j < group2.size(); ++j)
                sequence[i + j] = group2[j];
            for (size_t j = 0; j < group1.size(); ++j)
                sequence[i + x + j] = group1[j];
        }
    }
    for (size_t i = 0; i < sequence.size(); i++)
    {
        std::cout << "sequence["<<sequence[i] << "] ";
    }
    std::cout << std::endl;
    sequence = recursion(sequence, num_of_pairs / 2, x*2);
    return jhonson_algo(sequence, x);
}
/* ************************************************************************** */
PmergeMe::PmergeMe()
{
    comparisons = 0;
}

void    PmergeMe::insert(int val)
{
    this->vectors.push_back(val);
}
PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->vectors = src.vectors;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    vectors.clear();
}

void    PmergeMe::print(std::vector<int> vectors)
{
    for (size_t i = 0; i < vectors.size(); i++)
        std::cout << "elemnet->[" << vectors[i] << "] ";
    std::cout << std::endl;
}
void    new_jacobsthl(std::vector<int> &jacobstal_sequence, int index)
{
    int j = 0;
    while (jacobstal_sequence[j] < index)
    {
        j++;
    }
}

std::vector<int> &PmergeMe::getVectors()
{
    return this->vectors;
}

bool is_is_sorted(std::vector<int> &sequence)
{
    for (size_t i = 0; i < sequence.size() - 1; i++)
    {
        if (sequence[i] > sequence[i + 1])
            return(std::cout << "at ["<< sequence[i] << "]"<<std::endl, false);
    }
    return true;
}