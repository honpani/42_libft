/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthongka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:18:38 by pthongka          #+#    #+#             */
/*   Updated: 2022/03/31 23:22:55 by pthongka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	finallen;

	finallen = len;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || (int)len < 0)
		finallen = 0;
	else if (len >= ft_strlen(s))
		finallen = ft_strlen(s) - start;
	new = (char *)malloc(finallen + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < finallen && s[start + i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
