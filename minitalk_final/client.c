#include "minitalk.h"


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


void bit_func(int c, int pid)
{
    int i;

    i = 0;
    while(c > 0 || i < 8)
    {
        if (c % 2 == 1)
        {
             if(kill(pid, SIGUSR1) == -1)
                ft_putstr("Signal error");
        }
        else if (c % 2 == 0)
        {
            if(kill(pid, SIGUSR2) == -1)
               ft_putstr("Signal error");
        }
        c /= 2;
        i++;
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    int pid;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while(argv[2][i])
        {
            bit_func(argv[2][i],pid);
            i++;
            usleep(100);
        }
    }
    else 
        ft_putstr("Invalid no of arguments");
}