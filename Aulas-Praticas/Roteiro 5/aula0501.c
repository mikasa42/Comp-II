/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Codigo para calcularSerieHarmonicaAlternada
$Author $
$Date $
$Log: aula0501.c,v $
Revision 1.1  2021/08/24 23:29:58  mikaela.alves
Initial revision



*/

#include "aula0501.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>


tipoErros GerarDigitosVerificadoresCpf(byte cpf[])
{
	

	unsigned short int cont = 0;
	int soma = 0, peso = 10, D10 = 0, D11 = 0;

	/* Digito 10 */ 
	
	for(cont = 0; cont<9; cont++)
	{
			
		soma = soma +(peso*cpf[cont]);
		peso--;
	}

	if(soma%11 == 0 || soma%11 == 1)
	{
		D10 = 0;

	}
	else
		D10 = (11 - soma%11);

	
	cpf[9] = D10;




        /* digito 11*/	
	soma = 0;
	peso = 11;
	for(cont = 0; cont<10; cont++)
	{
			
		soma = soma +(peso*cpf[cont]);
		peso--;
	}

	if(soma%11 == 0 || soma%11 == 1)
	{
		D11 = 0;

	}
	else
		D11 = (11 - soma%11);

	cpf[10] = D11;
	return ok;
}
tipoErros ValidarCpf(byte cpf[])
{

	int D10 = 0,D11 = 0;
	D10 = cpf[9];
	D11 = cpf[10];

	GerarDigitosVerificadoresCpf(cpf);

	
	/*Caso cpf valido o valor da variavel eh zero, caso seja invalido eh 1 */
	
	
	if(cpf[9] != D10){
		return cpfInvalido;
	 
	
	}
	if(cpf[10] != D11)
		return cpfInvalido;

return ok;		
}

	


/*$RCSfile: aula0501.c,v $*/
