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
$Log: aula0501.h,v $
Revision 1.1  2021/08/24 23:30:20  mikaela.alves
Initial revision








*/



#ifndef _AULA0501_
#define _AULA0501_  "@(#)aula0501.h $Revision: 1.1 $"



/* Prototipo da funcao*/

#define digitos        13  


typedef unsigned char byte;
typedef enum
{
	ok,
	cpfInvalido
}tipoErros;

tipoErros
GerarDigitosVerificadoresCpf (byte []);

tipoErros
ValidarCpf (byte []);


#endif 
/*$RCSfile: aula0501.h,v $*/
