
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMERO_HIFENS           80


void ExibirSeparador(void){
	int indice = 0;
	printf("\n");
	while (indice <= NUMERO_HIFENS)
	{	printf("-");
		indice ++;
	}
	printf("\n\n");
}
size_t tamStrlen(const char *str){
	const char *p = str;
	while(*p !=  '\0')
		++p;
return p - str;
}

int main (int argc, char *argv[]){
	int letras;
	int tam;

	tam = 0;
	for (letras = 1; letras<argc;letras++){
		tam = tam + tamStrlen(argv[letras]);

	}
	if (tam >50){
		printf("nome invalido");
}	
		
	ExibirSeparador();
	int cont;
	int centro;


	centro = (80-argc-tam)/2;
	for (cont = 1; cont <= centro; cont ++){
		printf(" ");

	}
	printf("\"");

	for(cont = 1; cont < argc; cont++){

		printf("%s", argv[cont]);
		if(cont +1 != argc){
			printf(" ");
		}
	}
	printf("\"");
	ExibirSeparador();	

/*	
	string str1;
	char str2;
	char nome[MAX];
	int i;
	if(argc>1){
		for(i=1; i<=argc; i++){

			str1 = argv[1];
			str2 = argv[i+1];

			strcat(strcpy(nome, str1), str2);
			printf("%s\n", nome);
		}
	}

*/
return 0;
}

