/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Codigo para calcular exponencial

$Author: mikaela.alves $
$Date: 2021/08/17 22:52:06 $
$Log: aula0402.c,v $
Revision 1.1  2021/08/17 22:52:06  mikaela.alves
Initial revision








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
#include "aula04.h"
#include <errno.h>
#include <math.h>

/*macros com letra maiuscula */
#define numArgs               1

#define ValorExcedidoUs       3
#define ValorExcedidoFuncao   4
#define BaseInvalida	      5

#define numArgs_invalido  1
#define ok                0
#define ValorUll_naoSuportado  2
#define END_OF_STRING        '\0'


int main(int  argc,char * argv[]){
	
	double  x;
	int  n;

	char *end;
	if(argc != 3){
		printf("\n\n Numero de argumentos invalidos");
		exit(numArgs_invalido);
	}
	x = strtod((argv[1]), &end);
	if (*end != END_OF_STRING)
	{
		printf("Argumento 1 contem caractere invalido\n");
		exit(numArgs_invalido);
	}
	n = strtoul((argv[2]), &end, 10);
	if (*end != END_OF_STRING)
	{
		printf("Argumento 1 contem caractere invalido\n");
		exit(numArgs_invalido);
	}
	
	if(errno == ERANGE)
	{
		printf("Valor maximo permitido para uma LD foi excedido.\n");
		exit(ValorExcedidoFuncao);
	}
	if(errno == EINVAL)
	{
		printf("Base invalida");
		exit(BaseInvalida);
	}

	printf("base(%.10lf)expoente(%d) = (%.10Lf)\n\n",x,n,CalcularExponencial(x,n));
return ok;
}
/*$RCSfile $*/
