/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular uma serie harmonica alterada

$Author: mikaela.alves $
$Date: 2021/08/21 17:32:57 $
$Log: aula0403a.c,v $
Revision 1.1  2021/08/21 17:32:57  mikaela.alves
Initial revision







*/



#include "aula04.h"

float  CalcularSerieHarmonicaAlternada (unsigned short int termo){
   

	if(termo == 0)
	{
		return 0;
	}
	if(termo%2 == 0)
	{
		return -1/CalcularExponencial(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1);
	}
	if(termo%2 !=0)
	{
		return 1/CalcularExponencial(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1);
	}
	return 0;
}




/*$RCSfile: aula0403a.c,v $*/
