
/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao 
EEL270 - Computacao II - Turma 2021/1 
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Alves
Descricao: Implementacao da matriz transposta

$Author: mikaela.alves $
$Date: 2021/09/09 23:36:12 $ 
$Log: aula0603.c,v $
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
#define BASE_INVALIDA	 			5
#define END_OF_STRING				'\0'
#define ARGUMENTO_INVALIDO 			1





int main (int argc, char *argv [])
{
	int indice, linha, coluna;
	char *validacao;
	unsigned short numero, numeroLinha, numeroColuna;
	unsigned long int numeroExcedido;
	double matrizE[LINHA][COLUNA], matrizT[LINHA][COLUNA];

	if (argc < 4) /* O valor minimo da de entrada deve ser 1 + 2 (linhas e colunas) + 1 (matriz minima 1x1 */
	{
		printf ("Uso: <numero-linhas-matriz-1> <numero-colunas-matriz-1> <numero-real> ... <numero-real> \n"); 
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);		
	}

	for (indice = 1; indice < 3; indice++)
	{ 
		numeroExcedido = strtoul (argv [indice], &validacao, 10);  
				
		if (errno == EINVAL) /* base invalida */
		{
			printf ("Base invalida.\n");
			exit (BASE_INVALIDA);														}	
		if (*validacao != END_OF_STRING)
		{
			printf ("Argumento caractere invalido.\n");
			exit (ARGUMENTO_INVALIDO);
																			}

		numero = (unsigned short) numeroExcedido;
		if (numero != numeroExcedido)
		{
			printf ("Valor maximo para funcao excedido.\n");
			exit (VALOR_MAXIMO_EXCEDIDO);
																			}
													
		if (indice == 1)
			numeroLinha = numero;
		if (indice == 2)
			numeroColuna = numero;
	}	

	if (argc != 3 + numeroLinha*numeroColuna)
	{
		printf ("Argumentos invalidos (%d).\n", argc);
		exit (ARGUMENTO_INVALIDO);
	}
		
		indice = 3;


	 for (linha = 0; linha < numeroLinha; linha++)
	 {
		 for (coluna = 0; coluna < numeroColuna; coluna++)
		 {
			 matrizE[linha][coluna] = strtod (argv [indice], &validacao);
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
				printf ("Argumento caractere invalido.\n");
				exit (ARGUMENTO_INVALIDO);
						
      			}
    		}		
	}


	ObterMatrizTransposta(numeroLinha, numeroColuna, matrizE, matrizT);

	printf ("Matriz transposta \n[");

	for (coluna = 0; coluna < numeroColuna; coluna++)
	{		  
		printf ("[");
		for (linha = 0; linha < numeroLinha; linha++)
		{
			printf ("%0.05lf ", matrizT[coluna][linha]);
		}
		if (coluna != numeroColuna - 1)
			printf ("]\n");
		else
			printf ("]]\n");
	}

return OK;
}

/* RCSfile$ */



