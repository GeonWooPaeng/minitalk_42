/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:36:10 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/25 15:50:30 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

void sig_handler(int signo)
{
    printf("I Received SIGINT(%d)\n", SIGINT);
}

int main(int argc, char *argv[])
{
    int i;

    i = 0;
    signal(SIGINT, (void *)sig_handler);
    while (1)
    {
        printf("%d\n", i);
        sleep(2);
        i++;
    }
}