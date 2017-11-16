#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int var=0; //globle variable
int main()

{
int status,a[100];
int sum2=0;
int sum1=0;
int sum=0;
int sum3=0;
for(int i=0;i<100;i++)
	{a[i]=rand()%20;
}
int  pid1,pid2;
pid1=fork();
if(pid1<0)
	printf("fork failed");
else if(pid1==0)
{	
	for(int i=1;i<=25;i++)
	{
	sum+=a[var];
	var++;
	}
}
else 
{	
	wait(&status);
	
	for(int i=0;i<=15;i++)
	{sum1+=a[var];
	var++;}

	pid2=fork();
	if (pid2<0)
		printf("fork failed");
else if(pid2==0)
{	
	for(int i=0;i<=25;i++)
	{sum2+=a[var];
	var++;}
}
else
{
	wait(&status);
	
	for(int i=0;i<=25;i++)
	{sum3+=a[var];
	var++;}

}
}
int c=sum+sum1+sum2+sum3;
printf("%d\n",c);
return 0;
}
