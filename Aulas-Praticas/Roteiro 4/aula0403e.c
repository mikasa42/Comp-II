/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular uma serie harmonica alterada

$Author: mikaela.alves $
$Date: 2021/08/21 17:34:03 $
$Log: aula0403e.c,v $
Revision 1.1  2021/08/21 17:34:03  mikaela.alves
Initial revision







*/

#include <math.h>
#include "aula04.h"
#define   ok       0


float  CalcularSerieHarmonicaAlternada (unsigned short int termo){	

	if(termo == 0){
		return 0;
	}
	for(; termo > 0; termo--){
		if(termo%2 == 0)
			return (-1/pow(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1));
		else	
			return (1/pow(termo,termo)+ CalcularSerieHarmonicaAlternada(termo-1));
	}
return ok;
}


/*$RCSfile: aula0403e.c,v $*/
