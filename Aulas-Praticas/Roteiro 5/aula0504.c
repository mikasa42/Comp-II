/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao
$Author $
$Date $
$Log: aula0504.c,v $
Revision 1.1  2021/09/03 16:25:52  mikaela.alves
Initial revision



*/

#include "aula0504.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>


tipoErros GerarDigitosVerificadoresCpf(char *cpf, char *digito10, char *digito11)
{
	

	unsigned short int cont = 0;
	int soma = 0, peso = 10, D10 = 0, D11 = 0, x = 0;
	
	/* Digito 10 */

	
	for(cont = 0; cont<9; cont++)
	{
		x = cpf[cont] - '0';
		soma = soma +(peso*x);
		peso--;
	}

	if(soma%11 == 0 || soma%11 == 1)
	{
		D10 = 0;

	}
	else
		D10 = (11 - soma%11);

	
	*digito10 = D10 + '0';




        /* digito 11*/	
	soma = 0;
	peso = 11;
	for(cont = 0; cont<9; cont++)
	{
			
		x = cpf[cont] - '0';
		soma = soma +(peso*x);
		peso--;
	}
	
	soma = soma + (D10*peso);
	if(soma%11 == 0 || soma%11 == 1)
	{
		D11 = 0;

	}
	else
		D11 = (11 - soma%11);

	*digito11 = D11 + '0';
	return OK;
}
tipoErros ValidarCpf(char *cpf)
{

	int D10 = 0,D11 = 0;
	char digito10[1],digito11[1];
	D10 = cpf[9];
	D11 = cpf[10];
	
	GerarDigitosVerificadoresCpf(cpf, digito10, digito11);

	
	/*Caso cpf valido o valor da variavel eh zero, caso seja invalido eh 1 */
	
	if(digito10[0] != D10){
		return CPF_INVALIDO;
	}

	
	if(digito11[0] != D11){
		return CPF_INVALIDO;
	}
return OK;		
}

	


/*$RCSfile: aula0504.c,v $*/
