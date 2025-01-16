/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:30:31 by obarais           #+#    #+#             */
/*   Updated: 2025/01/16 10:47:13 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 5

typedef struct l_stack
{
	long			content;
	struct l_stack	*next;
}					t_stack;

t_stack				*creat_stack(t_stack **a, char **av);
int					ft_do_option(t_stack **a, t_stack **b);
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
int					*ft_sort_arr(t_stack *a, int size);
int					check_empty(char **av, int ac);
void				put_big_in_the_top(t_stack **b, t_stack **a);
int					check_dable_int(t_stack **a);
char				*get_next_line(int fd);
void				free_stack_arr(t_stack **a, char **arr, char ***av);

#endif