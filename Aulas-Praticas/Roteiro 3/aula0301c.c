/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o fibonacci

$Author: mikaela.alves $
$Date: 2021/08/12 05:14:56 $
$Log: aula0301c.c,v $
Revision 1.1  2021/08/12 05:14:56  mikaela.alves
Initial revision





*/


#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include "aula0301.h"



ull CalcularMaximoDivisorComum (ull num1, ull num2){
ull a, b, r, indice;
    if (num1 >= num2)
	{
		a = num1;
		b = num2;
	}
    else
    {
	    a = num2; 
	    b = num2;
    }
    for(indice = 0; indice<=a; indice++) 
    {
	    if(a%b != 0)
	    {
		    r = a%b;
		    a = b;
		    b = r;
	    }

    }
  
    return b;
  
}



/*$RCSfile: aula0301c.c,v $*/
