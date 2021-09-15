#include <stdio.h> // fprintf, printf, fscanf, scanf, getchar, putc, getc, fopen e fclose;
#include <stdlib.h> //abs, atof, atol, rand, malloc, realloc, free e system;
#include <string.h> //strcpy, strcat, strcmp, strlen, memcpy, memmove e memcmp;
#include <conio.h> // getch, getche, kbhit, clrscr, delline, gotoxy, textcolor, textbackground e cprintf. Manipula caracteres na tela;
#include <locale.h> // colocar acentuação no prompt
#include <stdbool.h> // boolean type and values

/*Criando a struct cliente*/
typedef struct
{
	char nome[30];
	int anoNascimento;
	float gastosMes;
} Cliente;

typedef struct
{
	Cliente *pCliente;
	int qtdClientes;
} ListaClientes;

void criarListaVazia (ListaClientes *listaC)
{
	listaC->pCliente = (Cliente *) malloc(10*sizeof(Cliente));
	listaC->qtdClientes = 0;
}

void cadastrarCliente (ListaClientes *listaC)
{
	system("cls");
	
	if (listaC->qtdClientes % 10 == 0) // indicativo de necessidade em aumento na alocação de memória
	{
		int qtdBlocos = (listaC->qtdClientes / 10) + 1;
		listaC->pCliente = (Cliente *) realloc(listaC->pCliente, (qtdBlocos*10)*sizeof(Cliente));
	}
	
	Cliente cliente;

	printf("Entre com o nome do cliente: ");
	scanf("%s", &cliente.nome);
	printf("Entre com o ano de nascimento: ");
	scanf("%d", &cliente.anoNascimento);
	printf("Entre com o montante de gastos realizados no mês: ");
	scanf("%f", &cliente.gastosMes);

	memcpy(listaC->pCliente + (listaC->qtdClientes), &cliente, sizeof(Cliente));
	(listaC->qtdClientes)++;
			
	printf("\nPressione qualquer tecla para continuar. . . \n");
	getch();

}

void removerCliente (ListaClientes *listaC, Cliente *cliente)
{
	system("cls");
	
	if ((listaC->qtdClientes) == 0)
		printf("Nenhum cliente cadastrado.\n");
	else 
	{
		int pos = buscarCliente(listaC, cliente);
		
		if (pos == -1)
			printf ("Cliente não encontrado.\n");
		else
		{
			int i;
		
			for (i = pos; i < (listaC->qtdClientes)-1; i++)
				memcpy ((listaC->pCliente+i),(listaC->pCliente+i+1),sizeof(Cliente));
		
			(listaC->qtdClientes)--;
			
			printf("\nCliente removido com sucesso!\n");
		
			if (listaC->qtdClientes % 10 == 0) // indicativo de necessidade de redução na memória alocada
			{
				int qtdBlocos = (listaC->qtdClientes / 10) + 1;
				listaC->pCliente = (Cliente *) realloc(listaC->pCliente, (qtdBlocos*10)*sizeof(Cliente));
			}
	
		}
	}
	printf("\nPressione qualquer tecla para continuar. . . \n");
	getch();
	
}

void atualizarGastos (ListaClientes listaC, Cliente *cliente)
{
	system("cls");
		
	if ((listaC.qtdClientes) == 0)
		printf("Nenhum cliente cadastrado.\n");
	
	else
	{
		
		int pos = buscarCliente(listaC, cliente);
		
		if (pos == -1)
			printf ("Cliente não encontrado.\n");
		else
		{
			float novosGastos = 0;
			
			printf ("Entre com o novo valor de gastos mensais: \n");
			scanf ("%f", &novosGastos);
			
			(listaC.pCliente+pos)->gastosMes = novosGastos;
		}
		
	}
	
	printf("\nPressione qualquer tecla para continuar. . . \n");
	getch();
		
}

