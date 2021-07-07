#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>//Para uso da função sleep() contida no "else" da função MenuPricipal()
#include <stdbool.h> //Para uso da var Bool
#include <unistd.h>
#include <signal.h>
#include <string.h>

//========PROGRAMA CRIADO POR: RAFAEL RESTOLHO RIBEIRO========
//PROGRAMADO NA IDE: CODE::BLOCKS 20.03
//PEÇO QUE LEIA O COMENTARIO SOBRE POPULAÇÃO ANTES DE INICIAR O CODIGO

struct Projeto{//Struct para registro de projetos
	//"Iremos armazenar os campos básicos de um projeto, tais como:
	//Código, Titulo, Descrição, Ano, Status e o Gerente de Projetos responsável"
	int codigo_proj;
	int anoInicio_proj;
	int status_proj;
	char gerente_proj[30];
	char titulo_proj[30];
	char descricao_proj[100];
	// "[...] e incluir mais 3 campos que julgar necessário."
	float custo_proj;
	char recursos_proj[100];
	int anoConclusao_proj;

	bool validado; //Bool usada para verificar se o vetor ja esta preenchido
	}str_proj[200];

int main(){
	setlocale(LC_ALL, "Portuguese");
    setlocale(LC_ALL,"");

    /*            LEIA-ME:
      Aqui estou populando o STRUCT para caso
      queira consultar o LISTAR PROJETOS sem precisar
      ficar cadastrando um por um*/

    str_proj[0] = (struct Projeto){0,2020,1,"RAFAEL","Casa","Construir uma casa",50000.00,"Cimento, areia, tijolo",2021,true};
    str_proj[1] = (struct Projeto){1,2017,2,"REINALDO","Apartamento","Construir um Apartamento",80000.00,"Cimento, areia, tijolo",2019,true};
    str_proj[2] = (struct Projeto){2,2018,3,"JOAO","Campo de Futebol","Campo de Futebol",100000.00,"Mão de obra comunitária",2020,true};
    str_proj[3] = (struct Projeto){3,2019,3,"JULIA","Mesa","Construir uma mesa",500.00,"Madeira, prego",2019,true};

    //Caso queira cadastrar manualmente peço que comente esse bloco de codigo
	MenuPrincipal();
	return 0;
}
void cabecalho(){//Função para facilitar a exibição do cabeçalho.

	printf("=============================================================\n");
	printf("\n         BEM VINDO AO GERENCIADOR DE PROJETOS ATHENA\n");
	printf("\n            by Rafael R. Ribeiro \n");
	printf("\n=============================================================");}
void CadastrarProjeto(){//Função para cadastrar projetos
	system("cls");
	int cadastros_num,i,quantidade_proj=0,parar=0;
	for(i=0;i<200;i++){
		system("cls");
		cabecalho();
		if(str_proj[i].validado != false){
			//Esse if verifica se a Array ja está preenchida, se sim, ele passa para a proxima
			i++;
		}else{
		printf("\nInforme o titulo do projeto:\n=>");
		scanf("%s", str_proj[i].titulo_proj);

		fflush(stdin);
		system("cls");
		cabecalho();
		printf("\nDigite a descricao do projeto:\n=>");
		scanf("%s", str_proj[i].descricao_proj);

		fflush(stdin);
		system("cls");
		cabecalho();
		printf("\nDigite o ano de inicio do projeto:\n=>");
		scanf("%d", &str_proj[i].anoInicio_proj);
		printf("\nDigite o ano de conclusao do projeto:\n=>");
		scanf("%d", &str_proj[i].anoConclusao_proj);

		fflush(stdin);
		system("cls");
		cabecalho();
		printf("\nInforme o nome do gerente responsavel pelo projeto:\n=>");
		scanf("%s", str_proj[i].gerente_proj);

		fflush(stdin);
		system("cls");
		cabecalho();
		printf("\nInforme qual será o custo do projeto:\n=>R$ ");
		scanf("%f", &str_proj[i].custo_proj);

		fflush(stdin);
		system("cls");
		cabecalho();
		printf("\nInforme quais recursos serão usados na realização do projeto:\n=>");
		scanf("%s", str_proj[i].recursos_proj);

		fflush(stdin);
		system("cls");
		cabecalho();
		int status1=0;
		char status2[20];
		printf("\nDigite o status do projeto:");
		printf("\n1-A FAZER \n2-FAZENDO \n3-CONCLUÍDO");
		printf("\n=>");
		scanf("%d", &status1);
		str_proj[i].status_proj=status1;
		if(status1==1){
			strcpy(status2,"A FAZER");
		}else if(status1==2){
			strcpy(status2,"FAZENDO");
		}else if(status1==3){
			strcpy(status2,"CONCLUÍDO");
		}

		str_proj[i].codigo_proj=i;
		str_proj[i].validado=true;
		fflush(stdin);
		system("cls");
		cabecalho();
		printf("\n\nCONFIRA OS DADOS\n\nCÓDIGO: %d\nTítulo do Projeto: %s\nDescrição do Projeto: %s\nAno de ínicio do Projeto: %d\nAno de conclusão do Projeto: %d\nGerente do Projeto: %s\nCusto do Projeto: R$%.2f\nRecursos a serem utilizados: %s\nStatus do Projeto: %s\n",str_proj[i].codigo_proj,str_proj[i].titulo_proj,str_proj[i].descricao_proj,str_proj[i].anoInicio_proj,str_proj[i].anoConclusao_proj,str_proj[i].gerente_proj,str_proj[i].custo_proj,str_proj[i].recursos_proj,status2);
		printf("");
		printf("\n===================================");
		printf("\nDeseja cadastrar mais projetos?");
		printf("\n===================================\n");
		int escolha_cad;
		printf("\n1-SIM 2-NAO");
		printf("\n=>");
		scanf("%d", &escolha_cad);
		switch(escolha_cad){
			case 1:
				continue;
			case 2:
				break;
		}
		goto menu;//usado para pular para fora do if, loop e voltar para o menu principal
		}

	}
	menu:;
	fflush(stdin);
	system("cls");
	main();}
