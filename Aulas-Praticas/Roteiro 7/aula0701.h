/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021-1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves 
Descricao: Prototipo da funcao Mostrar monitor

$Author: mikaela.alves $ 
$Date: 2021/09/19 23:53:52 $ 
$Log: aula0701.h,v $
Revision 1.4  2021/09/19 23:53:52  mikaela.alves
Roteiro 7 - Arquivo com todas as funcoes

Revision 1.3  2021/09/19 05:37:48  mikaela.alves
Roteiro 7 - prototipo da funcao desenhar reta

Revision 1.2  2021/09/18 01:46:47  mikaela.alves
Roteiro 7 - Limpar monitor

Revision 1.1  2021/09/18 01:40:20  mikaela.alves
Initial revision


*/


#ifndef _AULA0701_
#define _AULA0701_  "@(#)aula0701.h $Revision: 1.4 $"

#ifdef __linux__
#define _BSD_SOURCE  || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif

#include <time.h>
#include <unistd.h>

#ifdef __linux__
typedef __useconds_t useconds_t;
#endif


/* Prototipo da funcao*/
#define NUMERO_MAXIMO_LINHAS      250
#define NUMERO_MAXIMO_COLUNAS     800
#define APAGADO                   '-'
#define	ACESO	                  '+'
#define DEFEITUOSO                 'X'



/*enum eh enumerado*/


typedef enum 
{
	apagado,
	aceso,
	defeituoso
}tipoPixel;

typedef enum
{
	ok,
	linhaInvalida,
	bordaPoligono

}tipoErros;

tipoErros 
MostrarMonitor (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas, 
		useconds_t tempoEspera);

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas);
  

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas, 
		unsigned linhaA, 
		unsigned colunaA, 
		unsigned linhaB, 
		unsigned colunaB);


tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas, 
		unsigned numeroVertices, 
		unsigned linhasVertices[NUMERO_MAXIMO_LINHAS], 
		unsigned colunasVertices[NUMERO_MAXIMO_COLUNAS]);
tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas, 
		unsigned linha, 
		unsigned coluna, 
		useconds_t tempoEspera);
#endif 
/*$RCSfile: aula0701.h,v $*/
