/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldanwell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:06 by ldanwell          #+#    #+#             */
/*   Updated: 2021/07/10 17:07:07 by ldanwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include <stdlib.h>

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i] != c && s[i])
			++num;
		while (s[i] != c && s[i])
			++i;
	}
	return (num);
}

static void	*free_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
	return (NULL);
}

static int	ft_split_strings(char const *cur, char c,
		size_t num_strs, char **ret)
{
	char	*delimeter;
	size_t	i;

	i = 0;
	delimeter = NULL;
	while (i < num_strs)
	{
		delimeter = ft_strchr(cur, c);
		if (!delimeter)
			break ;
		ret[i] = ft_substr(cur, 0, delimeter - cur);
		if (!ret[i])
			return (1);
		++i;
		cur = delimeter;
		while (*cur == c)
			++cur;
	}
	if (!delimeter && *cur != 0)
	{
		ret[i] = ft_substr(cur, 0, ft_strlen(cur));
		if (!ret[i])
			return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*cur;
	size_t	num_strs;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0)
		return ((char **)ft_calloc(1, sizeof(char *)));
	num_strs = ft_count_strs(s, c);
	ret = ft_calloc(num_strs + 1, sizeof(*ret));
	if (!ret)
		return (NULL);
	cur = (char *)s;
	while (*cur == c)
		++cur;
	if (ft_split_strings(cur, c, num_strs, ret) != 0)
		return (free_array(ret));
	ret[num_strs] = 0;
	return (ret);
}
