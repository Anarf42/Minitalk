/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:37:59 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/25 14:25:48 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler_sign(int signal)
{
	static int	i;
	static int	bit;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	else if (signal == SIGUSR2)
		(void)signal;
	bit++;
	if (bit == 8)
	{
		if (!i)
			ft_printf("\n");
		else
			ft_printf("%c", i);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("%sError: Server should be executed without arguments.%s\n", COLOR_RED, COLOR_RESET);
		exit(1);
	}
	pid = getpid();
	ft_printf("Server pid: %d\nwaiting message... \n", pid);
	if (signal(SIGUSR1, handler_sign) == SIG_ERR)
	{
		ft_printf("%sError: Failed to register signal handler for SIGUSR1.%s\n", COLOR_RED, COLOR_RESET);
		exit(1);
	}
	if (signal(SIGUSR2, handler_sign) == SIG_ERR)
	{
		ft_printf("%sError: Failed to register signal handler for SIGUSR2.%s\n", COLOR_RED, COLOR_RESET);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
