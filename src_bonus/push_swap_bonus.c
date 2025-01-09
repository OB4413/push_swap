/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:30:00 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 19:03:07 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_do_option(t_stack **a, t_stack **b)
{
	char	*p;

	p = NULL;
	while (1)
	{
		p = get_next_line(0);
		if (p == NULL)
			break ;
		else if (ft_strncmp(p, "sa\n", ft_strlen(p)) == 0)
			swap_a_b(&(*a));
		else if (ft_strncmp(p, "sb\n", ft_strlen(p)) == 0)
			swap_a_b(&(*b));
		else if (ft_strncmp(p, "ss\n", ft_strlen(p)) == 0)
			swap_a_and_b(&(*a), &(*b));
		else if (ft_strncmp(p, "pa\n", ft_strlen(p)) == 0)
			push_ab_choose(&(*b), &(*a));
		else if (ft_strncmp(p, "pb\n", ft_strlen(p)) == 0)
			push_ab_choose(&(*a), &(*b));
		else if (ft_strncmp(p, "ra\n", ft_strlen(p)) == 0)
			rotate_ab(&(*a));
		else if (ft_strncmp(p, "rb\n", ft_strlen(p)) == 0)
			rotate_ab(&(*b));
		else if (ft_strncmp(p, "rr\n", ft_strlen(p)) == 0)
			rr_ab(&(*a), &(*b));
		else if (ft_strncmp(p, "rra\n", ft_strlen(p)) == 0)
			reverse_r_ab(&(*a));
		else if (ft_strncmp(p, "rrb\n", ft_strlen(p)) == 0)
			reverse_r_ab(&(*b));
		else if (ft_strncmp(p, "rrr\n", ft_strlen(p)) == 0)
			rrr_ab(&(*a), &(*b));
		else
		{
			ft_printf("Error\n");
			free(p);
			return (1);
		}
		free(p);
	}
	return (0);
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
	if (ft_do_option(&a, &b) == 0)
	{
		if (check_sort(a) == 0 && b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_stack_arr(&a, &arr, &av);
	return (0);
}
