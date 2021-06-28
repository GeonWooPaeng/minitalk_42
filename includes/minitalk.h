/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:00:01 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/28 14:42:51 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

/*
**ft_all_utils.c
*/
void		ft_putstr(char *s);
void		ft_error(char *s);
void		ft_putchar(char s);

/*
**ft_client_utils.c
*/
int			ft_isspace(char c);
int			ft_isdigit(int c);
int			ft_atoi(char *nptr);

/*
**ft_client.c
*/
void		ft_binary_send(int server_id, char msg);
void		ft_send_message(int server_id, char *msgs);
void		ft_handler_ack(int signum, siginfo_t *siginfo, void *unused);

/*
**ft_server_utils.c
*/
void		ft_putnbr(int num);

/*
**ft_server.c
*/
void		ft_handler(int signum, siginfo_t *siginfo, void *unused);

#endif
