#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //alocar espa�o de mem�ria para o programa
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char ARQUIVO[40];
	char CPF[40];
	char NOME[40];
	char SOBRENOME[40];
	char CARGO[40];
	int opcao=0;
	int laco=1;
	
	printf("DIGITE O CPF DO US�RIO A SER CADASTRADO: ");
	scanf("%s", CPF);
	
	strcpy(ARQUIVO, CPF); //esta praticamente espelhando os valores das strings
	
	FILE *file; //criando o arquivo na pasta
	file = fopen(ARQUIVO, "w");
	fprintf(file, CPF); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(ARQUIVO, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O NOME A SER CADASTRADO:");
	scanf("%s", NOME);
	
	file = fopen(ARQUIVO, "a");
	fprintf(file,NOME);
	fclose(file);
	
	file = fopen(ARQUIVO, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O SOBRENOME DO USU�RIO:");
	scanf("%s", SOBRENOME);
	
	file = fopen(ARQUIVO, "a");
	fprintf(file,SOBRENOME);
	fclose(file);
	
	file = fopen(ARQUIVO, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O CARGO DO USU�RIO:");
	scanf("%s", CARGO);
	
	file = fopen(ARQUIVO, "a");
	fprintf(file,CARGO);
	fclose(file);
	
	printf("\nGostaria de adicionar mais usu�rios?\n");
	printf("\n[1]SIM | [2]N�O\n");
	printf("\nOP��O SELECIONADA: ");
	
	scanf("%d", &opcao);//armazena a resposta do usu�rio

	system("cls");//limpa a tela
	
	switch(opcao)//sistema para validar a escolha do usu�rio
	{
		case 1://caso escolha 1
		registro();
		break;
		
		case 2://caso escolha 2
		printf("\nRETORNANDO PARA O MENU INICIAL\n\n");
		int main();
		break;
		
		default://caso a escolha n�o seja nem 1 nem 2
		printf("\nESSA OP��O N�O EXISTE, RETORNANDO PARA O MENU INICIAL\n\n");
		int main();
		break;
	}
	
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char CPF[40];
	char conteudo[200];
	int laco=1;
	int opcao=0;
	
	printf("DIGITE O CPF PARA CONSULTA: ");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("N�O FOI POSS�VEL ENCONTRAR ESSE CPF CADASTRADO\n");
		printf("\nDESEJA TENTAR NOVAMENTE?\n");
		printf("[1]SIM | [2]N�O\n");
		printf("\nOP��O SELECIONADA: ");
		
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao)
		{
			case 1:
			consulta();
			break;
			
			case 2:
			printf("\nRETORNANDO PARA O MENU PRINCIPAL\n\n");
			break;
		}
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nCADASTRO LOCALIZADO, INFORMA��ES ABAIXO:\n\n");
		printf("%s", conteudo);
		printf("\n\nDESEJA CONSULTAR OUTRO USU�RIO?\n");
		printf("\n[1]SIM | [2]N�O\n");
		printf("\nOP��O SELECIONADA: ");
		
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			consulta();
			break;
			
			case 2:
			printf("\nRETORNANDO PARA O MENU PRINCIPAL\n\n");
			break;	
			
			default:
			printf("\nESSA OP��O N�O EXISTE, RETORNANDO PARA O MENU INICIAL\n\n");
			break;
		}
	}
	
	system("pause");
}


int deletar()
{
	char CPF[40];
	int laco=1;
	int opcao=0;
	
	
	printf("DIGITE O CPF DO USU�RIO A SER DELETADO: ");
	scanf("%s", CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL);
	{
		printf("\nN�O ENCONTRADO NO SISTEMA\n");
		printf("\nTENTE OUTRO CPF\n");
		system("pause");
		system("cls");
		int main();
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int x=1;
	
	for (x=1;x=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
		//DEFININDO A LINGUAGEM
		
		printf("CENTRAL DE CADASTROS EBAC\n\n");
		//MENSAGEM INICIAL
		printf("SELECIONE A OP��O DESEJADA\n\n");
		//DANDO AS OP��ES PARA O USU�RIO
		printf("\t[1] Registrar novo usu�rio\n");
		printf("\t[2] Consultar usu�rios\n");
		printf("\t[3] Deletar usu�rio\n");
		printf("\t[4] Sair do sistema\n\n");
		printf("Op��o desejada: ");
		
		scanf("%d", &opcao); //coletando a resposta do usu�rio
		
		system("cls"); //limpando a tela
		
		switch(opcao) //valida��o das op��es selecionadas pelo usu�rio.
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("SELECIONE UMA DAS 3 OP��ES\n");
			system("pause");
			break;
		}
		
}
}



