/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o fibonacci

$Author: mikaela.alves $
$Date: 2021/08/05 22:44:05 $
$Log: aula0202.c,v $
Revision 1.2  2021/08/05 22:44:05  mikaela.alves
Segunda versao

Revision 1.1  2021/08/05 21:10:53  mikaela.alves
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
#include "aula0201.h"
#include <errno.h>

/*macros com letra maiuscula */
#define numArgs               1
#define ArgNegativo           2
#define ValorExcedidoUs       3
#define ValorExcedidoFuncao   4
#define numArgs_invalido  1
#define ok                0
#define ValorUll_naoSuportado  2
#define END_OF_STRING        '\0'
/*
	verificar se n é negativo e se é um numero real 
*/
int main(int  argc,char * argv[]){
	
	unsigned short  n;
	
	char *end;
	n = strtoull((argv[1]), &end, 10);
	
	if(argc != 2){
		printf("\n\n Numero de argumentos invalidos");
		exit(numArgs_invalido);
	}
	if (argv [1][0] == '-')
	{
		printf("Argumento contem hifen.\n");
		exit(ArgNegativo);
	}
	if(errno > 93)
	{
		printf("valor maximo permitido(%lu) pela funcao foi excedido:\n", ULONG_MAX);
		exit(ValorExcedidoFuncao);
	}
	if (*end != END_OF_STRING)
	{
		printf("Argumento 1 contem caractere invalido\n");
		exit(numArgs_invalido);
	}
	if(n > 93)
	{
		printf("Entrada excede o valor maximo permitido para \" unsigned short\"(%hu)\n",(unsigned short) USHRT_MAX);
	
		exit(ValorExcedidoUs);
	}

	
	
	
	unsigned short indiceArgumentos = 0;
	
	for (indiceArgumentos = 0; indiceArgumentos<= n; indiceArgumentos++)	
	{
		printf("F(%d) = %llu \n",indiceArgumentos, CalcularTermoSerieFibonacci(indiceArgumentos));
	}

return ok;
}



/*$RCSfile: aula0202.c,v $*/
