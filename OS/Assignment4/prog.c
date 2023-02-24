/* 
Write a C program to truncate 
the files in a directory created 
after a certain date.
Inputs to the program: 
directory and date of creation 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    DIR *d;
    struct dirent *dir;
    struct stat stats;
    struct tm dt;
    char dirname[256];
    int date, month, year;

    printf("Enter directory ('.' for current directory): ");
    fflush(stdout);
    scanf("%s", dirname);

    d = opendir(dirname);

    printf("Enter date: ");
    fflush(stdout);
    scanf("%d", &date);
    printf("Enter month: ");
    fflush(stdout);
    scanf("%d", &month);
    printf("Enter year: ");
    fflush(stdout);
    scanf("%d", &year);
    if (!d)
    {
        printf("Error opening directory!");
        exit(0);
    }
    while ((dir = readdir(d)))
    {
        if (stat(dir->d_name, &stats) == 0)
        {
            dt = *gmtime(&stats.st_ctime);
            int d = dt.tm_mday;
            int m = dt.tm_mon;
            int y = dt.tm_year + 1900;
            if (year < y)
                printf("File: %s\n", dir->d_name);
            else if (month < m)
                printf("File: %s\n", dir->d_name);
            else if (date < d)
                printf("File: %s\n", dir->d_name);
        }
        else
        {
            printf("Error reading file: %s", dir->d_name);
        }
    }
    closedir(d);
    return 0;
}