/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthongka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:25:57 by pthongka          #+#    #+#             */
/*   Updated: 2022/03/12 22:30:06 by pthongka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (n <= destlen)
		return (srclen + n);
	while ((dest[i] != '\0') && i < (n - 1))
		i++;
	while (*src && i < (n - 1))
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}
