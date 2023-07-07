#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: "); //Nome ao valor 
	fprintf(file,cpf); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo o "a" é para atualizar a informação
	fprintf(file,",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo o "a" é para atualizar a informação
	fprintf(file, " Nome: "); //Nome ao valor
	fprintf(file,nome); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo 
	fprintf(file,","); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", sobrenome); 
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo
	fprintf(file, " Sobrenome: "); //Nome ao valor
	fprintf(file,sobrenome); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo
	fprintf(file,","); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo
	fprintf(file, " Cargo: "); //Nome ao valor
	fprintf(file,cargo); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa para leitura de tela
}
	
int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//Início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Localizando CPF existente
	
	if(file == NULL) //Caso o CPF não existe
	{
		printf("\nNão foi possível abrir o arquivo, não localizado!\n"); //Mensagem ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto tiver conteúdo dentro do arquivo armazena dentro da variável
	{
		printf("\nEssas são as informações do usuário:"); //Mensagem ao usuário
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa para leitura de tela

}

int deletar()
{
	//Início criação de variáveis/string
	char cpf[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informação do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Localizando CPF existente
				
	if(file == NULL) //Caso o CPF não existe
	{
		printf("\nO usuário não se encontra no sistema!\n\n"); //Mensagem ao usuário
	}
	
	if(file != NULL) //Para CPF existente
	{
		fclose(file);
		remove(cpf);
		printf("\nO CPF foi removido com sucesso!\n\n"); //Mensagem ao usuário 
	}
	
	system("pause"); //Pausa para leitura de tela
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Repetições
	{
		
		system("cls"); //Responsável por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //Início do menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
	
		
		switch(opcao) //Início da sessão do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível!\n\n"); 
			system("pause");
			break;//Fim da sessão
	
		}
			
	}
}

