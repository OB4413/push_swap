/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:25 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 13:03:24 by obarais          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*arr;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (check_empty(av, ac) == 1)
		return (1);
	arr = ft_join(av, ac);
	av = ft_split(arr, ' ');
	if (creat_stack(&a, av) == NULL)
	{
		free_stack_arr(&a, &arr, &av);
		return (1);
	}
	if (check_dable_int(&a) == 1)
	{
		free_stack_arr(&a, &arr, &av);
		return (1);
	}
	if (check_sort(a) == 1)
	{
		if (ft_size_a(&a) == 2)
			sort_2(&a);
		else if (ft_size_a(&a) == 3)
			sort_3(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack_arr(&a, &arr, &av);
	return (0);
}
