//Program for Finding Prime Numbers less than or equal to the user input using multithreading
#include<stdio.h>
#include<pthread.h>
void *prime(void *arg)		//Thread which outputs the prime numbers
{
	int *n;		//Pointer for assigning argument
	n = (int *)arg;
	int count,i,j;		//count variable is for counting the number of divisors which gives remainder as 0
	for(i=2;i<=n[0];i++)
	{
		count = 0;
		for(j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				count++;
			}
		}
		if(count==2)		//only factor is 1 and itself
		{
			printf("\n%d",i);
		}
	}
	return NULL;
}

int main()
{
	int n;		//Variable for taking input
	printf("Enter a Number: ");
	scanf("%d",&n);
	printf("Prime Numbers Less than or Equals to %d are:",n);
	pthread_t thrd;		//Thread declaration
	pthread_create(&thrd,NULL,prime,(void *)&n);		//Thread creation
	pthread_join(thrd,NULL);		//Wait for thread to finish
}
