/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:38:26 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/02/23 16:22:43 by anruiz-d         ###   ########.fr       */
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
				ft_printf("Client: kill(SIGUSR1) failed\n");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("Client: kill(SIGUSR2) failed\n");
				exit(1);
			}
		}
		usleep(150);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;
	char	*message;

	if (argc < 3)
	{
		ft_printf("Format error, it would be: ./client <PID Server> <message>");
		exit (ERROR_NUM_ARG);
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
	ft_printf("message sent successfully to server %d", server_pid);
	return (0);
}
