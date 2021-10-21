/*
 *
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza

Autor: Mikaela Rikberg Alves
Descricao:

$Author: mikaela.alves $
$Date: 2021/10/16 16:41:08 $
$Log: aula0903.c,v $
Revision 1.1  2021/10/16 16:41:08  mikaela.alves
Initial revision



*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula0901.h"

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
#define ERRO_ABRINDO_ARQUIVO 				9
#define ERRO_LENDO_ARQUIVO 				9
#define COMPRIMENTO_LINHA 				10000


int main (int argc, char *argv[])
{
	tipoErros resultado;
	
	if(argc < 2) 
	{
		printf ("\nUso: %s <arquivo> <arquivo> \n\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO) ;	
	}
	
	resultado = ConverterArquivoFormatoUnixParaFormatoDos (argv[1],argv[2]);
	
	if(resultado != ok)
	{
		exit(ERRO_LENDO_ARQUIVO);
	}
	return ok;
}

/* $RCSfile: aula0903.c,v $ */
