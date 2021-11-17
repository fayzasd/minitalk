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


int main(int argc, char **argv)
{
	int *rem;
	int i = 0; 
	int j = 0;
	int c = 0;

	int id = ft_atoi(argv[1]);
	while(argv[2][i])
		i++;
	rem = (int *)malloc(16*i);
	if (!rem)
		return 0;
	i = 0;
	while(argv[2][i])
	{
		c = argv[2][i];
		while(c > 0)
		{
			rem[j] = c % 2;
			c = c / 2;
			j++;
		}
		i++;
	}
	rem[j] = 3;
	j = 0;
	while(rem[j] != 3)
	{
		if (rem[j] == 0)
			kill(id, SIGUSR1);
		else if (rem[j] == 1)
			kill(id, SIGUSR2);
		j++;
		usleep(100);
	}
}
