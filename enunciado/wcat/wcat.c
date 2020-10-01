#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char** argv)
{
 FILE* file;   
 if(argc==1)
	{
		//printf("NOTHING HERE \n");
		exit(0);
	}
	else
	{
		for(int i=1;i<argc;i++)
			{
				file=fopen(argv[i],"r");
				if(file==NULL)
				{
					printf("wcat: cannot open file\n");
					//fclose(file);
					 exit(1);
				}
				char  line[1000];
				while(fgets(line,1000,file)!=NULL)
					{
						//puts(line);
					 printf("%s",line);
									
					}
				//printf("\n");
				fclose(file);
					
		       }
		
 		exit(0);
       }
 	
}
