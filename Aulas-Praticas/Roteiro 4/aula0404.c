/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Codigo para calcularSerieHarmonicaAlternada
$Author $
$Date $
$Log$


*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula04.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>

/*macros com letra maiuscula */
#define ValorExcedidoUs       3
#define ValorExcedidoFuncao   4
#define BaseInvalida	      5
#define numArgs_invalido      1
#define ok                    0
#define Valor_maximo_us  2
#define END_OF_STRING        '\0'

int main(int  argc,char * argv[]){
	
	float  x;
	unsigned short int cont = 0;
	char *end;
	float SerieHarmonica = 0, SerieHarmonicaSecundario = 0, modSerie = 0;

	if(argc !=  2){
		printf("\n\n Numero de argumentos invalidos");
		exit(numArgs_invalido);
	}
	x = strtof((argv[1]), &end);
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
	if(x > USHRT_MAX)
	{
		printf("Entrada excede o valor maximo permitido para \"unsigned short\"(%hu)\n ",(unsigned short)USHRT_MAX);
		exit(Valor_maximo_us);
	}
	while(modSerie > x*SerieHarmonicaSecundario || SerieHarmonicaSecundario == 0)
	{
		SerieHarmonicaSecundario = SerieHarmonica;
		SerieHarmonica = CalcularSerieHarmonicaAlternada(cont);
		printf("S(%hu) = %.10f\n", cont,CalcularSerieHarmonicaAlternada(cont));
		cont++;
		if((SerieHarmonica - SerieHarmonicaSecundario) > 0)
		{
			modSerie = SerieHarmonica - SerieHarmonicaSecundario;
		}
		if((SerieHarmonica - SerieHarmonicaSecundario) <=  0)
		{
			modSerie = SerieHarmonicaSecundario - SerieHarmonica;
		}
	}
	if(cont >= 10)
	{
		printf("Valor maximo da funcao foi alcancado. \n");
	}


return ok;
}
/*$RCSfile$*/
