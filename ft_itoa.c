/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthongka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:25:23 by pthongka          #+#    #+#             */
/*   Updated: 2022/03/29 22:48:13 by pthongka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	div;
	int	len;

	len = 1;
	div = n / 10;
	while (div)
	{
		div = div / 10;
		len = len + 1;
	}
	if (n < 0)
		return (len + 2);
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char			*a;
	int				len;
	unsigned int	num;

	len = count_digits(n);
	a = (char *)malloc(len * sizeof(char));
	if (!a)
		return (NULL);
	num = n;
	if (n < 0)
	{
		a[0] = '-';
		num = n * -1;
	}
	a[len - 1] = '\0';
	while ((num / 10) != 0 && len > 1)
	{
		a[len - 2] = '0' + (num % 10);
		num = num / 10;
		len--;
	}
	a[len - 2] = '0' + (num % 10);
	return (a);
}
