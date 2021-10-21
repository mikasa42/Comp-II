/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o exponencial

$Author $
$Date: 2021/08/18 00:30:31 $
$Log: aula0401b.c,v $
Revision 1.1  2021/08/18 00:30:31  mikaela.alves
Initial revision





*/

#include <math.h>
#include <limits.h>


long double CalcularExponencial (double x, int n){
long double exponencial, exponencial_negativa;

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
		do
		{
			exponencial  = exponencial * x;
			n = n - 1;
			
		}
		while (n != 0 && n>0);	
		return exponencial;
	}
	if(n < 0)
	{	
		do
		{
			exponencial_negativa  = exponencial_negativa * x;
			n = n + 1;
		}
		while (n != 0 && n<0);
		return 1/exponencial_negativa;
	}
  return 0;
}



/*$RCSfile: aula0401b.c,v $*/
