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
$Log: eelInterfaceUsuario.c,v $
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


#include "eelInterfaceUsuario.h"
#include <stdio.h>
#include <stdlib.h>

#define OK		


char *eelMensagensInterfaceUsuarioWeb [eelQuantidadeIdiomas] [eelQuantidadeErros] =
{
	{"Boas vindas","Usuario","Senha","Botao"},
	{"Welcome","Username","Passwors","button"}
};

char *eelMensagensInterfaceUsuarioCli [eelQuantidadeIdiomas] [eelQuantidadeErros] =
{
	{"Boas vindas","Usuario","Senha","Botao"},
	{"Welcome","Username","Passwors","button"}
};



char *
EelObterMensagemInterfaceUsuarioCli (eelTipoIdiomas idioma, eelTipoNumerosMensagemInterfaceUsuario numero)
{
	return eelMensagensInterfaceUsuarioCli [idioma][numero];
}

char *
EelObterMensagemInterfaceUsuarioWeb (eelTipoIdiomas idioma, eelTipoNumerosMensagemInterfaceUsuario numero)
{
	return eelMensagensInterfaceUsuarioWeb [idioma][numero];
}


/*$RCSfile: eelInterfaceUsuario.c,v $*/
