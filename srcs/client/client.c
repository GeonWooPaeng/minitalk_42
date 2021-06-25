/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:29:40 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/25 15:51:07 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/client.h"

// void	decimal_conversion(char ascii, int power, int pid)
// {
// 	if (power > 0)
// 		decimal_conversion(ascii / 2, power - 1, pid);
// 	if ((ascii % 2) == 1)
// 	{
// 		if (kill(pid, SIGUSR1) == -1)
// 		{
// 			ft_putstr("Error signal!\n");
// 			exit(0);
// 		}
// 	}
// 	else
// 	{
// 		if (kill(pid, SIGUSR2) == -1)
// 		{
// 			ft_putstr("Error signal!\n");
// 			exit(0);
// 		}
// 	}
// 	usleep(100);
// }

// int	send_message(int server_pid, char *msg)
// {
// 	int		i;

// 	i = 0;
// 	while (msg[i] != '\0')
// 	{
// 		decimal_conversion(msg[i], 7, server_pid);
// 		i++;
// 	}
// 	return (0);
// }

// void	my_handler(int signum, siginfo_t *siginfo, void *unused)
// {
// 	(void)unused;
// 	(void)siginfo;
// 	(void)signum;
// 	ft_putstr("Signal received\n");
// }

// int	main(int argc, char **argv)
// {
// 	struct sigaction	sact;

// 	sact.sa_flags = SA_SIGINFO; // SA_SIGINFO설정을 안해주면 시그널 번호만 handler에 보내줍니다.
// 	sact.sa_sigaction = my_handler;// sa_flags가 SA_SIGINFO로 설정 되어 있어서 sa_sigaction사용합니다.
// 	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
// 		error("Error sigaction\n");
// 	if (argc == 3)
// 		send_message(atoi(argv[1]), argv[2]);
// 	else
// 		error("Error arguments\n");
// 	while (1)
// 		pause();
// 	return (0);
// }


// int main(int argc, char *argv[])
// {
// 	struct sigaction	sact;
// 	int					ascii;

// 	sact.sa_flags = SA_SIGINFO; // SA_SIGINFO설정을 안해주면 시그널 번호만 handler에 보내줍니다.
// 	sact.sa_sigaction = ft_handler;// sa_flags가 SA_SIGINFO로 설정 되어 있어서 sa_sigaction사용합니다.	
// 	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
// 		ft_error("[Error] sigaction");
// 	if (argc == 3)
// 	{
// 		ascii = atoi(argv[1]);
// 		ft_send_message(ascii, argv[2]);
// 	}
// }

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int pid;
	int sig_num;

	if (argc != 3)
	{
		printf("usage %s [pid] [signum]\n", argv[0]);
		return (1);
	}
	pid = atoi(argv[1]);
	sig_num = atoi(argv[2]);
	if (!kill(pid, sig_num))
	{
		perror("signal send error");
		return (1);
	}
	return (0);
}