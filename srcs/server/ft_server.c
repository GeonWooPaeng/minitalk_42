/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:27 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/26 20:27:47 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minitalk.h"

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static unsigned char	bit = 0b00000000;
	static	int				bit_num = 0;

	(void)siginfo;
	(void)unused;
	if (signum == SIGUSR1)
	{
		printf("bit >>> %d\n", bit);
		bit += 1 << (7 - bit_num);
	}
	bit_num += 1;
	if (bit_num == 8)
	{
		ft_putchar(bit);
		bit_num = 0;
		bit = 0b00000000;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sact;
	
	(void)argv;
	(void)argc;
	ft_putstr("server id: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_handler;
	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
		ft_error("[Error] sigaction\n");
	if ((sigaction(SIGUSR2, &sact, 0)) == -1)
		ft_error("[Error] sigaction\n");
	while (1)
		pause();
	return (0);
}
