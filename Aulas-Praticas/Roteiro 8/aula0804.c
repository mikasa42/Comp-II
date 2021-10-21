
/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao 
EEL270 - Computacao II - Turma 2021/1 
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: Implementa a funcao decodificar base 16. 

Author:$
$Date: 2021/10/02 19:04:37 $ 
$Log: aula0804.c,v $
Revision 1.1  2021/10/02 19:04:37  mikaela.alves
Initial revision


 
*/


#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif


#include "aula0801.h"

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
#define MEMORIA_INSUFICIENTE                            8
#define ALFABETO_INVALIDO                               9 


int main (int argc, char *argv [])
{
	
	char *validacao;
	
	char *saida;
	unsigned long long numeroBytes[1];
	char  *entrada;
	tipoAlfabetoBase32 alfabeto;

	unsigned short indice;

	byte *vetorBytes;


	if (argc < 4) 
	{
		printf ("Uso: <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo> \n");
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);		
	}
	

	if(argv[1][0] == '-')
	{	
		printf ("Argumento caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}

	
	
	  
	if(argv[1][0] == '0')
		alfabeto = alfabetoNormal;

	if(argv[1][0] == '1')
		alfabeto =  alfabetoEstendido;

	if(argv[1][0] != '0' && argv[1][0] != '1')
	{
		printf ("Argumento invalido.\n");
		exit (ALFABETO_INVALIDO);
	}

	numeroBytes[0] = strtoull(argv [2], &validacao, 10);



		
		
		
/*----------------Alocando memoria---------------------*/
	entrada = malloc(sizeof(char[(argc-3)*2+1]));

	if( entrada == NULL)
	{
		printf (" memoria insuficiente");
		exit (MEMORIA_INSUFICIENTE);
	}

	saida = malloc(sizeof(char[numeroBytes[0]*2+1]));

	if( entrada == NULL)
	{
		printf (" memoria insuficiente");
		exit (MEMORIA_INSUFICIENTE);
	}

	vetorBytes = malloc(sizeof(byte[numeroBytes[0]*2]));

	if( entrada == NULL)
	{
		printf (" memoria insuficiente");
		exit (MEMORIA_INSUFICIENTE);
	}


/*-------------------------------------------------------*/
	
	for(indice = 3; indice < argc; indice++)
	{
		strcat(entrada,argv[indice]);
	}

	
	DecodificarBase16 (entrada, vetorBytes, numeroBytes);
	
	CodificarBase32 (vetorBytes, numeroBytes[0], alfabeto, saida);

	printf ("\n %s \n\n", saida);


return OK;
}

/* RCSfile$ */
