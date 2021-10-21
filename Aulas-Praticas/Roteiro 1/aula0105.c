/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza
Autor: <nome completo>
Descricao: <descrição sucinta dos objetivos do programa>

$Author: mikaela.alves $
$Date: 2021/07/30 07:38:40 $
$Log: aula0105.c,v $
Revision 1.1  2021/07/30 07:38:40  mikaela.alves
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
/*
       	ExibirSeparador();	
	printf("\n\n\n\t\Tamanhos dos Tipos Básicos combinados com Modificadores de Largura: \n\n");
	
	printf("short char:\n\t\t%lu byte%s", (long unsigned) sizeof(char short), sizeof(char short)> 1 ? "s\n\n": "\n\n");
	printf("long char :\n\t\t%lu byte%s", (long unsigned) sizeof(char long), sizeof(char long)> 1 ? "s\n\n": "\n\n");
	printf("long long char:\n\t\t%lu byte%s", (long unsigned) sizeof(char long long ), sizeof(char long long)> 1 ? "s\n\n": "\n\n");

	printf("int short:\n\t\t%lu byte%s", (long unsigned) sizeof(int short), sizeof(int short)> 1 ? "s\n\n": "\n\n");
	printf("int long:\n\t\t%lu byte%s", (long unsigned) sizeof(int long), sizeof(int long)> 1 ? "s\n\n": "\n\n");
	printf("int long long:\n\t\t%lu byte%s", (long unsigned) sizeof(int long long), sizeof(int long long)> 1 ? "s\n\n": "\n\n");



	printf("float short:\n\t\t%lu byte%s", (long unsigned) sizeof(float short), sizeof(float short)> 1 ? "s\n\n": "\n\n");	
	printf("float long:\n\t\t%lu byte%s", (long unsigned) sizeof(float long), sizeof(float long)> 1 ? "s\n\n": "\n\n");
	printf("float long:\n\t\t%lu byte%s", (long unsigned) sizeof(float long long), sizeof(float long long)> 1 ? "s\n\n": "\n\n");


	printf("double short:\n\t\t%lu byte%s", (long unsigned) sizeof(double short), sizeof(double short)> 1 ? "s\n\n": "\n\n");
	printf("double long:\n\t\t%lu byte%s", (long unsigned) sizeof(double long), sizeof(double long)> 1 ? "s\n\n": "\n\n");
	printf("double long long:\n\t\t%lu byte%s", (long unsigned) sizeof(double long long), sizeof(double long long)> 1 ? "s\n\n": "\n\n");


	printf("void short:\n\t\t%lu byte%s", (long unsigned) sizeof(void short), sizeof(void short)> 1 ? "s\n\n": "\n\n");
	printf("void long:\n\t\t%lu byte%s", (long unsigned) sizeof(void long), sizeof(void long)> 1 ? "s\n\n": "\n\n");
	printf("void long long:\n\t\t%lu byte%s", (long unsigned) sizeof(void long long), sizeof(void long long)> 1 ? "s\n\n": "\n\n");

	ExibirSeparador();
*/
	return ok;
}
