#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //respons�vel por aloca��o de espa�o de mem�ria, biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblitoeca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pela String

int registro() //Fun��o respons�vel por cadastrar os usu�rios
{
	char arquivo [40]; // Inicio de cria��o de variaveis/strings
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo [40]; //Fim da cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf ("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar valor das Strings
	
	FILE *file; //cria o arquivo (*file repsons�vel pela CRIA��O)
	file = fopen(arquivo, "w"); //criando o arquivo ("w" serve para dizer que o arquivo � novo!)
	fprintf(file, cpf); //Qual arquivo e nome ser� salvo
	fclose (file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");//Acesso ao arquivo
	fprintf(file,",");
	fclose (file);
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf (file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//Acesso ao arquivo
	fprintf(file,",");
	fclose (file);
	
	printf ("Digite o sobrenome a ser cadastrado: "); // Coletando informa��es do usu�rio
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

int consulta()//Fun��o para consultar dados do usu�rio
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
		system ("cls"); // Respons�vel por limpar a tela
		printf ("N�o foi poss�vel localizar o Arquivo!\n"); 
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system ("pause");
}
int deletar()//Fun��o para deletar o usu�rio
{
	char cpf[40];//Vari�vel para cadastrar o CPF
	
	printf ("Digite o CPF a ser deletado: ");//Coletando informa��o do usu�rio
	scanf ("%s", cpf);
	
	remove (cpf);
	
	FILE *file; //FILE= Referencia arquivo; *file= o que quer abrir, no caso um arquivo
	file = fopen (cpf, "r"); //fopen para abrir o arquivo, cpf para indicar qual arquivo quero que ele apague, e "r" para indicar que voc� quer ler o arquivo
	
	if(cpf == NULL);
	{
		printf ("Esse usu�rio n�o se encontra no sistema!\n");
		system ("pause");
	}
}

int main()
	{
		int opcao=0; //Defini��o das vari�veis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao; 
	
		printf ("### Cart�rio de Registros EBAC ###\n\n");
		printf ("Login de Admnistrador!\n\nDigite a sua senha:");
		scanf ("%s",senhadigitada);
		
		comparacao = strcmp (senhadigitada, "admin");
	
		if (comparacao == 0) 
		{
		
		system ("cls");
	
			for (laco=1;laco=1;)//La�o para volta do Menu
			{
		
				system ("cls");//Limpando a tela
		
				setlocale (LC_ALL, "Portuguese"); //Definindo regi�o de lingugaem
		
				printf ("### Cart�rio de Registros EBAC ###\n\n"); //In�cio do Menu
				printf ("Escolha a op��o desejada:\n\n");
				printf ("\t1 - Registrar nomes\n");
				printf ("\t2 - Consultar nomes\n");
				printf ("\t3 - Deletar nomes\n\n");
				printf ("\t4 - Sair do Sistema\n\n");
				printf ("Op��o:   "); //Final do Menu
	
				scanf ("%d", &opcao); //Armazenando escolha do usu�rio
	
				system("cls");
		
		
				switch(opcao) //Inicio do Menu sele��o
				{
					case 1: //chamada de fun��es
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
					printf ("Essa op��o n�o est� dispon�vel!\n");
					system ("pause");
				} //Final do Menu Sele��o 
			}	
		}
		else
			system ("cls");	
			printf ("Senha incorreta"); //Retorno erro de senha
	}
