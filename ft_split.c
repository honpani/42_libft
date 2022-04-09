/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthongka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:51:03 by pthongka          #+#    #+#             */
/*   Updated: 2022/03/31 18:04:55 by pthongka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*wordbuild(const char *s, char c)
{
	char	*word;

	word = (char *)malloc(wordlen(s, c) + 1);
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, wordlen(s, c) + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	arr = (char **)malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < wordcount(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		arr[j] = wordbuild(&s[i], c);
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	arr[j] = 0;
	return (arr);
}
