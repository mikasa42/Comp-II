/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : CODIGO PARA VALIDAR CPF 
$Author$
$Date$
$Log: aula0502a.c,v $
Revision 1.2  2021/08/28 19:22:39  mikaela.alves
primeira versao

Revision 1.1  2021/08/24 23:29:36  mikaela.alves
Initial revision



*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula0501.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>

/*macros com letra maiuscula */

#define VALOR_INVALIDO	      3
#define NUM_ARGS_INVALIDO      1
#define OK                   0
#define END_OF_STRING        '\0'

int main(int  argc,char * argv[]){
	
	int  x = 0;
	unsigned short int cont = 0;
	char *end;
	byte cpf [digitos];

	if(argc !=  10){
		printf("\n Numero de argumentos invalidos\n\n");
		exit(NUM_ARGS_INVALIDO);
	}

	
	for(cont = 1; cont<argc; cont++)
	{
		x = strtoull(argv[cont],&end,10);
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
		if(x < 0 || x > 9)
		{
			printf("\n Comprimento do argumento invalido : %d\n\n", x);
			exit(VALOR_INVALIDO);
		}
		cpf[cont-1] = x;

	}
	GerarDigitosVerificadoresCpf(cpf);
	printf("\n");
	for(cont = 0; cont<11; cont++)
	{
		if(cont == 0)
			printf("CPF:");
		if(cont == 9)
			printf("/");
		printf("%u",cpf[cont]);
	}
	printf("\n\n");

return ok;
}
/*$RCSfile: aula0502a.c,v $*/
