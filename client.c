#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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