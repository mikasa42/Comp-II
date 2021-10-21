/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : codigo para validar cpf
$Author: mikaela.alves $
$Date: 2021/09/03 20:30:26 $
$Log: aula0506b.c,v $
Revision 1.2  2021/09/03 20:30:26  mikaela.alves
terceira vers√ao

Revision 1.1  2021/09/03 20:03:00  mikaela.alves
Initial revision


*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula0504.h"

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
#define VALOR_MAXIMO          2
#define END_OF_STRING        '\0'

int main(int  argc,char * argv[]){
	
	int  x = 0;
	unsigned short int cont = 0,indice = 0;
	
	char cpf [11];

	tipoErros statusCpf;
	if(argc !=  2){
		printf("\n Numero de argumentos invalidos\n\n");
		exit(NUM_ARGS_INVALIDO);
	}

	
	if(strlen(argv[1]) != 14)
	{
	
		printf("\n esperado sao 14 caracteres\n\n");
		exit(VALOR_MAXIMO);
	}
	for(cont = 0; cont<strlen(argv[1]); cont++)
	{
		if(argv[1][cont] == '.'|| argv[1][cont] == '/'){
			cont = cont +1;
		}

		x = argv[1][cont] - '0';
	
		if(x < 0 || x > 9)
		{
			printf("\n Comprimento do argumento invalido : %c\n\n", argv[1][cont]);
			exit(VALOR_INVALIDO);
		}		
		
		cpf[indice] = x + '0';
		indice++;
	}
	if(indice != 11){
		
		printf("\n esperado :\"<x1><x2><x3>.<x4><x5><x6>.<x7><x8><x9>/<x10><x11>\"\n\n");
		exit(VALOR_INVALIDO);
	}

	statusCpf = ValidarCpf(cpf);
	printf("\n");

	for(cont = 0; cont<11; cont++)
	{
		if(cont == 3 || cont == 6)
			printf(".");
		if(cont == 0)
			printf("CPF:");
		if(cont == 9)
			printf("/");
		printf("%c",cpf[cont]);
		
	}
	if(statusCpf == CPF_INVALIDO)
		printf("- invalido");
	if(statusCpf == OK)
		printf("- valido");
	printf("\n\n");

return OK;
}
/*$RCSfile: aula0506b.c,v $*/
