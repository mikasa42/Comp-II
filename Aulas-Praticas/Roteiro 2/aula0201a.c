/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao: codigo fonte pra calcular o fibonacci

$Author: mikaela.alves $
$Date: 2021/08/05 21:10:32 $
$Log: aula0201a.c,v $
Revision 1.1  2021/08/05 21:10:32  mikaela.alves
Initial revision

*/


#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include "aula0201.h"



ull CalcularTermoSerieFibonacci(us n){

    if (n == 0)
        return  0;
    if (n == 1)
        return 1;
    else
        return CalcularTermoSerieFibonacci(n - 1) + CalcularTermoSerieFibonacci(n - 2);
  
}



/*$RCSfile: aula0201a.c,v $*/
