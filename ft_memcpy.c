/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldanwell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:06 by ldanwell          #+#    #+#             */
/*   Updated: 2021/07/10 17:07:07 by ldanwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*c_dest;
	const char	*c_src;	


	if (!dest && !src)
		return (NULL);
	c_dest = (char *)dest;
	c_src = (const char *)src;
	while (n--)
	{
		*(c_dest++) = *(c_src++);
	}
	return (dest);
}
