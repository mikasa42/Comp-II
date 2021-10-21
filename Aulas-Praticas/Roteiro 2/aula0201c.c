/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o fibonacci

$Author: mikaela.alves $
$Date: 2021/08/05 22:47:55 $
$Log: aula0201c.c,v $
Revision 1.1  2021/08/05 22:47:55  mikaela.alves
Initial revision

Revision 1.1  2021/08/05 21:10:32  mikaela.alves
Initial revision

*/


#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include "aula0201.h"



ull CalcularTermoSerieFibonacci(us n){
	ull fib1, fib2, indice;
	ull fibonacci;

	fib1 = 0;
	fib2 = 1;
	fibonacci = 0;
	if(n == 0)
	{
		return fibonacci; 
	}
	for(indice = 1;  indice <= n; indice++)
	{
		fib1 = fibonacci + fib2;
		fibonacci = fib2;
		fib2 = fib1;
	}		


	        return fibonacci;  
}


/*$RCSfile: aula0201c.c,v $*/
