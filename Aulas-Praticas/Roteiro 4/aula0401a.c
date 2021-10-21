/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o exponencial

$Author: mikaela.alves $
$Date: 2021/08/17 22:50:47 $
$Log: aula0401a.c,v $
Revision 1.1  2021/08/17 22:50:47  mikaela.alves
Initial revision




*/

#include <math.h>
#include <limits.h>

long double CalcularExponencial (double x, int n){

    if (x == 0 && n < 0 )
#if defined (__STRICT_ANSI__) && defined(__linux__)
	    return 1.0/0.0;
#else
    return INFINITY;
#endif

    if (n == 0)
	{
		return 1;
	}
    if(n>0)
    {
	   return x*CalcularExponencial(x,n-1);
    }
    else
    {

	   return (1/x)*CalcularExponencial(x,n+1);
    }

}



/*$RCSfile: aula0401a.c,v $*/
