#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main()
{
	char buf[1024],fname[10];
	int fd,fd1;
	system("rm test1.txt");	
	system("touch test1.txt");		//Create empty file
	fd=open("test1.txt",O_WRONLY);	// open file in write only mode
	printf("\nEnter the message::");
	gets(buf);
    write(fd,buf,strlen(buf));		// write data into the file
	close(fd);
	
	printf("\nEnter the filename to read::");
	scanf("%s",fname);
	fd1=open(fname,O_RDONLY);		// open file in read only mode
	if(fd1!=3)
	{
		printf("File does not exist\n");
		exit(0);
	}
	read(fd1,buf,sizeof(buf));		// read the contents of file into buffer and print it
	printf("\nFile contents are -> %s\n",buf);
	close(fd1);						// close a file
	return 0;
}
