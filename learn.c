#include <stdio.h>
#include <signal.h>
#include <unistd.h>  
#include <stdlib.h>

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
	int id = ft_atoi(argv[1]);
	printf("Enter the message:");
	kill(id, SIGUSR2);
}