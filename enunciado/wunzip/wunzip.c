#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool esNum(char c);

int main(int argc, char ** args)
{
	FILE *file;
	
	if (argc==1)
	{
		printf("wunzip: file1 [file2 ...]\n");
		return 1;
	}
	else  
	{
		char num[2];
		int iter=-1;// -1 if avail
		for(int i=1;i<argc;i++)//por cada ducmento
		{
			int cuantos=1;
			file=fopen(args[i], "r");
			//if(fread(b,sizeof(b),1,file)!=1)
			//{printf("IS NOT REAIDNG");exit(1);}//else{printf(b);}
			
			while(!feof(file))//for(int j=0;j<sizeof(b);j++)//for each char on buffer
			{
				//printf("E\n");
				char c=fgetc(file);
				if(c==EOF){break;}				
				bool loes=esNum(c);//es un unmero
				if(loes)//add to num
				{
					if(iter==-1){num[0]=c;iter=0;}
					else{num[iter+1]=c;iter++;}
					//printf("aqui para %c \n",c);
				}else
				{			
					//hay que pegar los digitos de num
					if(iter!=-1)
					{					
						if(iter==0)
						{	
							cuantos=num[0]-'0';
							//printf("CUANTOS : %i \n",cuantos);
						}
						else
						{cuantos=atoi(num);}
						
						//iter=-1;
					
						for(int l=0;l<cuantos;l++)
						{
							printf("%c",c);
						}
						cuantos=1;
						iter=-1;
						//printf("\n");
					}
					else{printf("%c",c);}
					
				}
			  
			}fclose(file);
			
	}
}
return 0;

}
bool esNum(char c)
{
	int es=	c-'0';
	if(es<10&&es>-1)
		{
			return true;
		}
	return false;
}

