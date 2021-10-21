/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : codigo para verificacao de cpf 
$Author: mikaela.alves $
$Date: 2021/09/03 20:49:56 $
$Log: aula0505b.c,v $
Revision 1.3  2021/09/03 20:49:56  mikaela.alves
primeira versao

*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula0504.h"

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
	char cpf [11];
	char digito10[1];
	char digito11[1];

	if(argc !=  2){
		printf("\n Numero de argumentos invalidos\n\n");
		exit(NUM_ARGS_INVALIDO);
	}

	
	if(strlen(argv[1]) < 11 || strlen(argv[1]) > 11)
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
		cpf[indice] = x + '0';
		indice ++;

	}

	if(indice != 9){
		
		printf("\n esperado : \"<x1><x2><x3>.<x4><x5><x6>.<x7><x8><x9>\"\n\n");
		exit(VALOR_INVALIDO);
	}
	/*  digito10 -- > dessa forma eu estou indicado o endereco desta variavel
	   *digito10--> Aqui eu estou com valor da variavel como digito10[0] */

	GerarDigitosVerificadoresCpf(cpf, digito10, digito11);
	printf("\n");
	for(cont = 0; cont<9; cont++)
	{
		if(cont == 0)
			printf("CPF:");
		if(cont == 3 || cont == 6)
			printf(".");
		if(cont == 9)
			printf("/");
		printf("%c",cpf[cont]);
	
	}
	printf("/%c%c\n\n", digito10[0],digito11[0]);

return OK;
}
/*$RCSfile: aula0505b.c,v $*/
