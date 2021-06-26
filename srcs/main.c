/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:53:54 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/26 19:45:59 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/ft_minitalk.h"

#include <signal.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char bit = 0b00000000;

    int idx;

    idx = 0;
    while (idx < 9)
    {
        bit += 1 << (7 - idx);
        printf(">>> %d\n", bit);
        idx++;
    }
}