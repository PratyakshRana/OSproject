#include <stdio.h>

int main()
{
	int i,j;
	int n=5, m=4;		//n is the number of processes and m is the number of resources
	//Available instances of resources
	int avail[4] = {1,5,2,0};
	//Resource instances presently allocated to processes
	int alloc[5][4] = { {0,0,1,2}, //P0
	                    {1,0,0,0}, //P1
						{1,3,5,4}, //P2
						{0,6,3,2}, //P3
						{0,0,1,4} }; //P4
	//Maximum requirement of resource instances that each process requires to complete its task
	int max[5][4] = { {0,0,1,2}, //P0
	                  {1,7,5,0}, //P1
					  {2,3,5,6}, //P2
					  {0,6,5,2}, //P3
					  {0,6,5,6} }; //P4
	//Remaining need found by (Maximum - Allocated)
	int need[n][m];
	for ( i = 0 ; i < n ; i++ )		//For calculating need
	{
		for ( j = 0 ; j < m ; j++ )
		{
			need[i][j] = (max[i][j]) - (alloc[i][j]);
		}
	}
	int isAvail;		//To check if need is fulfilled by the available instances
	int isSafe = 1;		//To check if system is in safe state or not
	int finish[5] = {0};		//To check if each process finished its task successfully or not
	int pass;		//Number of passes required = number of processes
	for ( pass = 0 ; pass < n ; pass++)		//For passses
	{
		for ( i = 0 ; i < n ; i++ )		//For checking each process 
		{
			if ( finish[i] == 0 )		//If process is not finished
			{
				isAvail = 1;
				for ( j = 0 ; j < m ; j++ )		//For checking need can be fulfilled or not
				{
					if ( need[i][j] > avail[j] )
					{
						isAvail = 0;
					}
				}
				if ( isAvail == 1 )
				{
					for ( j = 0 ; j < m ; j++ )		//If both conditions met then instances were allocated to process 
					{
						avail[j] = avail[j] + alloc[i][j];		//Then the process completed its task and freed the instances
					}
					finish[i] = 1;
				}
			}
		}
	}
	
	for ( i = 0 ; i < n ; i++ )		//For checking every process has completed its task or not
	{
		if ( finish[i] == 0)
		{
			isSafe = 0;		//If any one of the process could not complete its task then the system is not in safe state
		}
	}
	if ( isSafe == 1 )
	{
		printf("The System is in Safe State");
	}
	else
	{
		printf("The System is not in Safe State");
	}
}
