/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:53:49 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/16 15:48:58 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (*(s + i))
	{
		while (*(s + i) && *(s + i) == c)
			++i;
		if (*(s + i) && *(s + i) != c)
		{
			while (*(s + i) && *(s + i) != c)
				++i;
			++words;
		}
	}
	return (words);
}

static char	**split_words(char **result, char const *s, char c, int words)
{
	size_t	k;
	int		i;
	int		words_aux;

	i = 0;
	words_aux = 0;
	while (*(s + i) && words_aux < words)
	{
		k = 0;
		while (*(s + i) && *(s + i) == c)
			++i;
		while (*(s + i + k) && *(s + i + k) != c)
			++k;
		if (k > 0)
			*(result + words_aux++) = ft_substr(s, i, k);
		i = i + k;
	}
	return (result);
}

char		**ft_split(char const *s, char c)
{
	int		words;
	char	**result;

	if (!s)
		return (0);
	words = count_words(s, c);
	if (!(result = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	result = split_words(result, s, c, words);
	*(result + words) = NULL;
	return (result);
}
