/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:00:23 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/08 11:38:31 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static	int	ft_print_number(int number)
{
	int		lengh_number;
	char	*str_number;

	lengh_number = 0;
	str_number = ft_itoa(number);
	ft_putstr_fd(str_number, 1);
	lengh_number += ft_strlen(str_number);
	free(str_number);
	return (lengh_number);
}

static	int	ft_print_caracter(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static	int	ft_print_string(char *str)
{
	int	lenght;

	lenght = 0;
	if (str)
	{
		ft_putstr_fd(str, 1);
		lenght = ft_strlen(str);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		lenght += 6;
	}
	return (lenght);
}

static	int	ft_format(va_list args, char format)
{
	int	length_word;

	length_word = 0;
	if (format == 'c')
		length_word += ft_print_caracter((char)va_arg(args, int));
	else if (format == 's')
		length_word += ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		length_word += ft_print_memory(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		length_word += ft_print_number(va_arg(args, int));
	else if (format == 'u')
		length_word += ft_print_unsigned_number(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length_word += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		length_word += ft_print_caracter('%');
	return (length_word);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		length_word;

	length_word = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			length_word += ft_format(args, *(str + 1));
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			length_word += 1;
		}
		str++;
	}
	va_end(args);
	return (length_word);
}
