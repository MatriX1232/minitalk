/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:35:51 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/15 01:09:43 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>

//		print int in binary
// void	print_bin(long n)
// {
// 	long	i;
// 	for (i = 1 << 8; i > 0; i = i / 2) {
// 		if ((n & i) != 0)
// 		{
// 			ft_printf("1");
// 		}
// 		else
// 		{
// 			ft_printf("0");
// 		}
// 	}
// 	ft_printf("\n");
// }

//		send bit by bit
void	ft_send_bin(int i, int pid, int bin[8])
{
	while (i < 8)
	{
		if (bin[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

//		converting to binary and sending bit by bit
void	ft_send_signal(int pid, int n)
{
	int	bin[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (n == 0 || (n & 1) == 0)
			bin[i] = 0;
		else if ((n & 1) == 1)
			bin[i] = 1;
		if (n > 0)
			n = n >> 1;
		i--;
	}
	i = 0;
	ft_send_bin(i, pid, bin);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Bad arguments!\n");
		ft_printf("USAGE ./client <PID> <MESSAGE>\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (str && *str)
		ft_send_signal(pid, *str++);
	ft_send_signal(pid, '\n');
	return (0);
}
