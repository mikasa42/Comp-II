/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : codigo para verificacao de cpf 
$Author $
$Date $
$Log $





*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula0501.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>

/*macros com letra maiuscula */

#define VALOR_INVALIDO	      3
#define NUM_ARGS_INVALIDO     1
#define OK                    0
#define VALOR_MAXIMO          2
#define END_OF_STRING        '\0'

int main(int  argc,char * argv[]){
	
	int  x = 0;
	unsigned short int cont = 0, indice = 0;
/*	char *end;*/
	byte cpf [digitos];

	if(argc !=  2){
		printf("\n Numero de argumentos invalidos\n\n");
		exit(NUM_ARGS_INVALIDO);
	}

	if(strlen(argv[1]) != 11)
	{
		printf("\nO valor maximo de caracteres pela funcao foi excedido\n\n");
		exit(VALOR_MAXIMO);
	}
	if(strlen(argv[1]) < 11)
	{
		printf("\nO valor esperado  de caracteres pela funcao eh 11 \n\n");
		exit(VALOR_MAXIMO);
	}
	for(cont = 0; cont<strlen(argv[1]); cont++)
	{
		if(argv[1][cont] == '.'){
			cont = cont +1;
			
		}
		x = argv[1][cont] - '0';
		if(x < 0 || x > 9)
		{
			printf("\n caractere do argumento invalido : %c\n\n",argv[1][cont] );
			exit(VALOR_INVALIDO);
		}
		cpf[indice] = x;
		indice ++;

	}
	GerarDigitosVerificadoresCpf(cpf);
	printf("\n");
	for(cont = 0; cont<11; cont++)
	{
		if(cont == 0)
			printf("CPF:");
		if(cont == 3 || cont == 6)
			printf(".");
		if(cont == 9)
			printf("/");
		printf("%u",cpf[cont]);
	}
	printf("\n\n");

return OK;
}
/*$RCSfile: aula0502b.c,v $*/