int ListarProjetosFiltro(int stat){//Função para facilitar o filtro de status
    int cont;
    system("cls");
		    if(str_proj[0].validado == false)
            {
                system("cls");
                cabecalho();
                int escolha_case1, i_case1=0;
                printf("\nNenhum projeto cadastrado\n\nVoltando para o menu de projetos, aguarde");
                while(i_case1<5)
                {
                    printf(".");
                    usleep(500000);
                    i_case1++;
                }
                goto inicio_list;
		    }
		    else{
		        cabecalho();
		        char status_list[10];
                for(cont=0;cont<200;cont++)
                {
                    if(str_proj[cont].status_proj != stat)
                    {
                        cont++;
                    }
                    if(str_proj[cont].validado == false)
                    {
                        break;
                    }
                    else if(str_proj[cont].status_proj == stat)
                    {
                        if(str_proj[cont].status_proj==1){
                            strcpy(status_list,"A FAZER");
                        }else if(str_proj[cont].status_proj==2){
                            strcpy(status_list,"FAZENDO");
                        }else if(str_proj[cont].status_proj==3){
                            strcpy(status_list,"CONCLUÍDO");
                        }

                        printf("\n==================================================");
                        printf("\nTitulo do Projeto: %s\nDescrição do Projeto: %s\nAno de Ínicio do Projeto: %d\nAno previsto para conclusão: %d\nGerente do Projeto: %s\nCusto do Projeto: R$%.2f\nRecursos a serem utilizados: %s\nStatus do Projeto: %s",
                            str_proj[cont].titulo_proj,
                            str_proj[cont].descricao_proj,
                            str_proj[cont].anoInicio_proj,
                            str_proj[cont].anoConclusao_proj,
                            str_proj[cont].gerente_proj,
                            str_proj[cont].custo_proj,
                            str_proj[cont].recursos_proj,
                            status_list
                        );//fim printf
                        printf("\n==================================================\n");
                    }
                }
                fflush(stdin);
                int escolha_list2;
                printf("\nDeseja continuar?\n(1)-SIM\n(2)-NÃO\n=>");
                scanf("%d", &escolha_list2);
                switch(escolha_list2){
                case 1:
                system("cls");
                MenuPrincipal();
                break;
                case 2:
                exit(0);
                break;}

		    }
		    inicio_list:system("cls");main();
}
void ListarProjetos(){//Função para listar projetos
	int escolha_list;
	int cont;
	system("cls");
	cabecalho();
	printf("\n  (1)  TODOS PROJETOS");
	printf("\n  (2)  TODOS PROJETOS A FAZER");
	printf("\n  (3)  TODOS PROJETOS SENDO FEITOS");
	printf("\n  (4)  TODOS PROJETOS CONCLUÍDOS");
	printf("\n  (5)  LISTAR POR GERENTE");
	printf("\n=>");
	scanf("%d", &escolha_list);
	switch(escolha_list)
	{
		case 1:
		    system("cls");
		    if(str_proj[0].validado == false){
                system("cls");
                cabecalho();
                int escolha_case1, i_case1=0;
                printf("\nNenhum projeto cadastrado\n\nVoltando para o menu de projetos, aguarde");
                while(i_case1<5){
                    printf(".");
                    usleep(500000);
                    i_case1++;
                }
                goto inicio_list;

		    }else{
		        cabecalho();
		        char status_list[10];
                for(cont=0;cont<200;cont++){

                    if(str_proj[cont].validado == false){
                        break;
                    }else
                    {
                        if(str_proj[cont].status_proj==1){
                            strcpy(status_list,"A FAZER");
                        }else if(str_proj[cont].status_proj==2){
                            strcpy(status_list,"FAZENDO");
                        }else{
                            strcpy(status_list,"CONCLUÍDO");
                        }

                        printf("\n==================================================");
                        printf("\nTitulo do Projeto: %s\nDescrição do Projeto: %s\nAno de Ínicio do Projeto: %d\nAno previsto para conclusão: %d\nGerente do Projeto: %s\nCusto do Projeto: R$%.2f\nRecursos a serem utilizados: %s\nStatus do Projeto: %s",
                            str_proj[cont].titulo_proj,
                            str_proj[cont].descricao_proj,
                            str_proj[cont].anoInicio_proj,
                            str_proj[cont].anoConclusao_proj,
                            str_proj[cont].gerente_proj,
                            str_proj[cont].custo_proj,
                            str_proj[cont].recursos_proj,
                            status_list
                        );//fim printf
                        printf("\n==================================================\n");
                    }
                }
                fflush(stdin);
                int escolha_list2;
                printf("\nDeseja continuar?\n(1)-SIM\n(2)-NÃO\n=>");
                scanf("%d", &escolha_list2);
                switch(escolha_list2){
                case 1:
                system("cls");
                MenuPrincipal();
                break;
                case 2:
                exit(0);
                break;
                }
		    }
			break;
		case 2:
		    ListarProjetosFiltro(1);
		    break;
		case 3:
		    ListarProjetosFiltro(2);
		    break;
		case 4:
		    ListarProjetosFiltro(3);
		    break;
        case 5://Listar por gerente
            system("cls");

		    if(str_proj[0].validado == false)
            {
                system("cls");
                cabecalho();
                int escolha_case1, i_case1=0;
                printf("\nNenhum projeto cadastrado\n\nVoltando para o menu de projetos, aguarde");
                while(i_case1<5)
                {
                    printf(".");
                    usleep(500000);
                    i_case1++;
                }
                goto inicio_list;
		    }
		    else
            {
                int cont5=0;
		        cabecalho();
		        char status_list[10];
		        char gerente[30];
		        char gerenteproj[30];
		        fflush(stdin);
		        printf("\nInforme o nome do gerente\n=>");
		        scanf("%s", gerente);
                for(cont5=0;cont5<200;cont5++)
                {
                    if(str_proj[cont5].status_proj==1){strcpy(status_list,"A FAZER");}
                    else if(str_proj[cont5].status_proj==2){strcpy(status_list,"FAZENDO");}
                    else{strcpy(status_list,"CONCLUÍDO");}

                    strcpy(gerenteproj,str_proj[cont5].gerente_proj);
                    //strcpy(gerenteproj,str_proj[cont5].gerente_proj]);
                    if(gerenteproj != gerente)
                    {
                        cont5++;
                    }
                    else if(str_proj[cont5].validado == false){break;}

                    else if(gerenteproj == gerente){
                    printf("\n==================================================");
                    printf("\nTitulo do Projeto: %s\nDescrição do Projeto: %s\nAno de Ínicio do Projeto: %d\nAno previsto para conclusão: %d\nGerente do Projeto: %s\nCusto do Projeto: R$%.2f\nRecursos a serem utilizados: %s\nStatus do Projeto: %s",
                        str_proj[cont5].titulo_proj,
                        str_proj[cont5].descricao_proj,
                        str_proj[cont5].anoInicio_proj,
                        str_proj[cont5].anoConclusao_proj,
                        str_proj[cont5].gerente_proj,
                        str_proj[cont5].custo_proj,
                        str_proj[cont5].recursos_proj,
                        status_list
                    );//fim printf
                    printf("\n==================================================\n");}
                }
                fflush(stdin);
                int escolha_list2;
                printf("\nDeseja continuar?\n(1)-SIM\n(2)-NÃO\n=>");
                scanf("%d", &escolha_list2);
                switch(escolha_list2){
                case 1:
                system("cls");
                MenuPrincipal();
                break;
                case 2:
                exit(0);
                break;}
		    }
		    inicio_list:system("cls");main();
            break;
	}
}
void MenuPrincipal(){//Função para abrir o menu de opções
	inicio:;
	int escolha;
	fflush(stdin);
	cabecalho();
	printf("\n  (1)  CADASTRAR PROJETO");
	printf("\n  (2)  LISTAR PROJETO");
	printf("\n  (3)  SAIR");
	printf("\n=>");
	scanf("%d", &escolha);
	if(escolha==1){
		CadastrarProjeto();
	}else if(escolha==2){
		ListarProjetos();
	}else if(escolha==3){
        exit(0);
	}else{
		system("cls");
		cabecalho();
		printf("\nDigite uma opcao valida");
		sleep(0.8);
		printf(".");
		sleep(0.8);
		printf(".");
		sleep(0.8);
		printf(".");
		sleep(0.8);
		//Funcoes sleep usadas para dar tempo do usuario ler e adicionar o "efeito" dos pontos piscando
		system("cls");
		goto inicio; //Volta para o inicio da função MenuPrincipalç()
	}}

