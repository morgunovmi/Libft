/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldanwell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:06 by ldanwell          #+#    #+#             */
/*   Updated: 2021/07/10 17:07:07 by ldanwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_chars(int n)
{
	size_t	num_chars;

	num_chars = 0;
	if (n < 0)
	{
		n *= -1;
		++num_chars;
	}
	while (n)
	{
		n = n / 10;
		++num_chars;
	}
	return (num_chars);
}

static void	ft_reverse_string(char *start, char *end)
{
	char	*a;
	char	*b;	
	char	tmp;

	a = start;
	b = end - 1;
	while (b > a)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b--;
	}
}

static void	ft_handle_neg(int *n, int *is_neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*is_neg = 1;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	int		is_neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = ft_calloc(ft_count_chars(n) + 1, sizeof(*res));
	if (!res)
		return (NULL);
	i = 0;
	is_neg = 0;
	ft_handle_neg(&n, &is_neg);
	while (n)
	{
		res[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_neg)
		res[i++] = '-';
	res[i] = '\0';
	ft_reverse_string(res, res + ft_strlen(res));
	return (res);
}
