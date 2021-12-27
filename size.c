#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main(void)
{
	 int count=0;
	 FILE *fp;
	 struct dirent *file;
	 DIR *dr=opendir("/home/user");
	 if (dr == NULL)
	 {
		  printf("directory not found");
		  return 0;
	 }
	 while((file=readdir(dr)) != NULL)
	 {
		    count ++;
		    printf("%s\n",file->d_name);
		    fp=fopen(file->d_name,"r");
		    if (fp == NULL)
		    {
		      printf("files not fount \n");
		      return 0;
		     }
		      fseek(fp,0L,SEEK_END); 
		      long int size=ftell(fp);
		      printf("size of file %ld bytes \n",size);
	 
	 }
	 printf("total file is:%d\n",count);
	 closedir(dr);
	 fclose(fp);
	 return 0;
}
