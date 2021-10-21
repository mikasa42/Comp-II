
/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao 
EEL270 - Computacao II - Turma 2021/1 
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: Programa que implementa a funcao para calcular o determinante de uma matriz

$Author: mikaela.alves $
$Date: 2021/09/09 23:36:12 $ 
$Log: aula0604.c,v $
Revision 1.1  2021/09/09 23:36:12  mikaela.alves
Initial revision

 
*/


#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif


#include "aula0601.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include <errno.h>

#define OK					0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define COMPRIMENTO_ARGUMENTO_INVALIDO		2	
#define VALOR_MAXIMO_EXCEDIDO			4
#define BASE_INVALIDA				5
#define NUMERO_NEGATIVO				6
#define END_OF_STRING				'\0'
#define ARGUMENTO_INVALIDO			1

int main (int argc, char *argv [])
{
	int indice = 0, linha, coluna;
	char *validacao;
	unsigned short ordem;
	unsigned long int numeroExcedido;
	double matriz[LINHA][COLUNA], det[0];

	if (argc < 3) /* O valor minimo da de entrada deve ser 1 + ordem + matriz (minimo 1 elemento) */
	{
		printf ("Uso: <numero-inteiro-nao-negativo> <numero-real> ... <numero-real> \n"); 
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);		
	}
		
	if (argv[1][0] == '-')
	{
		printf ("Argumento contem hifen.\n");
		exit (NUMERO_NEGATIVO);
	}

	numeroExcedido = strtoul (argv [1], &validacao, 10);  
	
	if (errno == EINVAL) /* base invalida */
	{
		printf ("Base invalida.\n");
		exit (BASE_INVALIDA);
	}

	if (*validacao != END_OF_STRING)
	{
		printf ("Argumento caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	ordem = (unsigned short) numeroExcedido;
	if (ordem != numeroExcedido)
	{
		printf ("Valor maximo para funcao excedido.\n");
		exit (VALOR_MAXIMO_EXCEDIDO);
	}
	
	if (argc != 2 + ordem*ordem)
	{
		printf ("A ordem (%d) da matriz nao corresponde ao numero de elementos (%d).\n", ordem, argc - 2);
		exit (ARGUMENTO_INVALIDO);
	}

  for (linha = 0; linha < ordem; linha++)
  {
    for (coluna = 0; coluna < ordem; coluna++)
    {
      matriz[linha][coluna] = strtod (argv [indice + 2], &validacao);
      indice++;

      if (errno == EINVAL) /* base invalida */
      {
        printf ("Base invalida.\n");
        exit (BASE_INVALIDA);
      }

      if (errno == ERANGE) /* valor maximo excedido */
      {
        printf ("Valor maximo permitido (%lf) pela funcao foi excedido.\n", DBL_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
      }
		
			if (*validacao != END_OF_STRING)
			{
				printf ("Argumento contem caractere invalido.\n");
				exit (ARGUMENTO_INVALIDO);
			}
		}
  }
	
	printf ("Matriz\n[");

	for (linha = 0; linha < ordem; linha++)
  {
		printf ("[");
    for (coluna = 0; coluna < ordem; coluna++)
    {
			printf ("%0.05lf ", matriz[linha][coluna]);
		}
		if (linha != ordem - 1)
			printf ("]\n");
		else
			printf ("]]\n");
	}

	CalcularDeterminanteMatriz (ordem, matriz, det);
	printf ("Determinante = %lf \n", *det);

	return OK;
}

/* RCSfile$ */
