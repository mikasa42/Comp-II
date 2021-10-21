/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: <nome completo>
Descricao: <descrição sucinta dos objetivos do programa>

$Author: mikaela.alves $
$Date: 2021/07/30 07:38:03 $
$Log: aula0104.c,v $
Revision 1.1  2021/07/30 07:38:03  mikaela.alves
Initial revision

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMERO_HIFENS           80
#define numArgs                 1
#define ok                      1
#define numArgs_invalido        1


void ExibirSeparador(void){
	int indice = 0;
	printf("\n");
	while (indice <= NUMERO_HIFENS)
	{	printf("-");
		indice ++;
	}
	printf("\n\n");

}


int main(int argc, char* argv[]){
	ExibirSeparador();
	if(argc != numArgs){
		printf("\n\n Numero de argumentos invalidos");
		exit(numArgs_invalido);
	}

	printf("\n\t Tamanhos dos Modificadores de Sinal combinados com os Modificadores de Largura:\n\n");


	printf("signed short:\n\t\t%lu byte%s", (long unsigned) sizeof(signed short), sizeof(signed short)> 1 ? "s\n\n": "\n\n");
	printf("signed long:\n\t\t%lu byte%s", (long unsigned) sizeof(signed long), sizeof(signed long)> 1 ? "s\n\n": "\n\n");
	printf("signed long long:\n\t\t%lu byte%s", (long unsigned) sizeof(signed long long), sizeof(signed long long)> 1 ? "s\n\n": "\n\n");
	   
	printf("unsigned short:\n\t\t%lu byte%s", (long unsigned) sizeof(unsigned short), sizeof(unsigned short)> 1 ? "s\n\n": "\n\n");
	printf("unsigned long:\n\t\t%lu byte%s", (long unsigned) sizeof(unsigned long), sizeof(unsigned long)> 1 ? "s\n\n": "\n\n");
	printf("unsigned long long:\n\t\t%lu byte%s", (long unsigned) sizeof(unsigned long long), sizeof(unsigned long long)> 1 ? "s\n\n": "\n\n");
	
       	ExibirSeparador();
return ok;
}
