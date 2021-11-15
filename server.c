
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


int main()
{
  int pid;

  pid = getpid();
  printf("PID: %d\n",pid);
}