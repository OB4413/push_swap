/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:18 by obarais           #+#    #+#             */
/*   Updated: 2025/01/06 15:02:47 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stddef.h>

typedef struct l_stack
{
    int   content;
    struct l_stack  *next;
}   t_stack;

t_stack *creat_stack(t_stack **a, char **av);
size_t  ft_strlen(const char *s);
void    *ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void    swap_a_b(t_stack **ab);
void    swap_a_and_b(t_stack **a, t_stack **b);
void    push_ab_choose(t_stack **ab1, t_stack **ab2);
void    rotate_ab(t_stack **ab);
void    rr_ab(t_stack **a, t_stack **b);
void    reverse_r_ab(t_stack **ab);
void    rrr_ab(t_stack **a, t_stack **b);
int     ft_size_a(t_stack **a);
char    *ft_join(char **s, int ac);
int     check_sort(t_stack *a);
int     error_stack(char **av);
void    sort_2(t_stack **a);
void    sort_3(t_stack **a);
void    sort_stack(t_stack **a, t_stack **b);
int    *ft_sort_arr(t_stack *a, int size);
int     *ft_smol_big(int size, int *arr);
void    algorithm_sort(t_stack **a, t_stack **b, int t);
void    algorithm_sort_1(t_stack **a, t_stack **b);
int     ft_calcul_end(int size);

#endif