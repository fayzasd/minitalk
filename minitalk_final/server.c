/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:13 by fasad             #+#    #+#             */
/*   Updated: 2021/11/22 14:32:19 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int two, int i)
{
	int	ret;

	ret = 1;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		ret *= two;
		i--;
	}
	return (ret);
}

void	signal_out(int sig)
{
	static int	i = 0;
	static int	x = 0;

	if (sig == SIGUSR1)
	{
		i += ft_pow(2, x);
		x++;
	}
	else if (sig == SIGUSR2)
		x++;
	if (x == 8)
	{
		write(1, &i, 1);
		i = 0;
		x = 0;
	}
}

void	ft_server(int sig, siginfo_t *sa, void *a)
{
	pid_t	c_pid;

	(void)a;
	c_pid = sa -> si_pid;
	signal_out(sig);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	printf("SERVER PID: %d\n", pid);
	sa.sa_sigaction = &ft_server;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
