#include<stdio.h>
#include<iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    //Open file
    FILE *file1=fopen("output.txt","a");
    
    
    //Get string from user
    char name[10];
    char number[10];
    scanf("%s",name);
    scanf("%s",number);
    
    //print(write) string to file
    
    if(file1==NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    
    fprintf(file1,"%s,%s\n",name,number);
    
    //close file
    fclose(file1);
    
    //read from file
    
    FILE *file2=fopen("output.txt","r");
    
    if(file2== NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    //reac char from file
    char ch;
    ch=fgetc(file2);
    
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(file2);
    }
    
    fclose(file2);

    return 0;
}
