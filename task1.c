#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int f;
int main()
{
	srand(time(NULL));
	int sum=0,sum2=0,sum3=0,sum4=0,i,j,status;
	int pid1;
	int bigsum=0;
	int arr1[4];
	FILE  *f;
	f=fopen("output.txt","w");
	FILE *f1;
	f1=fopen("output.txt","r");
	//int str2[4];
//	int str[100]={};
//	for(i=0;i<100;i++)
//	{
//		str[i]=rand()%1000;
//	}
	int str[100]={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
	for(j=0;j<=3;j++)
	{
		pid1=fork();
		if(pid1 <0)
		{
			printf("failed to create child process\n");
		}
		else if(pid1==0)
		{
			if(j==0)
			{
				int m;
				for(m=0;m<25;m++)
				{
					sum=sum+str[m];
					//printf("%d\n",sum);
				}
				fprintf(f,"%d\n",sum);

//				printf("%d\n",sum);
				exit(0);
			}
			else if(j==1)
			{
				int n;
				for(n=25;n<50;n++)
				{
					sum2=sum2+str[n];
				}
				fprintf(f,"%d\n",sum2);
		//		printf("%d\n",sum2);
				exit(0);
			}
			else if(j==2)
			{
				int v;
				for(v=50;v<75;v++)
				{
					sum3=sum3+str[v];
				}
				fprintf(f,"%d\n",sum3);
		///		printf("%d\n",sum3);
				exit(0);
			}
			else if(j==3)
			{
				int x;
				for(x=75;x<100;x++)
				{
					sum4=sum4+str[x];
				}
				fprintf(f,"%d\n",sum4);
		//		printf("%d\n",sum4);
				exit(0);
			}
		}
		else
		{
			wait(&status);
		}
	}
	int s;
	for(s=0;s<4;s++)
	{
		fscanf(f1,"%d\n",&arr1[s]);
	}
	for(s=0;s<4;s++)
	{
		bigsum=bigsum+arr1[s];
	}
	printf("Sum is :%d\n",bigsum);
	return 0;
}
