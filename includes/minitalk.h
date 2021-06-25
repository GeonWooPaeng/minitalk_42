/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:00:01 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/25 21:04:22 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>


/*
**ft_all_utils.c
*/
void		ft_putstr(char *s);
void		ft_error(char *s);

/*
**ft_client_utils.c
*/
int			ft_isspace(char c);
int			ft_isdigit(int c);
int			ft_atoi(char *nptr);

/*
**ft_client.c
*/
void		ft_decimal_conversion(int server_id, char msg, int power);
void		ft_send_message(int server_id, char *msgs);
void		ft_handler(int signum, siginfo_t *siginfo, void *unused);

/*
**ft_server_utils.c
*/


/*
**ft_server.c
*/




#endif