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
$Log: eelTipos.h,v $
Revision 1.1  2021/10/18 20:44:21  mikaela.alves
Initial revision


*/


#ifndef _EELTIPOS_
#define _EELTIPOS_  "@(#)eelTipos.h $Revision: 1.1 $"

#ifdef __linux__
#define _BSD_SOURCE  || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif
/*Macros*/


/*enum eh enumerado*/
typedef enum
{
	eelPortugues,
	eelIngles 
}eelTipoIdiomas;


#endif
/*$RCSfile: eelTipos.h,v $*/
