/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:34 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/26 19:31:34 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minitalk.h"

void	ft_binary_send(int server_id, char msg)
{
	unsigned char bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & msg)
		{
			if (kill(server_id, SIGUSR1) == -1)
				ft_error("[Error] kill\n");
		}
		else
		{
			if (kill(server_id, SIGUSR2) == -1)
				ft_error("[Error] kill\n");
		}
		bit >>= 1;
		usleep(100);
	}
}

void	ft_send_message(int server_id, char *msgs)
{
	int	idx;

	idx = 0;
	while (msgs[idx] != '\0')
	{
		ft_binary_send(server_id, msgs[idx]);
		idx++;
	}
}

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)signum;
	(void)siginfo;
	(void)unused;
	ft_putstr("Signal received\n");
}

int		main(int argc, char *argv[])
{
	struct sigaction	sact;
	int					server_id;

	sact.sa_flags = SA_SIGINFO; // SA_SIGINFO설정을 안해주면 시그널 번호만 handler에 보내줍니다.
	sact.sa_sigaction = ft_handler;// sa_flags가 SA_SIGINFO로 설정 되어 있어서 sa_sigaction사용합니다.	
	sigemptyset(&sact.sa_mask);
	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
		ft_error("[Error] sigaction\n");
	if ((sigaction(SIGUSR2, &sact, 0)) == -1)
		ft_error("[Error] sigaction\n");
	if (argc == 3)
	{
		server_id = atoi(argv[1]);
		ft_send_message(server_id, argv[2]);
	}
	while (1)
		pause();
	return (0);
}
