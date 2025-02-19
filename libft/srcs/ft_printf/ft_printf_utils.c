/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:11:43 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/08 11:39:11 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static	char	*ft_unsigned_itoa(unsigned int number)
{
	char			*str;
	unsigned long	aux;
	size_t			lenght_number;

	aux = number;
	lenght_number = 1;
	while (aux > 9)
	{
		aux = aux / 10;
		lenght_number++;
	}
	str = (char *)malloc(sizeof(char) * (lenght_number + 1));
	if (!str)
		return (NULL);
	str[lenght_number] = '\0';
	while (lenght_number-- > 0)
	{
		str[lenght_number] = (number % 10) + '0';
		number = number / 10;
	}
	return (str);
}

static	int	ft_putnbr_hex(unsigned long long number, char *base)
{
	int	length_number;

	length_number = 0;
	if (number >= 16)
		length_number += ft_putnbr_hex((number / 16), base);
	ft_putchar_fd(base[number % 16], 1);
	length_number++;
	return (length_number);
}

int	ft_print_hex(unsigned int number, char format)
{
	int	lenght;

	lenght = 0;
	if (format == 'x')
		lenght += ft_putnbr_hex(number, "0123456789abcdef");
	else if (format == 'X')
		lenght += ft_putnbr_hex(number, "0123456789ABCDEF");
	return (lenght);
}

int	ft_print_memory(void *s)
{
	unsigned long long	num_memo;
	int					lenght;

	if (!s)
		return (write(1, "0x0", 3));
	lenght = 0;
	num_memo = (unsigned long long)s;
	lenght += write(1, "0x", 2);
	lenght += ft_putnbr_hex(num_memo, "0123456789abcdef");
	return (lenght);
}

int	ft_print_unsigned_number(unsigned int number)
{
	int		lengh_number;
	char	*str_number;

	lengh_number = 0;
	str_number = ft_unsigned_itoa(number);
	ft_putstr_fd(str_number, 1);
	lengh_number += ft_strlen(str_number);
	free(str_number);
	return (lengh_number);
}
