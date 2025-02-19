/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:42:32 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/10/07 00:45:42 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;
	size_t	len_src;

	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	i = 0;
	len_src = ft_strlen(src);
	while (dst[i] && i < dstsize)
		i++;
	l = i;
	while (src[i - l] && i < dstsize - 1)
	{
		dst[i] = src[i - l];
		i++;
	}
	dst[i] = '\0';
	return (l + len_src);
}
