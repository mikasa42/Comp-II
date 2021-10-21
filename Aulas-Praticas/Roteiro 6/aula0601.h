/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021-1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves 
Descricao: Prototipo da funcao

$Author $ 
$Dat$ 
$Log: aula0601.h,v $
Revision 1.1  2021/08/31 23:09:41  mikaela.alves
Initial revision


*/



#ifndef _AULA0601_
#define _AULA0601_  "@(#)aula0601.h $Revision: 1.1 $"



/* Prototipo da funcao*/

#define LINHA        100  
#define COLUNA       100




typedef enum
{
	ok,
	matrizInvalida,
	comprimentoExcedido
}tipoErros;


tipoErros
MultiplicarMatrizes (unsigned short NumeroLinhas1, unsigned short NumeroColuna1, unsigned short NumeroLinha2,
                     unsigned short NumeroColuna2,  double  matriz1[LINHA][COLUNA], double matriz2[LINHA][COLUNA], 			                                     double matrizProduto[LINHA][COLUNA]); 

 
tipoErros 
ObterMatrizTransposta ( unsigned short numeroLinhas,unsigned short numeroColunas,  
			double matriz1[LINHA][COLUNA],
			double matriz2[LINHA][COLUNA]); 


tipoErros CalcularMenorComplementar ( unsigned short ordem, 
					unsigned short numeroLinhas1,  
					unsigned short numeroColunas2, 
					double matriz1[LINHA][COLUNA], 
					double *cofator); 


tipoErros CalcularComplementoAlgebrico (unsigned short ordem,
					unsigned short numeroLinhas1,  
					unsigned short numeroColunas1, 
					double matriz1[LINHA][COLUNA],
					double *cofator); 

tipoErros CalcularDeterminanteMatriz (unsigned short ordem,
					double matriz1[LINHA][COLUNA], 
					double *determinante);

#endif 
/*$RCSfile: aula0601.h,v $*/
