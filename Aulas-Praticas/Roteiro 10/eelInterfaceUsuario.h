/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021-1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves 
Descricao:
$Author: mikaela.alves $ 
$Date: 2021/10/18 20:44:21 $ 
$Log: eelInterfaceUsuario.h,v $
Revision 1.1  2021/10/18 20:44:21  mikaela.alves
Initial revision


*/


#ifndef _EELINTERFACEUSUARIO_
#define _EELINTERFACEUSUARIO_  "@(#)eelInterfaceUsuario.h $Revision: 1.1 $"

#ifdef __linux__
#define _BSD_SOURCE  || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif
/*Macros*/

#include "eelTipos.h"

#define eelQuantidadeIdiomas     2
#define eelQuantidadeErros       5

/*enum eh enumerado*/
typedef enum
{
	mensagem,
	usuario,
	senha,
	botao
}eelTipoNumerosMensagemInterfaceUsuario;


char *
EelObterMensagemInterfaceUsuarioCli(eelTipoIdiomas, eelTipoNumerosMensagemInterfaceUsuario);

char *
EelObterMensagemInterfaceUsuarioWeb (eelTipoIdiomas, eelTipoNumerosMensagemInterfaceUsuario );


#endif
/*$RCSfile: eelInterfaceUsuario.h,v $*/
