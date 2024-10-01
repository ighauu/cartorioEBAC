#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //responsável por alocação de espaço de memória, biblioteca de alocação de espaço em memória
#include <locale.h> //biblitoeca de alocação de texto por região
#include <string.h> //biblioteca responsável pela String

int registro() //Função responsável por cadastrar os usuários
{
	char arquivo [40]; // Inicio de criação de variaveis/strings
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo [40]; //Fim da criação de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf ("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar valor das Strings
	
	FILE *file; //cria o arquivo (*file repsonsável pela CRIAÇÃO)
	file = fopen(arquivo, "w"); //criando o arquivo ("w" serve para dizer que o arquivo é novo!)
	fprintf(file, cpf); //Qual arquivo e nome será salvo
	fclose (file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");//Acesso ao arquivo
	fprintf(file,",");
	fclose (file);
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf (file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//Acesso ao arquivo
	fprintf(file,",");
	fclose (file);
	
	printf ("Digite o sobrenome a ser cadastrado: "); // Coletando informações do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //Acesso ao arquivo
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//Acesso ao arquivo
	fprintf(file,",");
	fclose (file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose(file);
	
	system ("pause");
}

int consulta()//Função para consultar dados do usuário
{
	char cpf[40];
	char conteudo[200];
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL) 
	{
		system ("cls"); // Responsável por limpar a tela
		printf ("Não foi possível localizar o Arquivo!\n"); 
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system ("pause");
}
int deletar()//Função para deletar o usuário
{
	char cpf[40];//Variável para cadastrar o CPF
	
	printf ("Digite o CPF a ser deletado: ");//Coletando informação do usuário
	scanf ("%s", cpf);
	
	remove (cpf);
	
	FILE *file; //FILE= Referencia arquivo; *file= o que quer abrir, no caso um arquivo
	file = fopen (cpf, "r"); //fopen para abrir o arquivo, cpf para indicar qual arquivo quero que ele apague, e "r" para indicar que você quer ler o arquivo
	
	if(cpf == NULL);
	{
		printf ("Esse usuário não se encontra no sistema!\n");
		system ("pause");
	}
}

int main()
	{
		int opcao=0; //Definição das variáveis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao; 
	
		printf ("### Cartório de Registros EBAC ###\n\n");
		printf ("Login de Admnistrador!\n\nDigite a sua senha:");
		scanf ("%s",senhadigitada);
		
		comparacao = strcmp (senhadigitada, "admin");
	
		if (comparacao == 0) 
		{
		
		system ("cls");
	
			for (laco=1;laco=1;)//Laço para volta do Menu
			{
		
				system ("cls");//Limpando a tela
		
				setlocale (LC_ALL, "Portuguese"); //Definindo região de lingugaem
		
				printf ("### Cartório de Registros EBAC ###\n\n"); //Início do Menu
				printf ("Escolha a opção desejada:\n\n");
				printf ("\t1 - Registrar nomes\n");
				printf ("\t2 - Consultar nomes\n");
				printf ("\t3 - Deletar nomes\n\n");
				printf ("\t4 - Sair do Sistema\n\n");
				printf ("Opção:   "); //Final do Menu
	
				scanf ("%d", &opcao); //Armazenando escolha do usuário
	
				system("cls");
		
		
				switch(opcao) //Inicio do Menu seleção
				{
					case 1: //chamada de funções
					registro();
					break;
				
					case 2:
					consulta();
					break;
			
					case 3:
					deletar();
					break;
				
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
	
					default:
					printf ("Essa opção não está disponível!\n");
					system ("pause");
				} //Final do Menu Seleção 
			}	
		}
		else
			system ("cls");	
			printf ("Senha incorreta"); //Retorno erro de senha
	}
