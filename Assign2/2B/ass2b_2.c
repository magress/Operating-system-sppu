#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int binarySearch(int arr[],int l,int h,int key)
{
	while(l<=h)
	{
		int mid=l+((h-l)/2);
		if(arr[mid] == key)
			return mid;
		else if(arr[mid]<key)
			return binarySearch(arr,mid+1,h,key);
			//l=mid+1;
		else
			return binarySearch(arr,l,mid-1,key);
			//h=mid-1;
	}
	return -1;
}
int main(int argc, char* argv[], char *envp[])
{
	int i,value,n=0,arr[20];
	for(i=0;argv[i+1] != NULL;i++)
	{
		arr[i] = atoi(argv[i+1]);
		n++;
	}

	printf("\nEnter the value to be searched :\n");
	scanf("%d",&value);
	
	int x = binarySearch(arr,0,n-1,value);
	if(x == -1)
		printf("\nValue not found\n");
	else
		printf("\nThe required value found at position %d\n",x+1);
	return 0;
}
