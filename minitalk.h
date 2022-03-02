/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:18:34 by ataji             #+#    #+#             */
/*   Updated: 2022/03/02 14:55:48 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<signal.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>

int	g_pid;

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	message_to_server(char message, pid_t pid);
void	read_message(char *str, pid_t pid);
void	ft_putnbr(pid_t pid);
void	handler_sigusr(int signum, siginfo_t *pid, void *ptr);
void	get_old_pid(pid_t new_pid, char *c, int *bits);

#endif
