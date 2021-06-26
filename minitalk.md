# minitalk

<br/>

- client 와 server 사이의 communication(문자열)
- server는 먼저 시작되어야하며 시작된 후에 PID를 표시한다.
- client는 [server_PID] [string] 를 매개 변수로 사용한다.
- client는 매개 변수로 전달 된 문자열을 server에 전달한다.
  
    (문자열이 수신되면 server는 이를 표시해야합니다.)
- 프로그램 간의 통신은 UNIX 신호를 사용해서만 이루어져야한다.
- server는 문자열을 매우 빠르게 표시 할 수 있어야한다.
  
    (힌트 : 100 자에 대해 1 초는 COLOSSAL).
- server를 다시 시작할 필요없이 여러 client로 연속으로 문자열을받을 수 있어야한다.
- SIGUSR1 및 SIGUSR2 신호 만 사용할 수 있다.

<br/>

< 전반적인 이해 >

<https://www.joinc.co.kr/w/Site/system_programing/Book_LSP/ch06_Signal>

<br/>

> ## kill()

<br/>

- process에 signal을 전달하기위해 사용하는 함수

```c

int kill(pid_t process_id, int sig);
// process_id로 sig를 보낸다.

```

<br/>

> ## SIGUSR1, SIGUSR2

<br/>

- "특별한" 사전 정의 된 의미없이 사용자가 사용하다록 예약된 신호

<br/>

### POSIX 시스템 (다시 작성하기)
- <signal.h> 헤더는 시스템에서 발생하는 신호를 참조하는 데 사용되는 다음 매크로를 정의해야합니다. 여기에 정의 된 신호 SIG는 대문자가 뒤 따르는 문자로 시작합니다 . 매크로는 유형 int과 고유 한 값이있는 양의 정수 상수 표현식으로 확장 됩니다. 따라서 신호 이름은 매크로 여야합니다 

<br/>

> ## signal()

<br/>

- signal 처리를 설정

<br/>

```c
// ctrl + c 눌렀을 때 signal 받아오게 하기
// => ctrl + c로 프로그램 종료 대신 ft_handler실행
// SIGINT == ctrl + c

#include <signal.h>
#include <unistd.h>
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

```

<br/>

> ## sigaction()

<br/>

- signal() 와 마찬가지로 특정 신호를 수신하기 위해 사용합니다.
- signal을 객체 단위로 제어 할 수 있다.

<br/>

- helpsite

<https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skssim&logNo=121271980>

<https://man7.org/linux/man-pages/man2/sigaction.2.html>

<br/>

### sigaction struct

<br/>

```c
struct sigaction {
    int sa_flags;
    union {
        void (*sa_handler)(); 
        void (*sa_sigaction)(int, siginfo_t *, void *);
    }_funcptr;
}
```

<br/>

### sa_handler, sa_sigaction

<br/>

- sa_handler, sa_sigaction은 메모리가 중첩됩니다.

```c
sa_flags != SA_SIGINFO //이면 sa_handler 멤버 사용
sa_flags = SA_SIGINFO //이면 sa_sigaction 멤버 사용

//=====================================================//

//handler()
void handler(int signum, siginfo_t *sip, ucontext_t *ucp)
// signum: signal handler을 호출할 signal
// sip: signal이 발생한 원인을 담은 곳
// ucp: signal이 전달될 때 signal을 받는 process의 내부 상태

//======================================================//

//sigaction()
int sigaction(int signum, const struct sigaction *act, const struct sigaction *oldact)

// signum: 처리할 signal
// act: signal을 처리할 방법을 지정한 구조체 주소
// oldact:  기존에 signal을 처리하던 방법을 저장할 구조체 주소

```

<br/>

> ## pause()

<br/>

<https://man7.org/linux/man-pages/man2/pause.2.html>

<br/>

- signal을 수신할 때까지 대기합니다.

<br/>

> ## pid 범위

<br/>

<https://stackoverflow.com/questions/16599463/what-is-the-value-range-of-thread-and-process-id>

<https://jybaek.tistory.com/112>

<br/>