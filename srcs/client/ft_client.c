/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:34 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/25 21:03:35 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minitalk.h"

void	ft_decimal_conversion(int server_id, char msg, int power)
{
	if (power > 0)
		ft_decimal_conversion(server_id, msg / 2, power - 1);
	if ((msg % 2) == 0)
	{
		if (kill(server_id, SIGUSR1) == -1)
			ft_error("[Error] kill");
	}
	else
	{
		if (kill(server_id, SIGUSR2) == -1)
			ft_error("[Error] kill");
	}
	usleep(100);
}

void	ft_send_message(int server_id, char *msgs)
{
	int	idx;

	idx = 0;
	while (msgs[idx])
	{
		ft_decimal_conversion(server_id, msgs[idx], 7);
		idx++;
	}
}

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)signum;
	(void)siginfo;
	(void)unused;
	ft_putstr("Signal received\n");
	exit(0);
}

int		main(int argc, char *argv[])
{
	struct sigaction	sact;
	int					ascii;

	sact.sa_flags = SA_SIGINFO; // SA_SIGINFO설정을 안해주면 시그널 번호만 handler에 보내줍니다.
	sact.sa_sigaction = ft_handler;// sa_flags가 SA_SIGINFO로 설정 되어 있어서 sa_sigaction사용합니다.	
	sigemptyset(&sact.sa_mask);
	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
		ft_error("[Error] sigaction");
	if ((sigaction(SIGUSR2, &sact, 0)) == -1)
		ft_error("[Error] sigaction");
	if (argc == 3)
	{
		ascii = atoi(argv[1]);
		ft_send_message(ascii, argv[2]);
	}
	while (1)
		pause();
	return (0);
}
