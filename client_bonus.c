/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:54:11 by ataji             #+#    #+#             */
/*   Updated: 2022/03/02 14:18:10 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	return_message(int i)
{
	(void)i;
	ft_putstr("we are good man\n");
	exit(0);
}

void	message_to_server(char message, pid_t pid)
{
	int	shift;

	shift = -1;
	while (++shift < 8)
	{
		if (message & (128 >> shift))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(1000);
	}
}

void	read_message(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		message_to_server(str[i], pid);
		i++;
	}
	message_to_server('\0', pid);
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	signal(SIGUSR1, return_message);
	if (ac != 3)
	{
		ft_putstr("we are not good");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	read_message(av[2], pid);
	return (0);
}
