/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:11:07 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/28 14:19:09 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	value;
	static int	bit;

	(void)context;
	if (sig == SIGUSR1)
		value += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &value, 1);
		if (value == '\0')
			kill(info->si_pid, SIGUSR1);
		value = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	ft_printf ("Server online\nPID: [%d]\n", pid);
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigemptyset(&act.sa_mask);
	while (1)
		pause();
}
