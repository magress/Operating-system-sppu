#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

//merge sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}




//quick sort
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
		sleep(3);	//zombie
		printf("\nParent, pid = %d and child is %d\n",getpid(), pid);
		mergeSort(arr, 0, n-1);
		printf("\nBy Merge Sort[Parent]\n");
		printf("Sorted array : ");
    	printArray(arr, n);
    	printf("\n");
	}
	else
	{
		//sleep(3);		//orphan
		printf("\nChild pid = %d and its parent is %d\n",getpid(),getppid());
		quickSort(arr, 0 ,n-1);
		printf("\nBy Quick Sort[Child]\n");
		printf("Sorted array : ");
    	printArray(arr, n);
    	printf("\n");		
	}
	
		
	system("ps -l");
	return 0;
}
