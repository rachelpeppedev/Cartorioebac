#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: "); //Nome ao valor 
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo o "a" � para atualizar a informa��o
	fprintf(file,",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo o "a" � para atualizar a informa��o
	fprintf(file, " Nome: "); //Nome ao valor
	fprintf(file,nome); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo 
	fprintf(file,","); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", sobrenome); 
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo
	fprintf(file, " Sobrenome: "); //Nome ao valor
	fprintf(file,sobrenome); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo
	fprintf(file,","); 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo
	fprintf(file, " Cargo: "); //Nome ao valor
	fprintf(file,cargo); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa para leitura de tela
}
	
int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Localizando CPF existente
	
	if(file == NULL) //Caso o CPF n�o existe
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n"); //Mensagem ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto tiver conte�do dentro do arquivo armazena dentro da vari�vel
	{
		printf("\nEssas s�o as informa��es do usu�rio:"); //Mensagem ao usu�rio
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa para leitura de tela

}

int deletar()
{
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Localizando CPF existente
				
	if(file == NULL) //Caso o CPF n�o existe
	{
		printf("\nO usu�rio n�o se encontra no sistema!\n\n"); //Mensagem ao usu�rio
	}
	
	if(file != NULL) //Para CPF existente
	{
		fclose(file);
		remove(cpf);
		printf("\nO CPF foi removido com sucesso!\n\n"); //Mensagem ao usu�rio 
	}
	
	system("pause"); //Pausa para leitura de tela
}

int main()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
		
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo vari�veis
	char loginusuario[10]="a"; //Definindo vari�veis
	char senhadigitada[10]="a"; //Definindo vari�veis
	int comparacao; //Para comparar duas vari�veis
	
	printf("### Cart�rio da EBAC ### \n\n"); //Inicio da tela
	printf(" Login de administrador!\n\n Digite seu login:\n\n "); //Acesso atrav�s do Login - Mensagem ao usu�rio
	scanf("%s", loginusuario); //Valor da variavel
	
	comparacao = strcmp(loginusuario, "master"); //Compara��o vari�vel com valor
	
	if(comparacao == 0); //Valida��o da compara��o
	
	else
	{
		printf("\n\nLogin Incorreto!\n\n"); //Se o valor da vari�vel estiver incorreto.
		return(0); //Estando incorreto, finaliza.
	}	
	
	printf("\n\nDigite a sua senha: \n\n");	//Ap�s login correto, digitar a senha - Mensagem ao usu�rio
	scanf("%s",senhadigitada); //Valor da variavel
	
	comparacao = strcmp(senhadigitada, "admin");//Compara��o vari�vel com valor
		
	if(comparacao == 0)//Valida��o da compara��o
	{
		system("cls");
		for(laco=1;laco=1;) //Repeti��es
		{
		
			system("cls"); //Respons�vel por limpar a tela
		
			printf("### Cart�rio da EBAC ### \n\n"); //In�cio do menu
			printf("Escolha a op��o desejada no menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //Fim do menu
	
			scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
			system("cls"); //Respons�vel por limpar a tela
	
		
			switch(opcao) //In�cio da sess�o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("\n\nObrigado por utilizar o sistema!\n\n");
				return 0;
				break;
			
				default:
				printf("Esta op��o n�o est� dispon�vel!\n\n"); 
				system("pause");
				break;//Fim da sess�o
			}
	
		}
			
	}
	
	else
		printf("\n\nSenha incorreta!\n\n");//Se o valor da vari�vel estiver incorreto.
		
}

