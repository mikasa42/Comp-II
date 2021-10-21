/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021-1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves 
Descricao: Prototipo da funcao

$Author $ 
$Dat$ 
$Log: aula0504.h,v $
Revision 1.1  2021/09/03 19:56:05  mikaela.alves
Initial revision

*/



#ifndef _AULA0504_
#define _AULA0504_  "@(#)aula0504.h $Revision: 1.1 $"



/* Prototipo da funcao*/

 



typedef enum
{
	OK,
	CPF_INVALIDO
}tipoErros;

tipoErros
GerarDigitosVerificadoresCpf (char *cpf ,char *DV1 ,char *DV2) ;

tipoErros
ValidarCpf (char*);


#endif 
/*$RCSfile: aula0504.h,v $*/
