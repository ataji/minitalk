/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:20:43 by ataji             #+#    #+#             */
/*   Updated: 2022/03/02 14:56:17 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include<signal.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int	g_pid;

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	message_to_server(char message, pid_t pid);
void	read_message(char *str, pid_t pid);
void	ft_putnbr(pid_t pid);
void	handler_sigusr(int signum, siginfo_t *pid, void *ptr);
void	get_old_pid(pid_t new_pid, char *c, int *bits);

#endif
