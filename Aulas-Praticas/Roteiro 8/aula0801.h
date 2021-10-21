/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021-1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves 
Descricao: Prototipo das funcoes do roteiro 8
$Author: mikaela.alves $ 
$Date: 2021/10/02 19:07:41 $ 
$Log: aula0801.h,v $
Revision 1.1  2021/10/02 19:07:41  mikaela.alves
Initial revision
:

*/


#ifndef _AULA0801_
#define _AULA0801_  "@(#)aula0801.h $Revision: 1.1 $"
#endif

#ifdef __linux__
#define _BSD_SOURCE  || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif
/*Macros*/

#define COMPRIMENTO_BUFFER   100


/* Prototipo da funcao*/


/*enum eh enumerado*/

typedef  unsigned char byte;

typedef enum
{
	ok,
	valorInvalido,
	memoriaInsuficiente
}tipoErros;

typedef enum
{
	alfabetoNormal = 0,
	alfabetoEstendido = 1
}tipoAlfabetoBase32;

typedef enum 
{
	desabilitado = 0,
	habilitado = 1
}tipoFinalLinha;

tipoErros
CodificarBase16 (byte* vetorBytes , unsigned long long numerosBytes, char * saida);


tipoErros
DecodificarBase16 (char *entrada, byte *vetorBytes, unsigned long long *numeroBytes);


tipoErros
CodificarBase32 (byte * vetorBytes, unsigned long long numeroBytes, tipoAlfabetoBase32 alfabeto , char * saida);


tipoErros
DecodificarBase32 (char *entrada, tipoAlfabetoBase32 alfabeto, byte *vetorBytes, unsigned long long *numeroBytes);


tipoErros
CodificarBase64 (byte * vetorBytes, unsigned long long numeroBytes, tipoFinalLinha finalLinha, char * saida);

tipoErros
DecodificarBase64 (char *entrada, tipoFinalLinha finalLinha, byte *vetorBytes, unsigned long long *numeroBytes);

tipoErros 
TransformarDecimalBinario(byte *vetorBytes, char *bin);

tipoErros
TransformarBinarioDecimal(char *bin,  byte *vetorBytes);
/*$RCSfile: aula0801.h,v $*/
