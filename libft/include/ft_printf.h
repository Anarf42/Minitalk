/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:58:47 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/07 13:57:14 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int	ft_printf(char const *str, ...);
int	ft_print_unsigned_number(unsigned int number);
int	ft_print_memory(void *s);
int	ft_print_hex(unsigned int number, char format);

#endif