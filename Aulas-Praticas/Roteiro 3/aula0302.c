/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Código para calcular o maximo divisor comum 

$Author: mikaela.alves $
$Date $
$Log: aula0302.c,v $
Revision 1.3  2021/08/12 20:24:51  mikaela.alves
Terceira versao

Revision 1.2  2021/08/12 05:13:00  mikaela.alves
Segunda versao







*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include "aula0301.h"
#include <errno.h>

/*macros com letra maiuscula */
#define numArgs               1
#define ArgNegativo           2
#define ValorExcedidoUs       3
#define ValorExcedidoFuncao   4
#define BaseInvalida	      5
#define ValoresZerados        6
#define numArgs_invalido  1
#define ok                0
#define ValorUll_naoSuportado  2
#define END_OF_STRING        '\0'
int main(int  argc,char * argv[]){
	
	ull  num1;
	ull  num2;

	char *end;
	if(argc != 3){
		printf("\n\n Numero de argumentos invalidos");
		exit(numArgs_invalido);
	}
	if (argv [1][0] == '-')
	{
		printf("Argumento contem hifen.\n");
		exit(ArgNegativo);
	}

	if (argv [2][0] == '-')
	{

		printf("Argumento contem hifen.\n");
		exit(ArgNegativo);
	}
	num1 = strtoull((argv[1]), &end, 10);
	num2 = strtoull((argv[2]), &end, 10);
	if (*end != END_OF_STRING)
	{
		printf("Argumento 1 contem caractere invalido\n");
		exit(numArgs_invalido);
	}
	if(num1 == 0 || num2 == 0 )
	{
		printf("X e Y são iguais a 0");
		exit(ValoresZerados);
	}
	if(num1 == ULONG_MAX)
	{
		printf("Valor maximo (%lu)permitido para uma Ull foi excedido.\n", ULONG_MAX);
		exit(ValorExcedidoFuncao);
	}
	
	if(num2 == ULONG_MAX)
	{
		printf("Valor maximo (%lu)permitido para uma Ullfoi excedido.\n", ULONG_MAX);
		exit(ValorExcedidoFuncao);
	}
	if(errno == EINVAL)
	{
		printf("Base invalida");
		exit(BaseInvalida);
	}

	printf("MDC(%llu) (%llu) = (%llu)\n\n",num1,num2,CalcularMaximoDivisorComum(num1, num2));
return ok;
}



/*$RCSfile: aula0302.c,v $*/
