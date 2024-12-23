/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:18 by obarais           #+#    #+#             */
/*   Updated: 2024/12/23 10:43:55 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

typedef struct l_stack
{
    int   content;
    struct l_stack  *next;
}   t_stack;

t_stack *creat_stack(t_stack **a, char **av);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_atoi(const char *str);
void    swap_a(t_stack **a);
void    push_ab_choose(t_stack **ab1, t_stack **ab2);
void    rotate_ab(t_stack **ab);
void    rr_ab(t_stack **a, t_stack **b);
void    reverse_r_ab(t_stack **ab);
void    rrr_ab(t_stack **a, t_stack **b);

#endif