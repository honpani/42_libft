/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthongka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:32:37 by pthongka          #+#    #+#             */
/*   Updated: 2022/03/31 23:28:18 by pthongka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (join == NULL)
		return (NULL);
	while (s1[++i])
	{
		join[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		join[j] = s2[i];
		j++;
	}
	join[j] = '\0';
	return (join);
}
