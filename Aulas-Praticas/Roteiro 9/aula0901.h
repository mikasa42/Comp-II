/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021-1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves 
Descricao: Prototipo das funcoes do roteiro 9
$Author: mikaela.alves $ 
$Date: 2021/10/12 22:42:16 $ 
$Log: aula0901.h,v $
Revision 1.1  2021/10/12 22:42:16  mikaela.alves
Initial revision


*/


#ifndef _AULA0901_
#define _AULA0901_  "@(#)aula0901.h $Revision: 1.1 $"
#endif

#ifdef __linux__
#define _BSD_SOURCE  || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif
/*Macros*/

#define BUFFER   16
#define COMPRIMENTO_BUFFER   100


/* Prototipo da funcao*/


/*enum eh enumerado*/

typedef  unsigned char byte;

typedef enum
{
	ok,
	valorInvalido,
	memoriaInsuficiente,
	erroAbrindoArquivo
}tipoErros;

tipoErros
ExibirConteudoArquivo (char *nomeArquivo);

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *nomeArquivo, char *nomeConvertido);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *nomeArquivo, char *nomeConvertido);

/*$RCSfile: aula0901.h,v $*/
