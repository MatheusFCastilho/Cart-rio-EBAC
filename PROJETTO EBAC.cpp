#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocar espaço de memória para o programa
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char ARQUIVO[40];
	char CPF[40];
	char NOME[40];
	char SOBRENOME[40];
	char CARGO[40];
	
	printf("DIGITE O CPF DO USÁRIO A SER CADASTRADO: ");
	scanf("%s", CPF);
	
	strcpy(ARQUIVO, CPF); //esta praticamente espelhando os valores das strings
	
	FILE *file; //criando o arquivo na pasta
	file = fopen(ARQUIVO, "w");
	fprintf(file, CPF); //salva o valor da variável
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
	
	printf("DIGITE O SOBRENOME DO USUÁRIO:");
	scanf("%s", SOBRENOME);
	
	file = fopen(ARQUIVO, "a");
	fprintf(file,SOBRENOME);
	fclose(file);
	
	file = fopen(ARQUIVO, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O CARGO DO USUÁRIO:");
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
		printf("NÃO FOI POSSÍVEL ENCONTRAR ESSE CPF CADASTRADO\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nCADASTRO LOCALIZADO, INFORMAÇÕES ABAIXO:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()
{
	char CPF[40];
	
	printf("DIGITE O CPF DO USUÁRIO A SER DELETADO: ");
	scanf("%s", CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL);
	{
		printf("\nO CPF INFORMADO NÃO ESTÁ CADASTRADO NO SISTEMA!\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int x=1;
	
	for (x=1;x=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
		//DEFININDO A LINGUAGEM
		
		printf("CENTRAL DE CADASTROS EBAC\n\n");
		//MENSAGEM INICIAL
		printf("SELECIONE A OPÇÃO DESEJADA\n\n");
		//DANDO AS OPÇÕES PARA O USUÁRIO
		printf("\t[1] Registrar novo usuário\n");
		printf("\t[2] Consultar usuários\n");
		printf("\t[3] Deletar usuário\n");
		printf("\t[4] Sair\n\n");
		printf("Opção desejada: ");
		
		scanf("%d", &opcao); //coletando a resposta do usuário
		
		system("cls"); //limpando a tela
		
		switch(opcao) //validação das opções selecionadas pelo usuário.
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
			printf("SELECIONE UMA DAS 3 OPÇÕES\n");
			system("pause");
			break;
		}
		
}
}



