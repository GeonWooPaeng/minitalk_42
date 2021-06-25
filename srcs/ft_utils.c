/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:28:52 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/25 14:40:06 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int			ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' ||
	c == '\t' || c == '\v' || c == ' ');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_atoi(const char *nptr)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

void	ft_putstr(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		write(1, s[idx], 1);
		idx++;
	}
}

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(0);
}