#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int a[100][100],b[100][100],c[100][100];
int size,xy;

void* fun(void* g)
{
	int h = (int) g;
	int i,j,l,k;
	int sum=0,p_size;

	int start,end;
	start=h;
	end=h+1;
	printf("Thread no %d created\n",h+1);
	sleep(xy);

	for (i = start; i < end; i++)
    {
    	for (j = 0; j < size; j++)
        {
        	printf("Thread no %d is multiplying row %d to column %d\n",h+1,i+1,j+1);
            c[i][j] = 0;
            for (k = 0; k < size; k++)
                c[i][j] += a[i][k]*b[k][j];
        	sleep(1);
        }
    }     
}

int main(int argc, char const *argv[])
{
	int m,n,p,q,r,i,j,k,l,chk;
	printf("Enter the size for 1st matrix(RxC) : ");
	scanf("%d%d",&m,&n);
	xy = m;
	printf("Enter the elements\n");
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j <n ; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	

	printf("Enter the size for 2nd matrix(RxC) : ");
	scanf("%d%d",&p,&q);
	printf("Enter the elements\n");
	for (i = 0; i < p; ++i)
	{
		for (j = 0; j <q ; ++j)
		{
			scanf("%d",&b[i][j]);
		}
	}
	
	

	if(n==p)
	{
		chk=m;
		if(q>m)
		chk=q;
		pthread_t threads[chk];
		size = chk;
		for (int i = 0; i < chk; ++i)
		{
			pthread_create(&threads[i],NULL,fun,(void *)i);
			sleep(1);
		}
		for (int i = 0; i < chk; ++i)
		{
			pthread_join(threads[i],NULL);
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < q; ++j)
			{
				printf("%d\t",c[i][j] );
			}
			printf("\n");
		}
	}
	else
	{
		printf("\nMATRIX MULTIPLICATION NOT POSSIBLE\n");
	}
	return 0;
}
