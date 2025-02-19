/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 02:04:04 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/10/07 00:43:32 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*newstr;
	size_t			i;

	i = 0;
	a = (unsigned char)c;
	newstr = (unsigned char *)s;
	while (i < n)
	{
		if (newstr[i] == a)
			return (&newstr[i]);
		i++;
	}
	return (NULL);
}
