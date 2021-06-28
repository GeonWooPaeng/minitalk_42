/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:34 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/28 20:24:22 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"
// #include <time.h> //속도
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

	// clock_t start = clock();//속도
	idx = 0;
	while (msgs[idx] != '\0')
	{
		ft_binary_send(server_id, msgs[idx]);
		idx++;
	}
	ft_binary_send(server_id, '\0');
	// clock_t end = clock(); // 속도
	// printf("sec 속도: %lf\n", (double)(end - start)/CLOCKS_PER_SEC); //속도
	
}

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)signum;
	(void)siginfo;
	(void)unused;
}

int		main(int argc, char *argv[])
{
	struct sigaction	sact;
	int					server_id;

	if (argc != 3)
		ft_error("[Error] check argv\n");
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_handler;
	sigemptyset(&sact.sa_mask);
	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
		ft_error("[Error] sigaction\n");
	if ((sigaction(SIGUSR2, &sact, 0)) == -1)
		ft_error("[Error] sigaction\n");
	server_id = atoi(argv[1]);
	ft_send_message(server_id, argv[2]);
	while (1)
		pause();
	return (0);
}
