/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:40:56 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/26 19:50:05 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}
