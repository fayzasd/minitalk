
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

// void	btoc(char *str)
// {	
// 	int i;
// 	int c;
// 	int j;

// 	i = 0;
// 	c = 0;
// 	while (str[i] && j < 8)
// 	{
// 		if (str[i] == 1)
// 		{
// 			c += ft_pow(2,i);
// 		}
// 		if (i == 7)
// 			j = 0;
// 		i++;
// 	}
// 	ft_putchar(c);
// }


// void	btoc(char *str)
// {
// 	int i;
// 	int j;
// 	int c;

// 	i = 0;
// 	j = 0;
// 	c = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while(j < 8)
// 		{
// 			if (str[j + i] == '1')
// 				c += ft_pow(2,j);	
// 			j++;
// 		}
// 		ft_putnbr(c);
// 		i += 7;
// 	}
// }

// void ft_printchar(char c, int j)
// {
// 	while (i < 9)
// 	{
// 		if (i == 8)
// 			write(1, &c, 1);
// 		i++;
// 	}
// }

void some_func(int sig)
{
	static int i = 0;
	static int x = 0;
	static int j = 0;

	if (sig == SIGUSR1)
	{
		i += ft_pow(2,x);
		x++;
		j++;
	}
	else if(sig == SIGUSR2)
	{
		x++;
		j++;
	}
	if (j == 8)	
		{
			ft_putchar(i);
			j = 0;
			i = 0;
			x = 0;
		}	
}

void ft_server(int sig, siginfo_t *sa, void *a)
{
	// static int i;
	(void)a;
	pid_t c_pid;

	c_pid = sa -> si_pid;
	some_func(sig);
	// if (sig == SIGUSR1)
	// {
	// 	i += ft_pow(2,x);
	// 	x++;
	// }
	// else if(sig == SIGUSR2)
	// 	x++;
	// printf("%d\n",i);
}

// void ft_server(int sig, siginfo_t *sa, void *a)
// {
// 	char *str;
// 	static int i;
// 	(void)a;
// 	pid_t c_pid;

// 	i = 0;
// 	str = (char *)malloc(sizeof(char) * 8);
// 	c_pid = sa -> si_pid;
// 	if (sig == SIGUSR2)
// 	{
// 		i += ft_pow(2,x);
// 		x++;
// 	}
// 	else if(sig == SIGUSR1)
// 	{
// 		// str[i] = '0';
// 		x++;
// 	}
// 	ft_putnbr(i);
// 	//btoc(str);
// 	free(str);
// }

unsigned int rev_bits(unsigned int n)
{
    int i;
    unsigned int rev;

    rev = 0;
    i = 0;
    while(i < 8)
    {
        if(n && (1 << i))
            rev |= 1 << (7 - i);
    }
    return rev;
}

// void bit_user(int sig, int i, char c)
// {
// 	if (sig == SIGUSR1)
// 	{
// 		c |= (1 << i);
// 		i++;
// 	}
// 	printf("%d\n",c);
// 	if (i == 8)
// 	{
// 		ft_putchar(c);
// 		i = 0;
// 		c = 0;
// 	}
// }

// void ft_server(int sig, siginfo_t *sa, void *a)
// {
// 	(void)a;
// 	pid_t c_id;
// 	static char c = 0;
// 	static unsigned int i = 0;

// 	c_id = sa -> si_pid;
// 	bit_user(sig, i ,c);
// 	// if (sig == SIGUSR1)
// 	// {
// 	// 	c |= (1 << i);
// 	// 	i++;
// 	// 	// if (i % 2 == 1)
// 	// 	// 	i <<= 1;
// 	// 	// i |= 0x01;
// 	// }
// 	// // else
// 	// // 	i <<= 1;
// 	// printf("%d\n",i);
// 	// if (i == 8)
// 	// {
// 	// 	ft_putchar(c);
// 	// 	i = 0;
// 	// 	c = 0;
// 	// }
// }

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
