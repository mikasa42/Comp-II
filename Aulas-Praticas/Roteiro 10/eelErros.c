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
$Date: 2021/10/18 20:44:21 $
$Log: eelErros.c,v $
Revision 1.1  2021/10/18 20:44:21  mikaela.alves
Initial revision


*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

#include "eelTipos.h"
#include "eelErros.h"
#include <stdio.h>
#include <stdlib.h>

#define OK						0
#define eelQuantidadeIdiomas				2
#define eelQuantidadeErros				4

char *eelMensagensErro [eelQuantidadeIdiomas] [eelQuantidadeErros] =
{
	{"Sucesso","Erro relacionado com arquivo","Erro alocando memória","Senha incorret"},
	{"Ok","File error","Memory alocation error","Invalid password"}
};

char *EelObterMensagemErroCli (eelTipoIdiomas idioma, eelTipoErros erros)
{
	return ok;
}

char *EelObterMensagemErroWeb (eelTipoIdiomas idioma, eelTipoErros erros )
{

	return ok;
}


/*$RCSfile: eelErros.c,v $*/
