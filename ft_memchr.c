/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldanwell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:06 by ldanwell          #+#    #+#             */
/*   Updated: 2021/07/10 17:07:07 by ldanwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

//TODO segf when null
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*found_char;

	p = (unsigned char *)s;
	if (!s)
		*p = *(unsigned char *)s;
	found_char = NULL;
	while ((s != NULL) && (n--))
	{
		if (*p != (unsigned char)c)
			p++;
		else
		{
			found_char = p;
			break ;
		}
	}
	return (found_char);
}
