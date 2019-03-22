#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <x86intrin.h>
#include<sys/time.h>
     
int main(int argc, char **argv)
{
      
        FILE *fp, *fp1;
	char* file_name = argv[1]; 
 	unsigned long itr_count = atoi(argv[2]);	
	//printf("Filename: %s",file_name);     
        fp = fopen(file_name, "wr"); // write mode
     
        if (fp == NULL)
        {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
        }
     
        char ch; 
        int i=0;
	unsigned long start_time, end_time;
	int j;
       	time_t sec1, sec2;
       	clock_t begin, end;
	struct timeval starts, ends;
	//time(&sec1);
	//start_time = __rdtscp(&j);
	//begin = clock();
	gettimeofday(&starts, NULL);
	while(i<itr_count)
	{
		fputs("Writing to a file by\n",fp);	//writing 20 bytes
		i++;
	
	}
	gettimeofday(&ends, NULL);
	//end = clock();
	//end_time = __rdtscp(&j)- start_time;
	//time(&sec2);
	//printf("\nCPU ticks: %ld \t time: %lf sec \n",end_time,(double)( end_time/2808));
	//printf("\nTime: %ld %ld %ld \n",sec1, sec2, sec2 - sec1);
	unsigned long seconds = ends.tv_sec - starts.tv_sec;
	unsigned long  micro = ((seconds *1000000)+ends.tv_usec )-starts.tv_usec;
	//printf("\nClock Time in sec : %ld \n", (end-begin)/CLOCKS_PER_SEC);
	printf("%ld \n", micro);						
	fclose(fp);
        return 0;
}

