/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:37:59 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/23 16:29:43 by anruiz-d         ###   ########.fr       */
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
		ft_printf("error format\n");
		exit(1);
	}
	pid = getpid();
	ft_printf("pid -> %d\nwaiting message... \n", pid);
	if (signal(SIGUSR1, handler_sign) == SIG_ERR)
	{
		ft_printf("Client: kill(SIGUSR1) failed\n");
		exit(1);
	}
	if (signal(SIGUSR2, handler_sign) == SIG_ERR)
	{
		ft_printf("Client: kill(SIGUSR2) failed\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
