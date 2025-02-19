/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:24:02 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/10/01 04:55:54 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	num_strings(char const *str, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			i = 0;
		else if (!i)
		{
			i = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static	size_t	count_words(char const *s, char c, size_t i)
{
	size_t		len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static	char	**ft_free(char const **s, size_t i)
{
	while (i > 0)
	{
		i--;
		free((void *)s[i]);
	}
	free(s);
	return (NULL);
}

static	char	**create_string(char const *s, char **dst, char c, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * count_words(s, c, i) + 1);
		if (!dst)
			return (ft_free((char const **)dst, j));
		while (s[i] && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	len;

	if (!s)
		return (NULL);
	len = num_strings(s, c);
	dst = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	return (create_string(s, dst, c, len));
}
