#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsãvel por cuidar das string

int registro() //função responsávl porcadastrar os usuários no sistema
{
	//início da criação de variáveis/string
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
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" vem de write que é de escrever
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

    printf("Cadastro concluído!\n\n");
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
        printf("Arquivo não encontrado!\n");
    }
    else
    {
        fscanf(file, "%[^,],%[^,],%[^,],%[^\n]", cpf, nome, sobrenome, cargo);
        fclose(file);

        printf("\nInformações do usuário:\n");
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
    
    char cpf[40]; //variável a ser consultado
	
	printf("Digite o CPF do usuário a ser deletado: "); 
    scanf("%s",cpf);
    
    FILE *file; //abrindo e lendo o arquivo
    file = fopen(cpf, "r");
    
    if(file == NULL) //Usuário não existente
    {
    	printf("O usuário não se encontra no sistema!\n");
    	system("pause");
	}
    else //opção alternativa
  {
	fclose(file); //fecha arquivo
	remove(cpf); //remove cpf
	printf("Usuário deletado do sistema!\n");
	system("pause"); 
  }

}


int main() {
    int opcao = 0;
    int laco = 1;

    for (laco = 1; laco == 1;) {
        system("cls"); 
        setlocale(LC_ALL, "Portuguese"); //Definindo linguagem

        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");

        scanf("%d", &opcao);

        system("cls"); //responsável por limpar a tela

        switch (opcao) 
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
            
            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        } //fim da seleção
    }

    return 0;
}

