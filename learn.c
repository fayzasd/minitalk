#include <stdio.h>
#include <signal.h>
#include <unistd.h>  
#include <stdlib.h>

int main()
{
    int id;
    int n;
    int i;
    id = fork();

    if (id == 0)
        n = 1;
    else
        n = 6;
    if(id != 0)
        sleep(1);

    i = n;
    while (i < n+ 5)
    {
        printf("%d",i); 
        i++;
    }
    if (id != 0)
        printf("\n");
}