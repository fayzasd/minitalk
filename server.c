
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void server(int sig)
{
  printf("remember\n");
}

int main()
{
  struct sigaction sa = { 0 };
  int pid = getpid();
  
  sa.sa_handler = &server;
  sigaction(SIGUSR1, &sa, NULL);
  printf("PID: %d\n",pid);

  return 0;
}