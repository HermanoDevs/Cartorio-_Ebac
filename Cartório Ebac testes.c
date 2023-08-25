#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vl porcadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string

    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" vem de write que � de escrever
    fprintf(file, "%s", cpf); // salva o valor da variavel
   

    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf(" %[^\n]s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);

    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf(" %[^\n]s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);

    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf(" %[^\n]s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);

    fclose(file);

    printf("Cadastro conclu�do!\n\n");
    system("pause");
}

int consulta() 
{
    setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
    
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char conteudo[200];
  
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
  
    FILE *file;
    file = fopen(cpf, "r");
  
    if (file == NULL)
    {
        printf("Arquivo n�o encontrado!\n");
    }
    else
    {
        fscanf(file, "%[^,],%[^,],%[^,],%[^\n]", cpf, nome, sobrenome, cargo);
        fclose(file);

        printf("\nInforma��es do usu�rio:\n");
        printf("CPF: %s\n", cpf);
        printf("Nome: %s %s\n", nome, sobrenome);
        printf("Cargo: %s\n\n", cargo);
    }
    
    system("pause");
	
	printf("Pressione Enter para continuar...");
    getchar();
    getchar();
}
  
  
    


int deletar()
  {
    
    char cpf[40]; //vari�vel a ser consultado
	
	printf("Digite o CPF do usu�rio a ser deletado: "); 
    scanf("%s",cpf);
    
    FILE *file; //abrindo e lendo o arquivo
    file = fopen(cpf, "r");
    
    if(file == NULL) //Usu�rio n�o existente
    {
    	printf("O usu�rio n�o se encontra no sistema!\n");
    	system("pause");
	}
    else //op��o alternativa
  {
	fclose(file); //fecha arquivo
	remove(cpf); //remove cpf
	printf("Usu�rio deletado do sistema!\n");
	system("pause"); 
  }

}


int main() {
    int opcao = 0;
    int laco = 1;

    for (laco = 1; laco == 1;) {
        system("cls"); 
        setlocale(LC_ALL, "Portuguese"); //Definindo linguagem

        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��o: ");

        scanf("%d", &opcao);

        system("cls"); //respons�vel por limpar a tela

        switch (opcao) 
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
            
            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        } //fim da sele��o
    }

    return 0;
}

