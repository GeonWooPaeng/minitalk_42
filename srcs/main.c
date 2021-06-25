/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:53:54 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/25 17:49:03 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/ft_minitalk.h"

#include <signal.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>

void ft_handler(int signum)
{
    printf("시그널 받았습니다.(%d)\n", SIGINT);
    sleep(2);
}

int main(int argc, char *argv[])
{
    int idx;

    idx = 0;
    signal(SIGINT, (void *)ft_handler);
    while (1)
    {
        printf("process 실행 중 %d\n", idx);
        sleep(1);
        idx++;
    }
}