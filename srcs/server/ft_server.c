/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:27 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/26 17:58:47 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minitalk.h"

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
}

int	main(int argc, char *argv[])
{
	struct sigaction	sact;

	(void)argv;
	(void)argc;
	ft_putstr("server id: ");
	ft_putnbr(getpid());
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