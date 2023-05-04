/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:41:05 by asacchin          #+#    #+#             */
/*   Updated: 2023/03/28 14:06:07 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int bit, int pid)
{
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(600);
	}
}

void	check_bit(int pid, char *msg)
{
	int	i;
	int	bit;

	i = 0;
	while (msg[i])
	{
		bit = 0;
		send_char(msg[i], bit, pid);
		i++;
	}
}

void	sent_signal(int i)
{
	ft_printf("Message sent\n");
	ft_printf("Sent signal: %d\n", i);
}

int	main(int argc, char **argv)
{
	pid_t	c;

	c = 0;
	if (argc == 3)
	{
		c = ft_atoi(argv[1]);
		signal(SIGUSR1, &sent_signal);
		check_bit(c, argv[2]);
		send_char('\n', 0, c);
		send_char('\0', 0, c);
	}
	else
	{
		ft_printf("ERROR argc < 3\n");
		exit (0);
	}
}
