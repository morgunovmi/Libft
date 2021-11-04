/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldanwell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:06 by ldanwell          #+#    #+#             */
/*   Updated: 2021/07/10 17:07:07 by ldanwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			l;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc == 0)
	{
		while (*s)
			++s;
		return ((char *)s);
	}
	l = ft_strlen(s);
	while (l--)
	{
		if (s[l] == uc)
		{
			return ((char *)(s + l));
		}
	}
	return (0);
}
