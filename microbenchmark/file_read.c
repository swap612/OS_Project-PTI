#include <stdio.h>
#include <stdlib.h>
     
int main(int argc, char **argv)
{
      
        FILE *fp, *fp1;
	char* file_name = argv[1]; 
	printf("Filename: %s",file_name);     
        fp = fopen(file_name, "r"); // read mode
     
        if (fp == NULL)
        {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
        }
     
        char ch; 
        int i=0;
	unsigned long start_time, end_time;
	//start_time = __rdtscp();
	while(i<100000){
		fseek(fp, 0, SEEK_SET);
		fp1 = fp;
		printf("The contents of %s file are:\n", file_name);

		while((ch = fgetc(fp1)) != EOF)
	        	printf("%c", ch);
		i++;
	}     
        fclose(fp);
        return 0;
}
