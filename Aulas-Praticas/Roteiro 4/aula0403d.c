/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular uma serie harmonica alterada

$Author: mikaela.alves $
$Date: 2021/08/21 17:33:52 $
$Log: aula0403d.c,v $
Revision 1.2  2021/08/21 17:33:52  mikaela.alves
segunda versao

Revision 1.1  2021/08/21 15:39:18  mikaela.alves
Initial revision




*/



#include "aula04.h"
#define ok   0

float  CalcularSerieHarmonicaAlternada (unsigned short int termo){
	
	

	if(termo == 0)
	{
		return 0;
	}
	 
	while(termo > 0)
	{
		if(termo%2 == 0)
			return -1/CalcularExponencial(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1);

		else	
			return 1/CalcularExponencial(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1);
	--termo;
	}
	
return ok; 


}




/*$RCSfile: aula0403d.c,v $*/
