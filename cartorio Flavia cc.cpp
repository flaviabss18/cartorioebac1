
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocações de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
		
int registro() //função responsavel por cadastras os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // ria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //fopen comando para abrir o arquivo
	fprintf(file,","); //gravar informações do arquivo aberto
	fclose(file);//fechar um arquivo aberto
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //fopen comando para abrir o arquivo
	fprintf(file,nome);//gravar informações do arquivo
	fclose(file);//fechar o arquivo
	
	file = fopen(arquivo, "a");// fopen comando para abrir o arquivo
	fprintf(file,",");//gravar informações do arquivo aberto
	fclose(file); //fechar um arquivo aberto
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //%s salvar dentro da string
	
	file = fopen(arquivo, "a"); // fopen comando para abrir o arquivo
	fprintf(file,sobrenome); //gravar informações do arquivo
	fclose(file); //fechar um arquivo aberto
	
	file = fopen(arquivo, "a"); // fopen comando para abrir o arquivo
	fprintf(file,","); //gravar informações do arquivo
	fclose(file); //fechar um arquivo aberto
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s",cargo); //%s salvar dentro da string
	
	file = fopen(arquivo, "a"); // fopen comando para abrir o arquivo
	fprintf(file,cargo); //gravar informações do arquivo
	fclose(file);	//fechar um arquivo aberto
	
    system("pause"); //comando para pausar a tela e dar tempo para o usuário ler

}

int consulta()
{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file= fopen(cpf,"r");
	
	if(file==NULL)
	
	{
	
			printf("Não foi possivel abrir o arquivo, não localizado!.\n ");	
	}
	while(fgets(conteudo,200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
	    printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
}


int deletar()
{
	
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%/s",cpf);
	
	remove(cpf);
    
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("o usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}


	
int main()

	{
	int opcao=0; //Definindo variÃ¡veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
				
	scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");//responsável por limpar a tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
		
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
		
			default:
			printf("Essa opção não está¡ disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
