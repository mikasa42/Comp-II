/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular uma serie harmonica alterada

$Author: mikaela.alves $
$Date: 2021/08/21 17:33:16 $
$Log: aula0403b.c,v $
Revision 1.2  2021/08/21 17:33:16  mikaela.alves
segunda verao

Revision 1.1  2021/08/21 15:38:18  mikaela.alves
Initial revision




*/



#include "aula04.h"

float  CalcularSerieHarmonicaAlternada (unsigned short int termo){

	if(termo == 0)
	{
		return 0;
	}
	do 
	{
		if(termo%2 == 0)
			return -1/CalcularExponencial(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1);

		else	
			return 1/CalcularExponencial(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1);
	--termo;
	}
	while(termo > 0);

}




/*$RCSfile: aula0403b.c,v $*/
