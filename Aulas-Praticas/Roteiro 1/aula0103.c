/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: <nome completo>
Descricao: <descrição sucinta dos objetivos do programa>

$Author: mikaela.alves $
$Date: 2021/07/30 07:37:26 $
$Log: aula0103.c,v $
Revision 1.1  2021/07/30 07:37:26  mikaela.alves
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

	printf("\n\t'Modificadores De Sinal'\n\n");
	
	printf("signed:\n\t\t%lu byte%s", (long unsigned) sizeof(signed), sizeof(signed)> 1 ? "s\n\n": "\n\n");
	   
	printf("unsigned:\n\t\t%lu byte%s", (long unsigned) sizeof(unsigned), sizeof(unsigned)> 1 ? "s\n\n": "\n\n");
	ExibirSeparador();
return ok;
}
