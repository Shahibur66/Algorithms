#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*

-->To run on command line:

     gcc -o check_file jpegFileCheck.cpp
     check_file accuracy.gif

*/
int main(int argc, char *argv[])
{
   
   if(argc!=2)
   {
       return 1;
   }
   
   FILE *file=fopen(argv[1],"r");
   
   if(file==NULL)
   {
       return 1;
   }
   
   //read 3 bytes from file
   
   unsigned char bytes[1];
   
   fread(bytes,3,1,file);
   
   // check if bytes 0xff 0xd8 0xff
   
   if(bytes[0]==0xff && bytes[1]==0xd8 && bytes[2]==0xff)
   {
       printf("Maybe\n");
   }
   else{
       printf("No\n");
   }
   
  FILE * pFile;
  
  char buffer[] = { 'x' , 'y' , 'z' };
  
  pFile = fopen ("myfile1.txt", "w");
  
  fwrite (buffer,sizeof(char),sizeof(char),pFile);
  
  fclose (pFile);

    return 0;
}
