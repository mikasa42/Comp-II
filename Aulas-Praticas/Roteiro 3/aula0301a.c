/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o fibonacci

$Author: mikaela.alves $
$Date: 2021/08/10 22:42:33 $
$Log: aula0301a.c,v $
Revision 1.1  2021/08/10 22:42:33  mikaela.alves
Initial revision




*/


#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include "aula0301.h"



ull CalcularMaximoDivisorComum (ull num1, ull num2){
ull a, b;
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

    if (a%b == 0)
        return b;
    else
        return CalcularMaximoDivisorComum(b, a%b);
  
}



/*$RCSfile: aula0301a.c,v $*/
