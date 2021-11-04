/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldanwell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:06 by ldanwell          #+#    #+#             */
/*   Updated: 2021/07/10 17:07:07 by ldanwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	cpy_len;
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		cpy_len = 0;
	else if (start + len > s_len)
		cpy_len = s_len - start;
	else
		cpy_len = len;
	ret = ft_calloc(cpy_len + 1, sizeof(*ret));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < cpy_len)
	{
		ret[i] = s[start + i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
