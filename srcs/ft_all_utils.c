/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:56:58 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/28 14:33:29 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putstr(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		write(1, &s[idx], 1);
		idx++;
	}
}

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(0);
}

void	ft_putchar(char s)
{
	write(1, &s, 1);
}
