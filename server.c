
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int x = 0;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr(int n)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-');
		x = x * -1;
	}
	if (x / 10 > 0)
	{
		ft_putnbr(x / 10);
	}
	ft_putchar((x % 10) + '0');
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

void	btoc(char *str)
{	
	int i;
	int c;
	char *res;

	i = 0;
	c = 0;
	res = (char *)malloc(ft_strlen());
	while (i < 8)
	{
		if (str[i] == 1)
		{
			c += ft_pow(2,j);
		}
		i /= 10;
		j++;
	}
	ft_putchar(c);
}


// void	btoc(int *bin)
// {
// 	int i;
// 	int j;
// 	char c;

// 	i = 0;
// 	j = 0;
// 	while (bin[i])
// 	{
// 		j = 0;
// 		while(j < 8)
// 		{
// 			c *= ft_pow(2,i);
// 			j++;
// 		}
// 		write(1, &c, 1);
// 		i++;
// 	}
// }

// void ft_server(int sig, siginfo_t *sa, void *a)
// {
// 	int i;
// 	// static char *x;
// 	(void)a;
// 	pid_t c_pid;
	
// 	i = 0;
// 	c_pid = sa -> si_pid;
// 	if (sig == SIGUSR2)
// 	{
// 		i += ft_pow(2,x);
// 		x++;
// 	}
// 	else if(sig == SIGUSR1)
// 		x++;
// 	x = 0;
// 	printf("%d\n",i);
// }

void ft_server(int sig, siginfo_t *sa, void *a)
{
	char *str;
	int i;
	(void)a;
	pid_t c_pid;
	
	i = 0;
	str = (char *)malloc(sizeof(char) * 8);
	c_pid = sa -> si_pid;
	if (sig == SIGUSR2)
	{
		str[i] = '1';
		i++;
	}
	else if(sig == SIGUSR1)
	{
		str[i] = '0';
		i++;
	}	
	ft_putstr(str);
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
