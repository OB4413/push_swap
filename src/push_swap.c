/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:25 by obarais           #+#    #+#             */
/*   Updated: 2025/01/06 12:32:06 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    char *arr;
    (void)b;

    if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
        return (1);
    arr = ft_join(av, ac);
    av = ft_split(arr, ' ');
    if (creat_stack(&a, av) == NULL)
        return (1);
    if (check_sort(a) == 0)
    {
        if (ft_size_a(&a) == 2)
            sort_2(&a);
        else if (ft_size_a(&a) == 3)
            sort_3(&a);
        else
            sort_stack(&a, &b);
    }
    
    return (0);
}