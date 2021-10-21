/*
 *
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/1
Prof. Marcelo Luiz Drumond Lanza

Autor: Mikaela Rikberg Alves
Descricao:

$Author: mikaela.alves $
$Date: 2021/10/18 20:44:21 $
$Log: eelCgiExibirPaginaInicial.c,v $
Revision 1.1  2021/10/18 20:44:21  mikaela.alves
Initial revision


*/

#ifdef __linux__
#define sistemaOperacional "Linux"
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) 
#define sistemaOperacional "CentOS"
#endif


#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bibliotecas/mlcgi.h"
#include "eelTipos.h"
#include "eelErros.h"
#include "eelInterfaceUsuario.h"

#define OK						0
#define AMBIENTE_EXECUCAO_INVALIDO      1
#define COMPRIMENTO_MAXIMO_LETRA	66

int main (int argc, char *argv[])
{

	unsigned retorno;
	environmentType variavelAmbiente;
	char idiomaString [COMPRIMENTO_MAXIMO_LETRA+1];
	eelTipoIdiomas idioma;
	idioma = eelPortugues;
	
	if((retorno  = mlCgiInitialize(&variavelAmbiente)) != ML_CGI_OK)
	{
		exit (ML_CGI_OK);
	}

	if (variavelAmbiente != web)
	{
		printf ("Ambiente de execucao invalido ");
		exit (AMBIENTE_EXECUCAO_INVALIDO);
	}

	/*Cabecalho HTTP/HTTPS*/
	mlCgiBeginHttpHeader("text/html");
	mlCgiEndHttpHeader();
	
	retorno  = mlCgiGetFormStringNoNewLines("eelIdiomas",idiomaString, COMPRIMENTO_MAXIMO_LETRA +1);
	/*strcmp comparando duas strings*/ 
	if (!strcmp ("eelIngles",idiomaString))
		idioma = eelIngles;
	
	if (retorno != ML_CGI_OK)
	{
		printf ("<html>");
		printf ("	<head>");
		printf ("		<title>");
		printf ("		EEL270");
		printf ("		</title>");
		printf ("	</head>");
		printf ("<body bgcolor=\"#e66c74\">");
		printf ("	<div align=\"center\">");
		printf ("		<p > Computacao II - Turma 2021/1</p> \n");
		printf ("	</div>");
		printf ("	<div align=\"center\">");
		printf ("			%s - %s", sistemaOperacional,EelObterMensagemInterfaceUsuarioCli(idioma,mensagem));
		printf ("	</div>");
		printf ("<form action=\"eelAutenticarUsuario.cgi\" method=\"post\">");
		printf ("	<table align=\"center\">");
		printf ("		<tr>");
		printf ("			<td>");
		printf ("			%s <input type=\"text\"; name=\"eelUsuario\";  size=\"7\"; maxlegth=\"65\";>",EelObterMensagemInterfaceUsuarioWeb(idioma,usuario));
		printf ("			</td>");
		printf ("		</tr>");
		printf ("		<tr>");
		printf ("			<td>");
		printf ("			%s <input type=\"password\"; name=\"eelSenha\";  size=\"7\"; maxlegth=\"127\";>",EelObterMensagemInterfaceUsuarioWeb(idioma,senha));
		printf ("			</td>");
		printf ("		</tr>");
		printf ("		<tr>");
		printf ("			<td>");
		printf ("			<input type=\"submit\"; value=\"%s\"; >",EelObterMensagemInterfaceUsuarioWeb(idioma,botao));
		printf ("			</td>");
		printf ("		</tr>");
		printf ("		<tr>");
		printf ("		<td align = \"left\">");
 		printf ("			<a href=\"eelExibirPaginaInicial.cgi?eelIdioma=eelPortugues\" > Inicio </a>");
		printf ("		</td>");
		printf ("		<td align = \"right\">");
 		printf ("			<a href=\"eelExibirPaginaInicial.cgi?eelIdiomas=%s\" > Ingles </a>", idiomaString);
		printf ("		</td>");
		printf ("		</tr>");
		printf ("		<tr>");
		printf ("		<td align = \"left\">");
     		printf ("			<a href=\"eelExibirFormularioAtivacaoContaUsuario.cgi?eelIdioma=eelPortugues\" > Registrar </a>");
		printf ("		</td>");
		printf ("		<td align = \"right\">");
		printf ("			<a href=\"eelExibirFormulárioReinicializacaoSenhaUsuario.ci?eelIdioma=eelIngles\" > Esqueci a senha </a>");
		printf ("		</td>");
		printf ("		</tr>");
		printf ("	</table>");
		printf ("</form>");
		printf ("</body>");
		printf ("</html>");
	}
	mlCgiFreeResources();
	
	
return ok;
}
/*$RCSfile: eelCgiExibirPaginaInicial.c,v $*/
