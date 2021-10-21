/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Codigo com todas as funcoes do roteiro
$Author: mikaela.alves $
$Date: 2021/09/09 23:36:12 $
$Log: aula0601.c,v $
Revision 1.2  2021/09/09 23:36:12  mikaela.alves
arquivo com a implementa√acao de todas as funcoes do roteiro

Revision 1.1  2021/08/31 23:07:28  mikaela.alves
Initial revision






*/

#include "aula0601.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>


tipoErros 
MultiplicarMatrizes (unsigned short numeroLinha1, unsigned short numeroColunas1, unsigned short numeroLinha2,
                     unsigned short numeroColunas2,  double matriz1[LINHA][COLUNA], double matriz2[LINHA][COLUNA], 			                                     double matrizProduto[LINHA][COLUNA])
{

	unsigned short indice = 0, linha, coluna;
	double campoMatriz = 0;
	
	for (linha = 0; linha < numeroLinha1; linha++)
	{

		for (coluna = 0; coluna < numeroColunas2; coluna++)
		{
			
			for (indice = 0; indice < numeroColunas1; indice++)
			{
				campoMatriz+= matriz1[linha][indice]*matriz2[indice][coluna];
			}
			matrizProduto[linha][coluna]  = campoMatriz;
			campoMatriz = 0;
		}
	}
return ok;		
}


tipoErros 
ObterMatrizTransposta (unsigned short numeroLinhas, unsigned short numeroColunas, 
				double matrizE[LINHA][COLUNA], double matrizT[LINHA][COLUNA])
{
		unsigned short linha, coluna;
 																		
		if (numeroLinhas > LINHA || numeroColunas > COLUNA)
		{
			printf ("Matriz excede o comprimento permitido \n");											return comprimentoExcedido;
		}

																	            	for (linha = 0; linha < numeroLinhas; linha++)
																			{
																				for (coluna = 0; coluna < numeroColunas; coluna++)
																				{							            										matrizT[coluna][linha] = matrizE[linha][coluna];
								            											}
						            												}
 																	 																			            														return ok;
  																			            														}
tipoErros 
CalcularDeterminanteMatriz (unsigned short ordem, double matriz[LINHA][COLUNA], double *determinante)
{
	int cont1, cont2;
	double det = 0, dP = 0, dS = 0, diagonaisPrincipais = 1, diagonaisSecundarias = 1;
	double cofator[0];
	if (ordem > LINHA)
	{
		printf ("Matriz excede o comprimento permitido.\n");
		return comprimentoExcedido;
	}
	if (ordem == 1)
	{
		det = matriz[0][0];

	}
	if (ordem == 2)
	{
		det = matriz[0][0] * matriz[1][1] - matriz[1][0]*matriz[0][1];
	}
	if (ordem == 3) /* Calculadora pela regra de Sarrus */
	{
		for (cont1 = 0; cont1 < ordem; cont1++)
		{		
			for (cont2 = 0; cont2 < ordem; cont2++)
			{
				diagonaisPrincipais *= matriz[(cont2 + cont1)%3][cont2];
				diagonaisSecundarias *= matriz[(- cont2 + cont1 + 2)%3][cont2];
			}	
			dP += diagonaisPrincipais;
			dS += diagonaisSecundarias;
			diagonaisPrincipais = 1;
			diagonaisSecundarias = 1;
		}
										
		det = dP - dS; /* Soma das diagonais princiapsis menos a soma das diagonais secundarias */
	}
	if(ordem > 3)
	{
		
		for(cont1  = 1; cont1<= ordem; cont1++)
		{
			CalcularComplementoAlgebrico(ordem,cont1,1, matriz, cofator);
			det += cofator[0] * matriz[cont1 - 1][0];
		}
	}	
	*determinante = det;
	
return ok;
}



tipoErros 
CalcularMenorComplementar ( unsigned short ordem, unsigned short linha, unsigned short coluna, 
			double matriz[LINHA][COLUNA], double *menorComplementar)
{
		double matrizR[LINHA][COLUNA]; 
		unsigned short indLinha, indColuna;

		linha = linha -1 ;
		coluna = coluna -1;
	
		for (indLinha = 0; indLinha < ordem; indLinha++)
		{
			for (indColuna = 0; indColuna < ordem; indColuna++)
			{
					
				if (indLinha < linha)
				{
					if (indColuna < coluna  )
						matrizR[indLinha][indColuna] = matriz[indLinha][indColuna];
				
					else
					{
						if (indColuna > coluna  )
							matrizR[indLinha][indColuna -1] = matriz[indLinha][indColuna];
					}
			
				}
				if (indLinha > linha )
				{	
					if (indColuna < coluna)
						matrizR[indLinha - 1][indColuna] = matriz[indLinha][indColuna];
					else
					{		
						if (indColuna > coluna)
							matrizR[indLinha - 1][indColuna - 1] = matriz[indLinha][indColuna];
					}
				}	
			}
		}



		CalcularDeterminanteMatriz(ordem - 1, matrizR, menorComplementar);	
		
	return ok;
}

tipoErros CalcularComplementoAlgebrico ( unsigned short ordem, unsigned short linha, unsigned short coluna,
		                                      double matriz[LINHA][COLUNA], double *cofator)
{
	
	double menorComplementar[1];

	CalcularMenorComplementar(ordem, linha, coluna, matriz, menorComplementar);
	unsigned short soma = 0;
	soma = linha + coluna;
	if(soma%2 == 0)
		*cofator = 1;
	else
		*cofator = -1;

	*cofator = menorComplementar[0] * cofator[0];
	return ok;
}

/*$RCSfile: aula0601.c,v $*/
