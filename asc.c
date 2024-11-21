#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
typedef struct
{
	char *name;
	off_t size;
}
FileInfo;
void bubblesort(FileInfo arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j].size>arr[j+1].size)
			{
				FileInfo temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("Usage:%s<filename>\n",argv[0]);
		return 1;
	}
	int file_cnt=argc-1;
	FileInfo *files=malloc(file_cnt* sizeof(FileInfo));
	struct stat buffer;
	for(int i=0;i<file_cnt;i++)
	{
		if (stat(argv[i+1],&buffer)==0)
		{
			files[i].name=argv[i+1];
			files[i].size=buffer.st_size;
		}
	}
	bubblesort (files,file_cnt);
	printf("Files in ascending order is:\n\n");
	for(int i=0;i<file_cnt;i++)
	{
		printf("%d:%s(%ld bytes)\n",i+1,files[i].name,files[i].size);
	}
	free(files);
	return 0;
}
		
