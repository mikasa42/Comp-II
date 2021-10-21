/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Codigo para multiplicar matrizes
$Author $
$Date $
$Log: aula0602.c,v $
Revision 1.1  2021/08/31 23:07:51  mikaela.alves
Initial revision


*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula0601.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>

/*macros com letra maiuscula */

#define VALOR_INVALIDO	      3
#define NUM_ARGS_INVALIDO      1
#define OK                    0
#define END_OF_STRING        '\0'

int main(int  argc,char * argv[]){
	
	unsigned long int  x = 0;
	char *end;
  	int indiceLinha = 0;
  	int indiceColuna = 0;
  	int indiceArgumento = 5;

	unsigned short  numeroLinha1 = 0;
	unsigned short  numeroColuna1 = 0;

	unsigned short  numeroLinha2 = 0;
	unsigned short  numeroColuna2 = 0;

	double matriz1 [LINHA][COLUNA];
	double matriz2 [LINHA][COLUNA]; 
	double matrizProduto[LINHA][COLUNA];
	
	
	
	
	if(argc < 7){
		printf("\n Numero de argumentos invalidos\n\n");
		exit(NUM_ARGS_INVALIDO);
	}

/*Verificando numeros de linha da matriz 1 */
	x = strtoul(argv[1],&end,10);
	numeroLinha1 = x;

	if(errno == EINVAL)
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}	
	if(errno == ERANGE )
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	/* Quando o valor nao eh convertido /char --> int/ ele é guardado na vaiavel end*/	
	if(*end != END_OF_STRING)
	{	
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	if(x != numeroLinha1)
	{	
		printf("\n Comprimento do argumento invalido : %lo\n\n", x);
		exit(VALOR_INVALIDO);
	}

	
/*Verificando numeros de coluna da matriz 1 */
	x = strtoul(argv[2],&end,10);
	numeroColuna1 = x;

	if(errno == EINVAL)
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}	
	if(errno == ERANGE )
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	/* Quando o valor nao eh convertido /char --> int/ ele é guardado na vaiavel end*/	
	if(*end != END_OF_STRING)
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	if(x != numeroColuna1)
	{
		printf("\n Comprimento do argumento invalido : %lo\n\n", x);
		exit(VALOR_INVALIDO);
	}

/*Verificando numeros de linha da matriz 2 */
	x = strtoul(argv[3],&end,10);
	numeroLinha2 = x;

	if(errno == EINVAL)
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}	
	if(errno == ERANGE )
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	/* Quando o valor nao eh convertido /char --> int/ ele é guardado na vaiavel end*/	
	if(*end != END_OF_STRING)
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	if(x != numeroLinha2)
	{
		printf("\n Comprimento do argumento invalido : %lo\n\n", x);
		exit(VALOR_INVALIDO);
	}

/*Verificando numeros de coluna da matriz 2 */
	x = strtoul(argv[4],&end,10);
	numeroColuna2 = x;

	if(errno == EINVAL)
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}	
	if(errno == ERANGE )
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	/* Quando o valor nao eh convertido /char --> int/ ele é guardado na vaiavel end*/	
	if(*end != END_OF_STRING)
	{
		printf("\nBase invalida\n\n");
		exit(VALOR_INVALIDO);
	}
	if(x != numeroColuna2)
	{
		printf("\n Comprimento do argumento invalido : %lo\n\n", x);
		exit(VALOR_INVALIDO);
	}

	if(numeroColuna1 != numeroLinha2)
		exit(VALOR_INVALIDO);	
  
	for (indiceLinha = 0; indiceLinha < numeroLinha1; indiceLinha++)
	{

		for (indiceColuna = 0; indiceColuna < numeroColuna1; indiceColuna++)
		{
			matriz1 [indiceLinha][indiceColuna] = strtod(argv[indiceArgumento],&end);
			indiceArgumento++;
			if(errno == EINVAL)
			{
				printf("\nBase invalida\n\n");
				exit(VALOR_INVALIDO);
			}	
			if(errno == ERANGE )
			{
				printf("\nBase invalida\n\n");
				exit(VALOR_INVALIDO);
			}
			/* Quando o valor nao eh convertido /char --> int/ ele é guardado na vaiavel end*/	
			if(*end != END_OF_STRING)
			{
				printf("\nBase invalida\n\n");
				exit(VALOR_INVALIDO);
			}

		}
	}

  	
	for (indiceLinha = 0; indiceLinha < numeroLinha2; indiceLinha++)
	{

		for (indiceColuna = 0; indiceColuna < numeroColuna2; indiceColuna++)
		{
			matriz2 [indiceLinha][indiceColuna] = strtod(argv[indiceArgumento],&end);
			indiceArgumento++;
			if(errno == EINVAL)
			{
				printf("\nBase invalida\n\n");
				exit(VALOR_INVALIDO);
			}	
			if(errno == ERANGE )
			{
				printf("\nBase invalida\n\n");
				exit(VALOR_INVALIDO);
			}
			/* Quando o valor nao eh convertido /char --> int/ ele é guardado na vaiavel end*/	
			if(*end != END_OF_STRING)
			{
				printf("\nBase invalida\n\n");
				exit(VALOR_INVALIDO);
			}

		}
	}
  	MultiplicarMatrizes(numeroLinha1, numeroColuna1, numeroLinha2, numeroColuna2, matriz1, matriz2, matrizProduto);

	printf("\n");
  	printf(" ---- Matriz resultado -----\n\n");
	for (indiceLinha = 0; indiceLinha < numeroLinha1; indiceLinha++)
	{

		for (indiceColuna = 0; indiceColuna < numeroColuna2; indiceColuna++)
		{
			printf("%.05lf | ",matrizProduto[indiceLinha][indiceColuna]);


		}
	
		printf("\n\n");
	}

return OK; 
}
/*$RCSfile: aula0602.c,v $*/
