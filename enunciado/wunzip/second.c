#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool esNum(char c);

int main(int argc, char ** args)
{
	FILE *file;	
	file=fopen(args[1], "r");
	char b[5];
	if(fread(b,5,1,file)!=1)
	{printf("IS NOT REAIDNG");exit(1);}//else{printf(b);}
	for(int i=0;i<5;i++)
	{
		printf("%c",b[i]);
	}
}


