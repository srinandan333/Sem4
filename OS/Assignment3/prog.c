#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
    DIR *dir;
    dir = opendir(".");
    if(dir==NULL)
    {
        printf("Error while opening directory\n");
    }

    struct dirent *ptr;
    ptr = readdir(dir);
    struct stat st;
    FILE *fp;

    long int size;
    printf("Enter the constraint size in bytes: ");
    scanf("%ld",&size);
	
    while(ptr!=NULL)
    {
        fp=fopen(ptr->d_name,"r");
        int num = fileno(fp);
        if(fstat(num,&st)!= -1)
        {
            if(st.st_size<size)
            {
                printf("Name: %s \t Size: %ld bytes\n",ptr->d_name,st.st_size);
            }
        }
        fclose(fp);
        ptr = readdir(dir);
    }
    closedir(dir);
}