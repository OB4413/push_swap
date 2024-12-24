/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:25 by obarais           #+#    #+#             */
/*   Updated: 2024/12/24 18:37:42 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int     size;
    int     i;

    if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
        return (1);
    i = 0;
    if (ac == 2)
        av = ft_split(av[1], ' ');
    creat_stack(&a, av);
    size = ft_size_a(&a);
    while (i < size)
    {
        algorithm_sort(&a, &b);
        i++;
    }
    i = 0;
    while (i < size)
    {
        push_ab_choose(&b, &a);
        write(1, "pa\n", 3);
        i++;
    }
    return (0);
}