
/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao 
EEL270 - Computacao II - Turma 2021/1 
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: Implementa a funcao Desenhar poligono

Author$
$Date: 2021/09/19 23:52:55 $ 
$Log: aula0705.c,v $
Revision 1.1  2021/09/19 23:52:55  mikaela.alves
Initial revision



*/


#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif


#include "aula0701.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include <errno.h>

#define OK						0
#define NUMERO_ARGUMENTOS_INVALIDO			1
#define COMPRIMENTO_ARGUMENTO_INVALIDO			2	
#define VALOR_MAXIMO_EXCEDIDO				4
#define BASE_INVALIDA					5
#define ARGUMENTO_NEGATIVO				6
#define END_OF_STRING					'\0'
#define ARGUMENTO_INVALIDO				1
#define LINHA_INVALIDA                                  7
#define NUMERO_VERTICES_INVALIDO                        8
int main (int argc, char *argv [])
{

	char *validacao;
	unsigned short numeroLinha, numeroColuna, linha, coluna;
	long int variavelLonga;
	useconds_t tempoEspera;
	tipoErros status;
	tipoPixel matriz[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	unsigned indice, vertices,numVertices, indiceLinha, indiceColuna;
	
	unsigned linhasVertices[NUMERO_MAXIMO_LINHAS];
	unsigned colunasVertices[NUMERO_MAXIMO_COLUNAS];
	if (argc < 8) 
	{
		printf ("Uso: <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo> ... <numero-inteiro-nao-negativo> \n");
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);		
	}
	if (argv[1][0] == '-' && argv[2][0] == '-' && argv[3][0] == '-' && argv[4][0] == '-' && argv[5][0] == '-' && argv[6][0] == '-'&&argv[7][0]  == '-'&& argv[8][0] == '-')
	{
		printf ("\n Argumento contem hifen.\n");
		exit (ARGUMENTO_NEGATIVO);
	}

	variavelLonga = strtoul (argv [1], &validacao, 10);  
	linha = variavelLonga;

	if (errno == EINVAL) /* base invalida */
	{
		printf ("\n Base invalida.\n");
		exit (BASE_INVALIDA);
	}
	if (*validacao != END_OF_STRING)
	{
		printf ("\n Argumento caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}
	variavelLonga = strtoul (argv [2], &validacao, 10);  
	coluna = variavelLonga;

	if (errno == EINVAL) /* base invalida */
	{
		printf ("\n Base invalida.\n");
		exit (BASE_INVALIDA);
	}	
	if (*validacao != END_OF_STRING)
	{
		printf ("\n Argumento caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}
	variavelLonga = strtoul (argv [3], &validacao, 10);  
	tempoEspera = variavelLonga;
	
	if (errno == EINVAL) /* base invalida */
	{
		printf ("\n Base invalida.\n");
		exit (BASE_INVALIDA);
	}

	if (*validacao != END_OF_STRING)
	{
		printf ("\n Argumento caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (*validacao != END_OF_STRING)
	{
		printf ("\n Argumento caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}
	variavelLonga = strtoul (argv [4], &validacao, 10);  
	vertices = variavelLonga;
	
	if (errno == EINVAL) /* base invalida */
	{
		printf ("\n Base invalida.\n");
		exit (BASE_INVALIDA);
	}

	if (*validacao != END_OF_STRING)
	{
		printf ("\n Argumento caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}
	numVertices = (argc-5)/2;
	if(numVertices != vertices)
	{
		printf ("\n numero de vertices invalido.\n");
		exit (NUMERO_VERTICES_INVALIDO);
	}
	

	indiceLinha = 0;
	indiceColuna = 0;
	for (indice = 5; indice < argc; indice++)
	{
		if(argv[indice][0] == '-')
		{
			printf ("\nArgumento contem hifen.\n\n");
			exit (ARGUMENTO_NEGATIVO);

		}
		
		if(indice%2 !=0)
		{

			variavelLonga = strtoul (argv [indice], &validacao, 10);  
			linhasVertices[indiceLinha]= variavelLonga;			
		
			if (errno == EINVAL) /* base invalida */
			{
				printf ("\nBase invalida.\n");
				exit (BASE_INVALIDA);
			}

			if (*validacao != END_OF_STRING)
			{
				printf ("\nArgumento caractere invalido.\n");
				exit (ARGUMENTO_INVALIDO);
			}
			indiceLinha++;

		}

		if(indice%2 ==0)
		{

			variavelLonga = strtoul (argv [indice], &validacao, 10);  
			colunasVertices[indiceColuna]= variavelLonga;
			if (errno == EINVAL) /* base invalida */
			{
				printf ("\nBase invalida.\n");
				exit (BASE_INVALIDA);
			}

			if (*validacao != END_OF_STRING)
			{
				printf ("\nArgumento caractere invalido.\n");
				exit (ARGUMENTO_INVALIDO);
			}
			indiceColuna++;	
		}
	}

	
 
/*
        rand()%3 --> escolhe entre 0 a 2*/
	srand(time(NULL));
/*	srand eh a semente de  randomico. cada vez que que roda o programava eh necessario para 
	  criar uma semente para escolher uma nova seuqnecai de possibilidades
*/
	for (numeroLinha = 0; numeroLinha < linha; numeroLinha++)
	{
	  for (numeroColuna = 0; numeroColuna < coluna; numeroColuna++)
	  {
	    matriz[numeroLinha][numeroColuna] = rand()%3;
	    
	  }
	}
	  
	MostrarMonitor(matriz, linha, coluna, tempoEspera);

	LimparMonitor(matriz, linha, coluna);

	status = DesenharPoligono( matriz,linha,coluna,vertices, linhasVertices, colunasVertices);
	
	if(status == linhaInvalida)
	{	
		system("clear");	
		printf ("Erro na funcao, pixels com defeito \n");
		exit(LINHA_INVALIDA);
	}

	MostrarMonitor(matriz, linha, coluna, tempoEspera);


	
return OK;
}

/* RCSfile$ */
