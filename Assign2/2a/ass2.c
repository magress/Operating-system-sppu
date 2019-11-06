#include<stdio.h>
#include<stdlib.h>
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

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
	int i,n;
    printf("Enter the Size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements : ", n);
    for(i=0;i<n;i++)
    	scanf("%d",&arr[i]);
    
    pid_t pid = fork();
	//wait(NULL);

   	if(pid < 0)
		printf("Error");
	else if(pid > 0)
	{
		//sleep(3);	//zombie
		printf("\nParent, pid = %d and child is %d\n",getpid(), pid);
		bubbleSort(arr,n-1);
		printf("\nBy bubble Sort[Parent]\n");
		printf("Sorted array : ");
    	printArray(arr, n);
    	printf("\n");
	}
	else
	{
		sleep(3);		//orphan
		printf("\nChild pid = %d and its parent is %d\n",getpid(),getppid());
		bubbleSort(arr, n-1);
		printf("\nBy Quick Sort[Child]\n");
		printf("Sorted array : ");
    	printArray(arr, n);
    	printf("\n");		
	}
	
		
	system("ps -l");
	return 0;
}
