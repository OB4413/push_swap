/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_the_arg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:15:22 by obarais           #+#    #+#             */
/*   Updated: 2025/01/09 11:24:01 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_strdup_me(const char *s1)
{
	int		i;
	char	*p;

	i = ft_strlen(s1);
	p = ft_calloc((i + 2), sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, i);
	p[i] = ' ';
	i++;
	p[i] = '\0';
	return (p);
}

static char	*ft_strjoin_me(char const *s1, char const *s2)
{
	char	*p;
	size_t	j;
	size_t	k;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup_me(s2));
	if (s2 == NULL)
		return (ft_strdup_me(s1));
	p = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	j = 0;
	k = 0;
	if (p == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		p[j] = s1[j];
		j++;
	}
	p[j++] = ' ';
	while (s2[k] != '\0')
		p[j++] = s2[k++];
	p[j] = '\0';
	return (p);
}

char	*ft_join(char **s, int ac)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	str = NULL;
	tmp = NULL;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin_me(str, s[i]);
		free(tmp);
		i++;
	}
	return (str);
}
