/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:18 by obarais           #+#    #+#             */
/*   Updated: 2025/01/12 23:08:03 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct l_stack
{
	long			content;
	struct l_stack	*next;
}					t_stack;

t_stack				*creat_stack(t_stack **a, char **av);
void				swap_a_b(t_stack **ab);
void				swap_a_and_b(t_stack **a, t_stack **b);
void				push_ab_choose(t_stack **ab1, t_stack **ab2);
void				rotate_ab(t_stack **ab);
void				rr_ab(t_stack **a, t_stack **b);
void				reverse_r_ab(t_stack **ab);
void				rrr_ab(t_stack **a, t_stack **b);
int					ft_size_a(t_stack **a);
char				*ft_join(char **s, int ac);
int					check_sort(t_stack *a);
int					error_stack(char **av);
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);
void				sort_stack(t_stack **a, t_stack **b);
int					*ft_sort_arr(t_stack *a, int size);
int					*ft_smol_big(int size, int *arr);
void				algorithm_sort(t_stack **a, t_stack **b);
int					ft_calcul_end(int size);
int					check_empty(char **av, int ac);
void				put_big_in_the_top(t_stack **b);
int					position_big_int(t_stack **a);
int					check_dable_int(t_stack **a);
void				free_stack_arr(t_stack **a, char **arr, char ***av);

#endif