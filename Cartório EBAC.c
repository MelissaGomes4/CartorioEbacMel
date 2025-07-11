#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar das string

int registro() //fun��o repons�vel por cadsatrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //repons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //inclui mais informa��es no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //inclui mais informa��es no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //inclui mais informa��es no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //respons�vel por pausar a tela
	
}

int consulta() //fun��o respons�vel por procurar o usu�rio do sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//incio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //colentando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e "r" significa ler
	
	if( file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //respons�vel por pausar a tela
	fclose(file); //fecha o arquivo
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e "r" significa ler
		
		
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema!\n");
		system("pause"); //respons�vel por pausar a tela
	}

		
}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	  system("cls"); //repons�vel por limpar a tela
		
	  setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	  printf("\t** Cart�rio da EBAC **\n\n"); //inicio do menu
	  printf("Selecione o servi�o desejado no menu:\n\n");
	  printf("\t1- Registrar nomes\n");
	  printf("\t2- Consultar nomes\n");
	  printf("\t3- Deletar nomes\n");
	  printf("\t4- Sair\n\n");
	  printf("Op��o: "); //fim do menu
	
	  scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	  system("cls"); //respons�vel por limpar a tela
	  
	  
	  switch(opcao)
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
		printf("Obrigada por utilizar o sistema!\n");
		return 0;
		break;	
		
		default:
		printf("Essa op��o n�o est� dispon�vel!\n");
		system("pause"); //respons�vel por pausar a tela
		break;
	  
	  }
	  	
	
    }
}
