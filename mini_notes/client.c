#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int ft_atoi(char *s)
{
	int n;
	int i;
	
	n = 0;
	i = 0;
	while (s[i])
	{
		n += s[i] - 48;
		if (s[i + 1] != '\0')
			n *= 10;
		i++;
	}
	return n;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		ft_putchar(str[i]);
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
// int	*ft_putnbr(int x)
// {
// 	int	*n;
// 	int m;

// 	while(x > 0)
// 	{
// 		x = x /10;
// 		m++;
// 	}
// 	x = 0;
// 	m = n[x];
// 	if (m / 2 > 0)
// 	{
// 		ft_putnbr(m / 2);
// 	}
// 	n[x++] = m % 2;
// }

// int main(int argc, char **argv)
// {
// 	int i = 0; 
// 	int j = 0;
// 	int c = 0;

// 	int id = ft_atoi(argv[1]);
// 	i = 0;
// 	j = 0;
// 	while(argv[2][i])
// 	{
// 		c = argv[2][i];
// 		ft_putnbr(c);
// 		i++;
// 	}
// 	//rem[j] = 3;
// 	//j = 0;
// 	// while(j >= 0)
// 	// {
// 	// 	if (rem[j] == 0)
// 	// 		kill(id, SIGUSR1);
// 	// 	else if (rem[j] == 1)
// 	// 		kill(id, SIGUSR2);
// 	// 	j--;
// 	// 	usleep(100);
// 	// }
// }




int main(int argc, char **argv)
{
	char *rem;
	int i = 0; 
	int j = 0;
	int c = 0;

	int id = ft_atoi(argv[1]);
	while(argv[2][i])
		i++;
	rem = (char *)malloc(8 * i + 1);
	if (!rem)
		return 0;
	i = 0;
	while(argv[2][i])
	{
		c = argv[2][i];
		while(c > 0)
		{
			rem[j] = c % 2 + 48;
			c = c / 2;
			j++;
		}
		i++;
	}
	rem[j] = '\n';
	//j = 0;
	while(j >= 0)
	{
		if (rem[j] == '0')
			kill(id, SIGUSR1);
		else if (rem[j] == '1')
			kill(id, SIGUSR2);
		j--;
		usleep(100);
	}
	free(rem);
}

