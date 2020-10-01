#include <stdio.h>
#include <string.h>

int comparar(char palabra[], char linea[]);

//  {}  \  []
int main(int argc, char ** args){
	FILE *file;

	// Detalle 5
	if (argc < 2){
		printf("wgrep: searchterm [file ...]\n");
		return 1;
	}

	else if (argc == 2) {
		file = fopen(args[1], "r");
		// Detalle 8
		if(file == NULL){
			char *palabra = args[1];
			char *linea = NULL;
			size_t len = 0;
			ssize_t lineSize = 0;
			while((lineSize = getline(&linea, &len, stdin)) != -1){	   // Detalle 4			
				linea[lineSize-1] = '\0';
				if(comparar(palabra, linea))
					printf("%s\n", linea);
			}
		}
		else
			fclose(file);			// Detalle 9 no retorna nada
	}

	else{
		char *palabra = args[1];
		char *linea = NULL;
		size_t len;

		for(int i = 2; i < argc; i++){             // Detalle 1
			file = fopen(args[i], "r");

			// Detalle 6
			if(file == NULL){
				printf("wgrep: cannot open file\n");
				return 1;
			}

			len = 0;
			
			// Detalle 2
			while(getline(&linea, &len, file) != -1){   // Detalle 4
				if(comparar(palabra, linea))
					printf("%s", linea);
			}
				
		}
	}
		
	return 0;       // Detalle 7
}

// Detalle 3
int comparar(char palabra[], char linea[]){

	if (strstr(linea, palabra) != NULL) {
	   	 return 1;
	} else {
		return 0;
	}

}