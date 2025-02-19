/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:28:54 by Ana               #+#    #+#             */
/*   Updated: 2024/10/10 20:32:16 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_sum;
	char	*newstr;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_sum = len_s1 + len_s2 + 1;
	newstr = (char *)malloc(sizeof(char) * (len_sum));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len_s1 + 1);
	ft_strlcat(newstr, s2, len_sum);
	return (newstr);
}
