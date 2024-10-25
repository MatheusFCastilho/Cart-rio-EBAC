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
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char CPF[40];
	char conteudo[200];
	
	printf("DIGITE O CPF PARA CONSULTA: ");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("N�O FOI POSS�VEL ENCONTRAR ESSE CPF CADASTRADO\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nCADASTRO LOCALIZADO, INFORMA��ES ABAIXO:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()
{
	char CPF[40];
	
	printf("DIGITE O CPF DO USU�RIO A SER DELETADO: ");
	scanf("%s", CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL);
	{
		printf("\nO CPF INFORMADO N�O EST� CADASTRADO NO SISTEMA!\n\n");
		system("pause");
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
		printf("\t[4] Sair\n\n");
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
			printf("VOCE DESEJA MESMO SAIR DO PROGRAMA?\n\n");
			system("pause");
			break;
			
			default:
			printf("SELECIONE UMA DAS 3 OP��ES\n");
			system("pause");
			break;
		}
		
}
}



