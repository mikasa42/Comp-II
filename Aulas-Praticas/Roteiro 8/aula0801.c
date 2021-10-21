/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: Mikaela Rikberg Alves
Descricao : Codigo com todas as funcoes do roteiro

$Author: mikaela.alves $
$Date: 2021/10/02 19:09:06 $
$Log: aula0801.c,v $
Revision 1.1  2021/10/02 19:09:06  mikaela.alves
Initial revision





*/

#include "aula0801.h"

#include <unistd.h>
#include <stdlib.h>              
#include <stdio.h>              
#include <string.h>              

		  
#define EOS  '\0'


tipoErros
CodificarBase16 (byte* vetorBytes , unsigned long long numerosBytes, char * saida)
{
	unsigned indice;
	char stringAuxiliar[3];
	byte resto, numeroAuxiliar;
	
	char alfabeto[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	saida[0] = EOS;
	
	for (indice = 0; indice < numerosBytes; indice++)
	{
		numeroAuxiliar = vetorBytes[indice];
		resto = numeroAuxiliar %16;
		numeroAuxiliar = (numeroAuxiliar - resto)/16;
		
		stringAuxiliar[0] = alfabeto[numeroAuxiliar];
		stringAuxiliar[1] = alfabeto[resto];
		stringAuxiliar[2] = EOS;

		strcat (saida,stringAuxiliar);

	}

return ok;

}

tipoErros
DecodificarBase16 (char *entrada, byte *vetorBytes, unsigned long long *numeroBytes)
{
	unsigned indiceBase, indiceBase0, indiceBase1, conta, indice = 0;
	unsigned validar = 0;
	unsigned long long cont;

	char alfabeto[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	numeroBytes[0] = strlen(entrada)/2;

	for (cont = 0; cont < numeroBytes[0]*2; cont = cont+2)
	{
		for (indiceBase = 0; indiceBase < 16; indiceBase++)
		{
			if(entrada[cont] == alfabeto[indiceBase])
			{
				indiceBase0 = indiceBase;
				validar++;
			}
			if(entrada[cont +1] == alfabeto[indiceBase])
			{
				indiceBase1 = indiceBase;
				validar++;
			}
		}
			if(validar%2 != 0)
				return valorInvalido;
			
			validar = 0;
			
			conta = (indiceBase0 * 16) + (indiceBase1 );

					
			vetorBytes[indice] = conta;
			indice++;
		
			

			
	}
return ok;
}

tipoErros
CodificarBase32 (byte * vetorBytes, unsigned long long numeroBytes, tipoAlfabetoBase32 alfabeto , char * saida)
{


	
	char alfabetoNormalBase32[32] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','2','3','4','5','6','7'};
	
	char alfabetoEstendidoBase32[32] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};
	
	char *bin;
	int indice;
	byte numero = 0, resto;
	char string[5];
/*------------------------ Alocando memoria -----------------------*/
	bin = malloc(sizeof(char[numeroBytes*8+1]));

	if(bin == NULL)
	{
		printf (" memoria insuficiente");
		return memoriaInsuficiente;
	}
/*-----------------------------------------------------------------*/	
	TransformarDecimalBinario(vetorBytes, bin);
	
	
	if(strlen(bin)%5 != 0){
		resto = strlen(bin)%5;	
		
		for(indice=0; indice < 5-resto; indice++){
			string[indice] = '0';	
		}
		string[indice] = '\0';
		strcat(bin,string);
	}

	
	if(alfabeto == alfabetoNormal)
	{ 
		for(indice=0; indice < strlen(bin); indice+=5){
			numero =  (bin[indice] - '0')*16;
			numero+= (bin[indice + 1] - '0')*8;
			numero+= (bin[indice + 2] - '0')*4;
			numero+= (bin[indice + 3] - '0')*2;
			numero+= (bin[indice + 4] - '0')*1;
			
			saida[indice/5] = alfabetoNormalBase32[numero]; 
		}
		saida[indice/5] = '\0';
		
			

	}
	if(alfabeto == alfabetoEstendido)
	{ 
		for(indice=0; indice < strlen(bin); indice+=5){
			numero =  (bin[indice] - '0') * 16;
			numero += (bin[indice + 1] - '0') * 8;
			numero += (bin[indice + 2] - '0') * 4;
			numero += (bin[indice + 3] - '0') * 2;
			numero += (bin[indice + 4] - '0') * 1;
		saida[indice/5] = alfabetoEstendidoBase32[numero]; 
		}
		saida[indice/5] = '\0';
		
			
	}
	
	if(strlen(saida)%8 != 0){
		resto = strlen(saida)%8;	
		
		for(indice=0; indice < 8-resto; indice++){
			string[indice] = '=';	
		}
		string[indice] = '\0';
		strcat(saida,string);
	}

	
return ok;
}

tipoErros
DecodificarBase32 (char * entrada, tipoAlfabetoBase32 alfabeto, byte * vetorBytes, unsigned long long * numeroBytes)
{
	
	
	char alfabetoNormalBase32[32] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','2','3','4','5','6','7'};

	char alfabetoEstendidoBase32[32] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};

	int indice, cont, tamanhoVetor;
	char *decimal;
	

	tamanhoVetor = strlen((char*)entrada);
	
	int resto, auxiliar;
	char stringAux[tamanhoVetor][6];
	char *bin;
/*
 * CYRA --> C = 2; Y = 24; R = 17; A = 0;
 *   C = 00010
 *   Y = 11000
 *   R = 10001
 *   A = 00000
 *
 *   ALOCANDO = {00010110,00100010,00000000}
 *   22,34,0
 * */	
/*------------------------ Alocando memoria -----------------------*/
	bin = malloc(sizeof(char[tamanhoVetor*8+1]));

	if(bin == NULL)
	{
		printf (" memoria insuficiente");
		return memoriaInsuficiente;
	}
	
	decimal = malloc(sizeof(char[tamanhoVetor+1]));

	if(decimal == NULL)
	{
		printf (" memoria insuficiente");
		return memoriaInsuficiente;
	}
/*-----------------------------------------------------------------*/	
	bin[0] = '\0';
	
	if(alfabeto == alfabetoNormal)
	{

		for(indice = 0; indice < tamanhoVetor; indice++ )
		{
			for(cont = 0; cont<32; cont++)
			{
				if(entrada[indice] == alfabetoNormalBase32[cont])
					decimal[indice] = cont;
					
			}
			 
		}
		for(cont = 0; cont < tamanhoVetor; cont++){
			stringAux[cont][5] = '\0';

			for(indice = 4; indice>=0; indice--)
			{
				resto = decimal[cont]%2;
				auxiliar = (decimal[cont] - resto)/2;
				decimal[cont] = auxiliar; 
		
				if(resto == 0 || resto ==1 )
					stringAux[cont][indice] = resto + '0';
				
			}
			strcat(bin,stringAux[cont]);
		}

		TransformarBinarioDecimal(bin,vetorBytes);
		
		numeroBytes[0] = (int)strlen((char*)vetorBytes);
	}


	if(alfabeto == alfabetoEstendido)
	{

		for(indice = 0; indice < tamanhoVetor; indice++ )
		{
			for(cont = 0; cont<32; cont++)
			{
				if(entrada[indice] == alfabetoEstendidoBase32[cont])
					decimal[indice] = cont;
			}
			 
		}

		for(cont = 0; cont < tamanhoVetor; cont++){
			for(indice = 5; indice>=0; indice++)
			{
				resto = decimal[cont]%2;
				auxiliar = (decimal[cont] - resto)/2;
				decimal[cont] = auxiliar; 
		
				if(resto == 0 || resto ==1 )
					stringAux[cont][indice] = resto + '0';
				
			}
			strcat(bin,stringAux[cont]);
		}

		TransformarBinarioDecimal(bin, vetorBytes);
		numeroBytes[0] = (int)strlen((char*)vetorBytes);
	}


return ok;
}
tipoErros
CodificarBase64 (byte * vetorBytes, unsigned long long numeroBytes, tipoFinalLinha finalLinha, char * saida)
{


	char alfabeto[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
	
	char *bin;
	int indice, indiceLinha, cont;
	byte numero = 0, resto;
	char string[6];
	int conta;

/*
 *ENTRADA = FFA2FF;
 * FF = 255;
 * A2 = 162;
 * FF = 255;
 *
 * 255 = 11111111;
 * 162 = 10100010;
 * 255 = 11111111;
 *
 * 
 * {111111,111010,001011,111111};
 *
 *	{63,58,11,63};
 *
 *	{/,6,L,/}
 *
 *SAIDA = /6L/;
 *
 * */
/*------------------------ Alocando memoria -----------------------*/
	bin = malloc(sizeof(char[numeroBytes*8+1]));

	if(bin == NULL)
	{
		printf (" memoria insuficiente");
		return memoriaInsuficiente;
	}
/*-----------------------------------------------------------------*/	
	TransformarDecimalBinario(vetorBytes, bin);
	
	conta = strlen(bin)%24;
	if(conta != 0){
	
		
		
		if(strlen(bin)%6 != 0){
			resto = strlen(bin)%6;	
			
			for(indice=0; indice < 6-resto; indice++){
				string[indice] = '0';	
			}
			string[indice] = '\0';
			strcat(bin,string);
		}

	}

	for(indice=0; indice < strlen(bin); indice+=6){
		numero =  (bin[indice] - '0')*32;
		numero+= (bin[indice + 1] - '0')*16;
		numero+= (bin[indice + 2] - '0')*8;
		numero+= (bin[indice + 3] - '0')*4;
		numero+= (bin[indice + 4] - '0')*2;
		numero+= (bin[indice + 5] - '0')*1;
		
		saida[indice/6] = alfabeto[numero]; 
	}
	saida[indice/6] = '\0';
	
	conta = strlen(saida)%4;
	
	if(conta != 0){

	
		resto = strlen(saida)%4;	
		for(indice = 0; indice<4-resto; indice++){
			string[indice] = '=';	
		}
		string[indice] = '\0';
		strcat(saida,string);

	}		
	if(finalLinha == habilitado)
	{
		/*indiceLinha = 0;*/
		indiceLinha = 1;
		for(indice = 0; indice<strlen(saida); indice++){
			
			if(indiceLinha == 77)
			{
				saida[strlen(saida)+1] = '\0';
				for(cont = strlen(saida); cont>indice; cont--)
				{
					saida[cont] = saida[cont-1];
				}

				saida[indice] = '\n';
				indiceLinha = 0;
				/*continue*/
			}
			indiceLinha++;
		}
	}

return ok;
}

tipoErros
DecodificarBase64 (char *entrada, tipoFinalLinha finalLinha, byte *vetorBytes, unsigned long long *numeroBytes)
{

	
	char alfabeto[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
	
	
	int indice, cont, tamanhoVetor;
	char *decimal;
	

	tamanhoVetor = strlen((char*)entrada);
	
	int resto, auxiliar;
	char stringAux[tamanhoVetor][7];
	char *bin;

/*------------------------ Alocando memoria -----------------------*/
	bin = malloc(sizeof(char[tamanhoVetor*8+1]));

	if(bin == NULL)
	{
		printf (" memoria insuficiente");
		return memoriaInsuficiente;
	}
	
	decimal = malloc(sizeof(char[tamanhoVetor+1]));

	if(decimal == NULL)
	{
		printf (" memoria insuficiente");
		return memoriaInsuficiente;
	}
/*-----------------------------------------------------------------*/	
	bin[0] = '\0';
	

	for(indice = 0; indice < strlen(entrada); indice++ ){
		if(entrada[indice] == '\n'){
			for(cont=indice;   cont < strlen(entrada); cont++ ){
				entrada[cont] = entrada[cont+1];
			}
		}
	}


	for(indice = 0; indice < tamanhoVetor; indice++ )
	{
		for(cont = 0; cont<64; cont++)
		{
			if(entrada[indice] == alfabeto[cont])
				decimal[indice] = cont;
				
		}
		 
	}
	for(cont = 0; cont < tamanhoVetor; cont++){
		stringAux[cont][6] = '\0';

		for(indice = 5; indice>=0; indice--)
		{
			resto = decimal[cont]%2;
			auxiliar = (decimal[cont] - resto)/2;
			decimal[cont] = auxiliar; 
	
			if(resto == 0 || resto ==1 )
				stringAux[cont][indice] = resto + '0';
			
		}
		strcat(bin,stringAux[cont]);
	}

	TransformarBinarioDecimal(bin,vetorBytes);
	
	numeroBytes[0] = (int)strlen((char*)vetorBytes);


	
	
return ok;
}
	
tipoErros 
TransformarDecimalBinario(byte *vetorBytes, char *bin)
{
	

	int indice,cont, resto, auxiliar, indiceNovo;
	char stringAux[strlen((char*)vetorBytes)][8];
	char stringBin[strlen((char*)vetorBytes)][8];
	unsigned tamanhoVetor;	

	tamanhoVetor = strlen((char*)vetorBytes);

	for(cont = 0; cont < tamanhoVetor; cont++){
		for(indice = 0; indice<8; indice++)
		{
			resto = vetorBytes[cont]%2;
			auxiliar = (vetorBytes[cont] - resto)/2;
			vetorBytes[cont] = auxiliar; 
	
			if(resto == 0 || resto ==1 )
				stringAux[cont][indice] = resto + '0';
			
		}
	}
	indiceNovo = 0;
	for(cont = 0; cont < tamanhoVetor; cont++){
		for(indice = 7; indice>=0; indice--)
		{
			stringBin[cont][indiceNovo] = stringAux[cont][indice];
			indiceNovo++;	
		}
		stringBin[cont][indiceNovo] = '\0';
		indiceNovo = 0;
		strcat(bin,stringBin[cont]);
	}
	return ok;

	
}
/* char ** eh equivante a matriz*/

tipoErros 
TransformarBinarioDecimal(char *bin,  byte *vetorBytes)
{
	byte numero = 0;
	int indice, resto, tamanhoBin;
	char string[2];
	
	tamanhoBin = strlen(bin);

	string[0] = '0';
	string[1] = '\0';

	if (tamanhoBin%8 != 0)
	{
		resto = tamanhoBin%8;
	}	

	for (indice = 0; indice<(8-resto); indice++)
	{
		strcat(bin,string);
	}

	for(indice=0; indice < strlen(bin); indice+=8){
		numero =  (bin[indice] - '0') * 128;
		numero += (bin[indice + 1] - '0') * 64;
		numero += (bin[indice + 2] - '0') * 32;
		numero += (bin[indice + 3] - '0') * 16;
		numero += (bin[indice + 4] - '0') * 8;
		numero += (bin[indice + 5] - '0') * 4;
		numero += (bin[indice + 6] - '0') * 2;
		numero += (bin[indice + 7] - '0');
	
		vetorBytes[indice/8] = numero; 
	}
	vetorBytes[indice/8] = '\0';
		
			

return ok;
}
/*$RCSfile: aula0801.c,v $*/
