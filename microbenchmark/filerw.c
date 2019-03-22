#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <x86intrin.h>
#include<sys/time.h>
     
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
/*	while(i<100000){
		fseek(fp, 0, SEEK_SET);
		fp1 = fp;
		printf("The contents of %s file are:\n", file_name);

		while((ch = fgetc(fp1)) != EOF)
		i++;
	}
*/	int j;
       	time_t sec1, sec2;
       	clock_t begin, end;
	struct timeval starts, ends;
	start_time = __rdtscp(&j);
	gettimeofday(&starts, NULL);
	time(&sec1);
	begin = clock();
	while((ch = fgetc(fp)) != EOF);
//	       	printf("%c", ch);
	end_time = __rdtscp(&j)- start_time;
	gettimeofday(&ends, NULL);
	time(&sec2);
	end = clock();
	printf("\nCPU ticks: %ld \n",end_time);
	printf("\nTime: %ld %ld %ld \n",sec1, sec2, sec2 - sec1);
	int seconds = ends.tv_sec - starts.tv_sec;
	int micro = ((seconds *1000000)+ends.tv_usec )-starts.tv_usec;
	printf("\nClock Time: %ld \n", (end-begin)/CLOCKS_PER_SEC);
	printf("\nClock in usec Time: %d \n", micro);						
	fclose(fp);
        return 0;
}
