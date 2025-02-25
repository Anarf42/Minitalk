/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:38:26 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/25 15:09:39 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static	void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("%sError sending SIGUSR1 to PID %d. Kill failed.%s\n", COLOR_RED, server_pid, COLOR_RESET);
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("%sError sending SIGUSR2 to PID %d. Kill failed.%s\n", COLOR_RED, server_pid, COLOR_RESET);
				exit(1);
			}
		}
		usleep(SIGNAL_DELAY);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;
	char	*message;

	if (argc != 3)
	{
		ft_printf("%sError: Client format ./client <Server_Pid> <message>%s\n", COLOR_RED, COLOR_RESET);
		exit (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
	ft_printf("\033[32mmessage sent successfully to server %d\033[0m\n", server_pid);
	return (0);
}