void zerarGastosMensais(ListaClientes listaC)
{
	system("cls");
	
	if ((listaC.qtdClientes) == 0)
		printf("Nenhum cliente cadastrado.\n");
	else
	{
		int i;
		for (i = 0; i < (listaC.qtdClientes); i++)
			(listaC.pCliente+i)->gastosMes = 0;
		printf("Gastos mensais de todos os clientes zerados com sucesso!\n");
	}
	
	printf("\nPressione qualquer tecla para continuar. . . \n");
	getch();
	
}

void buscarMelhorCliente (ListaClientes listaC, Cliente *cliente)
{
	system("cls");

	if ((listaC.qtdClientes) == 0)
		printf("Nenhum cliente cadastrado.\n");
	else
	{
		int i, maiorGasto = 0;
	
		for (i = 0; i < (listaC.qtdClientes); i++)
		{				
			if ((listaC.pCliente+i)->gastosMes > maiorGasto)
			{
				maiorGasto = (listaC.pCliente+i)->gastosMes;
				cliente = (listaC.pCliente+i);
			}
		}
		if (maiorGasto == 0)
			printf("Os clientes não possuem gastos no mês atual.\n");
		else
		{
			printf ("Cliente melhor comprador do mês: %s\n", cliente->nome);
			printf ("Gastos no mês atual: %f\n", cliente->gastosMes);			
		}
			
	}
	
	printf("\nPressione qualquer tecla para continuar. . . \n");
	getch();
		
}

void exibirGastosCliente (ListaClientes listaC, Cliente *cliente)
{
	system("cls");
	
	int pos = buscarCliente(listaC, cliente);
	
	if (pos == -1)
			printf ("Cliente não encontrado.\n");
	else
		printf("\nGastos do cliente %s = %f\n", ((listaC.pCliente+pos)->nome), ((listaC.pCliente+pos)->gastosMes));
	
	printf("\nPressione qualquer tecla para continuar. . . \n");
	getch();
	
}

int buscarCliente (ListaClientes listaC, Cliente *cliente)
{
	
	if ((listaC.qtdClientes) == 0)
		printf("Nenhum cliente cadastrado.\n");
	else
	{
		char nome[30];
		
		printf ("Entre com o nome do cliente: \n");
		scanf ("%s", &nome);
				
		int i = 0;
		for (; i < (listaC.qtdClientes); i++)
		{
			if (!strcmp(nome,(listaC.pCliente+i)->nome))
			{
				cliente = (listaC.pCliente+i);
				return i;
			}
		}
			
	}
	
	return -1; // Indica que o valor não foi encontrado
	
}

void main() {
	
	// aceitar acentuação no prompt
	setlocale(LC_ALL, "Portuguese");
	
	ListaClientes listaC;
	ListaClientes *pListaC = &listaC;

	Cliente cliente;
	Cliente *pCliente = &cliente;
	
	criarListaVazia (pListaC);
	
	int opcao = 0;
	bool continua = true;
	bool valido = false;
	
	while (continua) {
		
		system("cls");
		
		printf("\n=== SOFTWARE PARA CONTROLE DE CLIENTES ===\n");
	
		printf("\n[1] Incluir novo cliente\n[2] Remover cliente\n[3] Atualizar o montante de compras do cliente realizadas no mês\n[4] Zerar todos os montantes de compras por ocasião da virada de mês\n[5] Listar o cliente melhor comprador\n[6] Exibir um montante de compras de um  cliente específico\n[7] Sair\n");
		
		valido = false;
		while (!valido) {
			printf("\nEscolha uma opção: ");
			scanf("%d", &opcao);
			if (opcao < 1 || opcao > 7) {
				printf ("Opção inválida! Tente novamente.");
			} else {
				valido = true;
			}
		}
	
		switch (opcao) {
			case 1: cadastrarCliente(pListaC); break;
			case 2: removerCliente(pListaC, pCliente); break;
			case 3: atualizarGastos(listaC, pCliente); break;
			case 4: zerarGastosMensais(listaC); break;
			case 5: buscarMelhorCliente(listaC, pCliente); break;
			case 6: exibirGastosCliente(listaC, pCliente); break;
			case 7: continua = false; break;
		}
	}
	printf("\nEncerrando...");
	free(pListaC->pCliente);
	
}
