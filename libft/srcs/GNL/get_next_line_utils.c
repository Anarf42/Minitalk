/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:04 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/08 11:56:59 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

/*
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && (str[i] != (char)c))
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	else
		return (NULL);
}
*/
char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	size_t	len;
	char	*res;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	c = 0;
	while (s2[c] != '\0')
		res[i++] = s2[c++];
	res[i] = '\0';
	return (res);
}

char	*inicilize_storage(char *storage)
{
	storage = malloc(1);
	if (!storage)
		return (NULL);
	storage[0] = '\0';
	return (storage);
}

char	*ft_reset_error(char *content)
{
	free(content);
	return (NULL);
}
