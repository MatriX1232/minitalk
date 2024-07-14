/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:35:55 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/15 00:00:12 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	ft_sig_handler(int signal)
{
	static int	i;
	static int	n;
	int			b;

	if (signal == SIGUSR1)
		b = 0;
	else
		b = 1;
	n = (n << 1) + b;
	i++;
	if (i == 8)
	{
		write(1, &n, 1);
		i = 0;
		n = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sigac;

	sigac.sa_handler = &ft_sig_handler;
	sigac.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sigac, 0);
	sigaction(SIGUSR2, &sigac, 0);
	printf("Receiver PID: %d\n", getpid());
	while (1)
	{
		usleep(100);
	}

	return (0);
}
