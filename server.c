
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int ft_putbinary(char *str)
{
  int i = 0;
  int rem[16] = {0, };
  int x = 20;
 
  while(x > 0)
  {
    rem[i] += x % 2;
    x /= 2;
    i++;
  } 

  return x;
}

int main(int argc, char **argv)
{
  int *rem;
  int i = 0, j = 0;
  int sig;
  int c = 0;


  int pid = getpid();
  while(argv[1][i])
    i++;
  rem = (int *)malloc(sizeof(int)*i);
  if (!rem)
    return 0;
  printf("PID: %d\n",pid);
  i = 0;
  while(argv[1][i])
  {
    c = argv[1][i];
    while(c > 0)
    {
      rem[j] = c % 2;
      c = c / 2;
      j++;
    }
    i++;
  }
  while(j >= 0)
  {
    printf("%d", rem[j]);
    j--;  
  }
}