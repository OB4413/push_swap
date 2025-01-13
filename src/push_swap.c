/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:25 by obarais           #+#    #+#             */
/*   Updated: 2025/01/12 21:51:58 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_arr(t_stack **a, char **arr, char ***av)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	free(*arr);
	while ((*av)[i])
	{
		free((*av)[i]);
		i++;
	}
	free(*av);
}

void	sort_algo(t_stack **a, t_stack **b)
{
	if (check_sort(*a) == 1)
	{
		if (ft_size_a(a) == 2)
			sort_2(&(*a));
		else if (ft_size_a(a) == 3)
			sort_3(&(*a));
		else if (ft_size_a(a) == 4)
			sort_4(&(*a), &(*b));
		else if (ft_size_a(a) == 5)
			sort_5(&(*a), &(*b));
		else
			sort_stack(&(*a), &(*b));
	}
}

static	int	creat_stack_check_dable_int(t_stack **a, char **av)
{
	if (creat_stack(&(*a), av) == NULL)
		return (1);
	if (check_dable_int(&(*a)) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*arr;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (check_empty(av, ac) == 1)
		return (1);
	arr = ft_join(av, ac);
	av = ft_split(arr, ' ');
	if (creat_stack_check_dable_int(&a, av) == 1)
	{
		free_stack_arr(&a, &arr, &av);
		return (1);
	}
	sort_algo(&a, &b);
	free_stack_arr(&a, &arr, &av);
	return (0);
}
