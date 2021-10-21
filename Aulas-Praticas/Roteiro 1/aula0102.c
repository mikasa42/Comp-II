/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: <nome completo>
Descricao: <descrição sucinta dos objetivos do programa>

$Author: mikaela.alves $
$Date: 2021/07/30 07:35:33 $
$Log: aula0102.c,v $
Revision 1.1  2021/07/30 07:35:33  mikaela.alves
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

	printf("\n\n\n\t'Tipos basicos'\n\n");
	
	printf("char:\n\t\t%lu byte%s", (long unsigned) sizeof(char), sizeof(char)> 1 ? "s\n\n": "\n\n");

	   
	printf("int:\n\t\t%lu byte%s", (long unsigned) sizeof(int), sizeof(int)> 1 ? "s\n\n": "\n\n");

	printf("float:\n\t\t%lu byte%s", (long unsigned) sizeof(float), sizeof(float)> 1 ? "s\n\n": "\n\n");

	printf("double:\n\t\t%lu byte%s", (long unsigned) sizeof(double), sizeof(double)> 1 ? "s\n\n": "\n\n");

	printf("void:\n\t\t%lu byte%s", (long unsigned) sizeof(void), sizeof(void)> 1 ? "s\n\n": "\n\n");

	ExibirSeparador();

	return ok;

}
