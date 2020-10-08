#include <stdio.h>

//  {}  \  []
int main(int argc, char ** args){
	
	// Detalle 1
	if(argc < 2){
		printf("wzip: file1 [file2 ...]\n");
		return 1;
	}

	FILE *file;
	int contC = 1;
	char c, cAnt = '\0';

	// Detalle 3
	for(int i = 1; i < argc; i++){
		file = fopen(args[i], "r");
		
		while ((c = fgetc(file)) != EOF){
			if(cAnt == '\0'){
				cAnt = c;
			}
			else if(c == cAnt){
				contC++;
				cAnt = c;
			}
			else{
				// Detalle 2
				fwrite(&contC, 4, 1, stdout);
				fwrite(&cAnt, 1, 1, stdout);
				contC = 1;
				cAnt = c;
			}
		}
	}

	// Detalle 2
	fwrite(&contC, 4, 1, stdout);
	fwrite(&cAnt, 1, 1, stdout);

	return 0;
}