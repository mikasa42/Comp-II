/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o exponencial

$Author $
$Date: 2021/08/18 00:30:54 $
$Log: aula0401c.c,v $
Revision 1.1  2021/08/18 00:30:54  mikaela.alves
Initial revision





*/

#include <math.h>
#include <limits.h>


long double CalcularExponencial (double x, int n){
long double exponencial, exponencial_negativa;
int indice;
    if (x == 0 && n < 0 )
#if defined (__STRICT_ANSI__) && defined(__linux__)
	    return 1.0/0.0;
#else
    return INFINITY;
#endif
exponencial = 1;
exponencial_negativa = 1;
	

	if(n == 0)
		return 1;
	if(n > 0 )
	{
		for(indice = 0; indice< n; indice++)	
		{
			exponencial  = exponencial * x;
			
		}	
		return exponencial;
	}
	if(n < 0)
	{	
		for(indice = n; indice< 0; indice++)
		{
			exponencial_negativa  = exponencial_negativa * x;
		}
		return 1/exponencial_negativa;
	}
  return 0;
}



/*$RCSfile: aula0401c.c,v $*/
