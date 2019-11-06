#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

void swap(int* a,int* b)
{
	int temp= *a;
	*a= *b;
	*b= temp;
}
void bubbleSort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(arr[i]>arr[j])
				swap(&arr[i],&arr[j]);
}
void display(int* arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int n,i;
	
	printf("Enter the size of array : ");
	scanf("%d",&n);
	
	int *arr = malloc(n*sizeof(int));
	char *str[n],buff[n];
	
	printf("Enter %d elements : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	bubbleSort(arr,n);
	for(int i = 0 ; i < n ; i++)
	{
		snprintf(buff,n,"%d",arr[i]);
		str[i+1] = strdup(buff); 
	}
	str[0] = malloc(9);
	strcpy(str[0],"child");
	str[n+1] = NULL;
		
	pid_t pid = fork();
	wait(NULL);
	
	if(pid < 0)
		printf("Error\n");
	
	else if(pid > 0)
	{
		printf("Sorted array : ");
		display(arr,n);
	}

	else if(pid == 0)
	{
		execve("child", str, NULL);
		perror("execve"); 
	}
}

