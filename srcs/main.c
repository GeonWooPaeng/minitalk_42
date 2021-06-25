/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:53:54 by gpaeng            #+#    #+#             */
/*   Updated: 2021/06/25 15:06:18 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/ft_minitalk.h"

#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 

// void sig_int(int signo);
// void sig_usr(int signo);

// int main()
// {
//     int i = 0;
//     struct sigaction intsig, usrsig;

//     usrsig.sa_handler = sig_usr;
//     sigemptyset(&usrsig.sa_mask);
//     usrsig.sa_flags = 0;

//     intsig.sa_handler = sig_int;
//     sigemptyset(&intsig.sa_mask);
//     intsig.sa_flags = 0;

// 	// SIGINT에 대해서 sig_int를 등록한다. 
//     if (sigaction(SIGINT, &intsig, 0) == -1)
//     {
//         printf ("signal(SIGINT) error");
//         return -1;
//     }    

// 	// SIGUSR2에 대해서 usrsig를 등록한다. 
//     if (sigaction(SIGUSR2, &usrsig, 0) == -1)
//     {
//         printf ("signal(SIGUSR2) error");
//         return -1;
//     }    

//     while(1)
//     {
//         printf("%d\n", i);
//         i++;
//         sleep(1);
//     }
// }

// void sig_int(int signo)
// {
//     sigset_t sigset, oldset;

// 	// 핸들러가 수행되는 동안 수신되는 모든 시그널에 대해서
// 	// 블럭한다.  
//     sigfillset(&sigset);
//     if (sigprocmask(SIG_BLOCK, &sigset, &oldset) < 0)
//     {
//         printf("sigprocmask %d error \n", signo);
//     }
//     fprintf(stderr, "SIGINT !!!!\n");
//     sleep(5);
// }

// void sig_usr(int signo)
// {
//     printf("sig_usr2\n");
// }


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("사용법\n");
    }
    else
        kill(atoi(argv[1]), SIGKILL);
    while (1)
        pause();

    return (0);
}