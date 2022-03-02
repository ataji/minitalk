/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:35:52 by ataji             #+#    #+#             */
/*   Updated: 2022/03/02 15:10:08 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr("we are not good");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid == 0)
	{
		ft_putstr("invalid pid\nplease write the correct pid\n");
		exit(0);
	}
	read_message(av[2], pid);
	return (0);
}
