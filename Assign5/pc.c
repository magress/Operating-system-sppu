#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int buf[5];
pthread_mutex_t m;
sem_t empty,full;
void *producer(void *arg)
{
  printf("\nProducer is created");
  sleep(1);
   int n,i=0;
  while(1)
  {
     sem_wait(&empty);
     pthread_mutex_lock(&m);
     n=random()%10;
     buf[i++]=n;
     printf("\nNumber %d  is added at %d",n,i);
     if(i==5)i=0;
     pthread_mutex_unlock(&m);
     sem_post(&full);
     sleep(1);
  }  
}

void *consumer(void *arg)
{
  printf("\nConsumer is created");
  sleep(1);
  int key,i=0;
  while(1)
  {
     sem_wait(&full);
     pthread_mutex_lock(&m);
     key=buf[i++];
     printf("\nNumber %d is consumed %d",key,i);
     if(i==5)i=0;
     pthread_mutex_unlock(&m);
     sem_post(&empty);
     sleep(2);
  }
}

int main(){
  pthread_mutex_init(&m,NULL);
  sem_init(&empty,0,5);
  sem_init(&full,0,0);
  pthread_t pid,cid;
  pthread_create(&pid,NULL,producer,NULL);
  sleep(1);
  pthread_create(&cid,NULL,consumer,NULL);
  sleep(1);
  pthread_join(pid,NULL);
  pthread_join(cid,NULL);
  
}
