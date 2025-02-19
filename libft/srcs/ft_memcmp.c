/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:15:06 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/10/10 20:18:38 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*newstr1;
	unsigned char	*newstr2;

	newstr1 = (unsigned char *)s1;
	newstr2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*newstr1 != *newstr2)
			return (*newstr1 - *newstr2);
		newstr1++;
		newstr2++;
	}
	return (0);
}
