/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:30:00 by obarais           #+#    #+#             */
/*   Updated: 2025/01/10 12:32:14 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	else_1(int i)
{
	write(1, "Error\n", 6);
	return (i);
}

static int	execute_command(char *p, t_stack **a, t_stack **b)
{
	if (ft_strncmp(p, "sa\n", ft_strlen(p)) == 0)
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
		return (else_1(1));
	return (0);
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
		if (execute_command(p, a, b) == 1)
		{
			free(p);
			return (1);
		}
		free(p);
	}
	return (0);
}

static void	creat_dable_do_option(t_stack **a, t_stack **b, char ***av)
{
	if (creat_stack(&(*a), *av) == NULL)
		return ;
	if (check_dable_int(&(*a)) == 1)
		return ;
	if (ft_do_option(&(*a), &(*b)) == 0)
	{
		if (check_sort(*a) == 0 && *b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
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
	creat_dable_do_option(&a, &b, &av);
	free_stack_arr(&a, &arr, &av);
	return (0);
}
