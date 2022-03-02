/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:35:42 by ataji             #+#    #+#             */
/*   Updated: 2022/03/02 14:57:03 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_old_pid(int new_pid, char *c, int *bits)
{
	*c = 0xFF;
	*bits = 0;
	g_pid = new_pid;
}

void	handler_sigusr(int signum, siginfo_t *pid, void *ptr)
{
	static char	c = 0xFF;
	static int	bits = 0;

	(void)ptr;
	if (!g_pid)
		g_pid = pid->si_pid;
	if (g_pid != pid->si_pid)
		get_old_pid(pid->si_pid, &c, &bits);
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler_sigusr;
	sa.sa_flags = SA_RESTART;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
