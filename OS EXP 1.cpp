#include<stdio.h>
#include<unistd.h>
int main()
{
printf("Process ID: %d\n", getpid() ); 
printf("ParentProcess ID: %d\n", getpid() );
return 0;
}