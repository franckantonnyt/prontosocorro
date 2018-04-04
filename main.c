#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*FILA DE PRIORIDADE PRONTO SOCORRO
-DUAS VISOES-
-	Atendente - 
Cadastrar paciente(inserir paciente na fila)
dados(nome,pressao,temperatura,sintoma,condiÃ§Ã£o(vermelho>amarelo>verde>azul)))

-	Medico - 
chamar paciente(Tirar paciente da fila)
listar paciente(listar todos os pacientes)
*/
typedef struct lista{
	char nome[30];
	float pressao;
	float temperatura;
	char sintoma[30];
	int condicao;
	struct lista *prox;
}li;
//cria lista
void cria_lista(li *fim, li *in)
{
	in = (li*)malloc(sizeof(li));
	if(in == NULL)
	{
		printf("Erro");
		return;
	}else
	{
		printf("OK\n");
		fim = in;
	}
}
//cadastrar paciente
void cadastrar(li *fim)
{
	printf("Cadastrar Paciente\nNome - ");
	scanf(" %[^\n]s", fim->nome);
	printf("Pressao - ");
	scanf("%f",&fim->pressao);
	printf("temperatura - ");
	scanf("%f",&fim->temperatura);
	printf("Sintoma - ");
	scanf(" %[^\n]s", fim->sintoma);
	printf("\nCondicao\n4 - Vermelho\n3 - Amarelo\n2 - Verde\n1 - Azul\n");
	scanf("%i",&fim->condicao);
	fim->prox = (li*) malloc(sizeof(li));
	fim = fim->prox;
	fim->prox = NULL;
}
//chamar paciente
void chamar(li *in)
{
	li *aux;
	printf("- Paciente -\nNome - %s\nPressao - %f\nTemperatura - %f\nSintoma - %s\nCondição - %i",in->nome,in->pressao,in->temperatura,in->sintoma,in->condicao);
	aux = in;
	in = in->prox;
	free(aux);
}
//listar paciente
void listar(li *fim, li *in)
{
	fim = in;
	do
	{
		printf("- Paciente -\nNome - %s\nPressao - %f\nTemperatura - %f\nSintoma - %s\nCondição - %i\n",fim->nome,fim->pressao,fim->temperatura,fim->sintoma,fim->condicao);
		fim = fim->prox;
	}while(fim->prox != NULL);	
}
int main(){
	li *in, *fim;
	int x,p=0;
	cria_lista(fim, in);
	do{
		printf("1 - Atendente\n2 - Medico\n3 - Sair\n");
		scanf("%i",&x);
		switch(x)
		{
			case 1:
				cadastrar(fim);
				break;
			case 2:
				printf("1 - Chamar Paciente\n2 - Listar Pacientes\n");
				scanf("%i",&p);
				if(p == 1)
				{
					chamar(in);
				}else if(p == 2)
				{
					listar(fim,in);					
				}
				break;
			case 3:

				break;
		}
	}while(x != 3);
	return 0;
}
