
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int x = 0;

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_pow(int two, int i)
{
	int ret;

	ret = 1;
	if (i == 0)
		return 1;
	while(i > 0)
	{
		ret *= two;
		i--;
	}
	return ret;	
}

void	btoc(int *bin)
{
	int i;
	int j;
	char c;

	i = 0;
	j = 0;
	while (bin[i])
	{
		j = 0;
		while(j < 8)
		{
			c *= ft_pow(2,i);
			j++;
		}
		write(1, &c, 1);
		i++;
	}
}

void ft_server(int sig, siginfo_t *sa, void *a)
{
	int i;
	// static char *x;
	(void)a;
	pid_t c_pid;
	
	i = 0;
	c_pid = sa -> si_pid;
	if (sig == SIGUSR2)
	{
		i += ft_pow(2,x);
		x++;
	}
	else if(sig == SIGUSR1)
		x++;
	x = 0;
	printf("%d\n",i);
}


int main()
{
	int pid;
	struct sigaction sa;

	pid = getpid();
	printf("SERVER PID: %d\n", pid);
	
	sa.sa_sigaction = &ft_server;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)		
		pause();
	return 0;
}
