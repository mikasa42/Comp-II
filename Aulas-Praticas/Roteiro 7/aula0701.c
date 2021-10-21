/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Codigo com todas as funcoes do roteiro

$Author: mikaela.alves $
$Date: 2021/09/19 05:34:53 $
$Log: aula0701.c,v $
Revision 1.3  2021/09/19 05:34:53  mikaela.alves
Roteiro 7 - funcao desenhar reta

Revision 1.2  2021/09/18 01:57:40  mikaela.alves
Roteiro 7 - Contem a funcao limpar monitor

Revision 1.1  2021/09/18 01:40:20  mikaela.alves
Initial revision




*/

#include "aula0701.h"

#include <unistd.h>
#include <stdlib.h>              
#include <stdio.h>              

/*useconds_t --> funcao que esta dentro do unistd.h capaz de percorrer um valor int de 0 a 1 milhao -1
 * sendo necessario incluir essa lib */

/* a funcao usleep cronometra em micro segundos !!!
 * */
tipoErros 
MostrarMonitor (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned linhas, unsigned colunas, useconds_t tempoEspera)

{

	unsigned short numeroLinha,numeroColuna;
	unsigned saida = 0;
	system("clear");

	  for (numeroLinha = 0; numeroLinha < linhas; numeroLinha++)
	  {
	    for (numeroColuna = 0; numeroColuna < colunas; numeroColuna++)
	    {
		    (monitor[numeroLinha][numeroColuna] == aceso) ? printf ("%c",ACESO): monitor[numeroLinha][numeroColuna] == apagado ? printf ("%c",APAGADO) : monitor[numeroLinha][numeroColuna] == defeituoso ? printf ("%c",DEFEITUOSO) : saida++;  
				
	    }
	    printf ("\n");
	  }
	  if(saida != 0)
		  return linhaInvalida;
	usleep(tempoEspera);

return ok;
}

tipoErros
LimparMonitor (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas)
{
	unsigned numeroLinha, numeroColuna;

	for (numeroLinha = 0; numeroLinha < numeroMaximoLinhas; numeroLinha++)
	{
	  for (numeroColuna = 0; numeroColuna < numeroMaximoColunas; numeroColuna++)
	  {
		  if(monitor[numeroLinha][numeroColuna] == 1)
		  {
			  monitor[numeroLinha][numeroColuna] = 0;
		  }
	    
	  }
	}

return ok;
}


tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas, 
		unsigned linhaA, 
		unsigned colunaA, 
		unsigned linhaB, 
		unsigned colunaB)
{

		
	unsigned numeroLinha, numeroColuna;
	signed linhaNova,colunaNova, linhaSinal, colunaSinal;
	float coeficiente;
       	int indiceCoeficiente;

	linhaA = linhaA -1;
	linhaB = linhaB -1;

	linhaNova = linhaA-linhaB;
	if(linhaNova>0)
		linhaSinal = -1;
	if(linhaNova<0)
	{
		linhaSinal = 1;
		linhaNova*= -1;
	}

	colunaA = colunaA -1;
	colunaB = colunaB -1;

	colunaNova = colunaA - colunaB;

	if(colunaNova > 0)
		colunaSinal = -1;
	if(colunaNova < 0)
	{
		colunaSinal = 1;
		colunaNova*=-1;
	}

/*para manter que a primeira retas em verticais ou horizontais*/
/* gravando valores*/
	if(linhaA == linhaB)
	{	if(colunaA<colunaB)
		{
			for (numeroLinha = 0; numeroLinha < numeroMaximoLinhas; numeroLinha++)
			{
			  for (numeroColuna = 0; numeroColuna < numeroMaximoColunas; numeroColuna++)
			  {
				  if(monitor[numeroLinha][numeroColuna] == 0 && linhaA == numeroLinha && numeroColuna>=colunaA && numeroColuna <= colunaB)
				  {
					  monitor[numeroLinha][numeroColuna] = 1;
				  }
			    
				  if(monitor[numeroLinha][numeroColuna] == 2 && linhaA == numeroLinha && numeroColuna>=colunaA && numeroColuna <= colunaB)
					  return linhaInvalida;
			  
			  }
			}
			return ok;
		}

		
		if(colunaA>colunaB)
		{
			for (numeroLinha = 0; numeroLinha < numeroMaximoLinhas; numeroLinha++)
			{
			  for (numeroColuna = 0; numeroColuna < numeroMaximoColunas; numeroColuna++)
			  {
				  if(monitor[numeroLinha][numeroColuna] == 0 && linhaA == numeroLinha && numeroColuna>=colunaB && numeroColuna <= colunaA)
					  monitor[numeroLinha][numeroColuna] = 1;		    
			  
				  if(monitor[numeroLinha][numeroColuna] == 2 && linhaA == numeroLinha && numeroColuna>=colunaB && numeroColuna <= colunaA)
					  return linhaInvalida;
			  }
			}
			return ok;
		}
	
	}
	if(colunaA == colunaB)
	{
		if(linhaA<linhaB)
		{	
			for (numeroLinha = 0; numeroLinha < numeroMaximoLinhas; numeroLinha++)
			{
			  for (numeroColuna = 0; numeroColuna < numeroMaximoColunas; numeroColuna++)
			  {
				  if(monitor[numeroLinha][numeroColuna] == 0 && colunaA == numeroColuna && numeroLinha>=linhaA && numeroLinha<= linhaB)
					  monitor[numeroLinha][numeroColuna] = 1;

			  
			  
				  if(monitor[numeroLinha][numeroColuna] == 2 && colunaA == numeroColuna && numeroLinha>=linhaA && numeroLinha<= linhaB)
			
					  return linhaInvalida;
			  }

			}
			return ok;
	
		}
	
		if(linhaA>linhaB)
		{	
			for (numeroLinha = 0; numeroLinha < numeroMaximoLinhas; numeroLinha++)
			{
			  for (numeroColuna = 0; numeroColuna < numeroMaximoColunas; numeroColuna++)
			  {
				  if(monitor[numeroLinha][numeroColuna] == 0 && colunaA == numeroColuna && numeroLinha>= linhaB && numeroLinha<= linhaA)

					  monitor[numeroLinha][numeroColuna] = 1;

				  if(monitor[numeroLinha][numeroColuna] == 2 && colunaA == numeroColuna && numeroLinha>= linhaB && numeroLinha<= linhaA)
					  return linhaInvalida;
			  }

			}
			return ok;
	
		}
	
	
	
	}
	


		
	
/*------------------------------------------------------------ DIAGONAL ----------------------------------------*/
	
		
	coeficiente = (float)linhaNova/colunaNova;
	for (numeroColuna = 0; numeroColuna <= colunaNova; numeroColuna++)
	{
		indiceCoeficiente =(int) (coeficiente * numeroColuna);

		if(monitor[linhaA + (indiceCoeficiente*linhaSinal)][colunaA +(numeroColuna*colunaSinal)] == 2 )	
			return linhaInvalida;
		else
			monitor[linhaA+(indiceCoeficiente*linhaSinal)][colunaA+(numeroColuna*colunaSinal)] = 1 ;	


	}


	coeficiente = (float)colunaNova/linhaNova;
	for (numeroLinha = 0; numeroLinha <= linhaNova; numeroLinha++)
	{
		indiceCoeficiente = (int)(coeficiente * numeroLinha);
		if(monitor[linhaA+(numeroLinha*linhaSinal)][colunaA+(indiceCoeficiente*colunaSinal)] == 2 )	
			return linhaInvalida;
		else
			monitor[linhaA+(numeroLinha*linhaSinal)][colunaA+(indiceCoeficiente*colunaSinal)] = 1 ;	


	}

	


return ok;
}

tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas, 
		unsigned numeroVertices, 
		unsigned linhasVertices[NUMERO_MAXIMO_LINHAS], 
		unsigned colunasVertices[NUMERO_MAXIMO_COLUNAS])
{

	int indice;
	tipoErros status;
	for (indice = 0; indice < numeroVertices-1 ; indice++)
	{
	
		status = DesenharReta (monitor,numeroMaximoLinhas,numeroMaximoColunas,linhasVertices[indice],colunasVertices[indice],linhasVertices[indice+1],colunasVertices[indice+1]);
		if(status == linhaInvalida)
			return linhaInvalida;
	}
		status = DesenharReta (monitor,numeroMaximoLinhas,numeroMaximoColunas,linhasVertices[numeroVertices-1],colunasVertices[numeroVertices-1],linhasVertices[0],colunasVertices[0]);
		if(status == linhaInvalida)
			return linhaInvalida;
return ok;
}

tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroMaximoLinhas, 
		unsigned numeroMaximoColunas, 
		unsigned linha, 
		unsigned coluna, 
		useconds_t tempoEspera)
{
	
	unsigned coordenadas[NUMERO_MAXIMO_LINHAS * NUMERO_MAXIMO_COLUNAS*2];
	unsigned indice, indicePontos = 0;
	unsigned contador = 1;	
	signed indiceLinha,indiceColuna;
	linha--;
	coluna--;

	coordenadas [0] = linha;
	coordenadas [1] = coluna;

		  for (indice = 0; indice < contador; indice++)
		  {
			  indiceLinha = coordenadas[indice + indicePontos];
			  indiceColuna = coordenadas[indice+1+indicePontos];
			  indicePontos++;
			  
			  if(monitor[linha][coluna] == 2)
				  return linhaInvalida;


			  monitor[indiceLinha][indiceColuna] = 1;
			  MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);
			 
			  if(monitor[indiceLinha][indiceColuna] == 2)
				  return linhaInvalida;

			  if(monitor[indiceLinha + 1][indiceColuna] == 0 && (indiceLinha+1) <numeroMaximoLinhas && (indiceLinha+1>=0))
			  {
				  coordenadas [contador*2] = indiceLinha + 1;
				  coordenadas [contador*2 + 1] = indiceColuna;
				  contador++;
				  monitor[indiceLinha + 1][indiceColuna] = 1;
				  MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);
			  }
			  if(monitor[indiceLinha][indiceColuna + 1] == 0 && (indiceColuna+1) <numeroMaximoLinhas && (indiceColuna+1>=0))
			  {
				  coordenadas [contador*2] = indiceLinha ;
				  coordenadas [contador*2 + 1] = indiceColuna + 1;
				  contador++;
				  monitor[indiceLinha ][indiceColuna +1] = 1;
				  MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);
			  }
			  if(monitor[indiceLinha][indiceColuna + 1] == 0 && (indiceColuna+1) <numeroMaximoLinhas && (indiceColuna+1>=0))
			  {
				  coordenadas [contador*2] = indiceLinha ;
				  coordenadas [contador*2 + 1] = indiceColuna + 1;
				  contador++;
				  monitor[indiceLinha ][indiceColuna +1] = 1;
				  MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);
			  }
			  if(monitor[indiceLinha - 1][indiceColuna] == 0 && (indiceLinha-1) <numeroMaximoLinhas && (indiceLinha-1>=0))
			  {
				  coordenadas [contador*2] = indiceLinha - 1;
				  coordenadas [contador*2 + 1] = indiceColuna;
				  contador++;
				  monitor[indiceLinha - 1][indiceColuna] = 1;
				  MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);
			  }
			  if(monitor[indiceLinha][indiceColuna - 1] == 0 && (indiceColuna-1) <numeroMaximoLinhas && (indiceColuna-1>=0))
			  {
				  coordenadas [contador*2] = indiceLinha;
				  coordenadas [contador*2 + 1] = indiceColuna - 1;
				  contador++;
				  monitor[indiceLinha ][indiceColuna -1] = 1;
				  MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);
			  } 
		  
		
		}
		
return ok;

}
/*$RCSfile: aula0701.c,v $*/
