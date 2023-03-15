/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servermandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:23:33 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/15 15:35:36 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	bit;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server online\nPID: [%d]\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause ();
	}
	return (0);
}
	