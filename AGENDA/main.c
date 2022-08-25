#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parte do deque(Pessoa)
typedef struct Contato
{
  char *email;
  char *nome;
  char *numero;
	struct Contato* anterior;
} Contato; //no -> stack

typedef struct Pessoa
{
  Contato* contato;
	int id;
  struct Pessoa* proximo;
  struct Pessoa* anterior;
	struct Stack* stack;
} Pessoa;

// Deque
typedef struct
{
  Pessoa* cabeca;
  Pessoa* cauda;
} Deque;

typedef struct Stack
{
	Contato* topo;
} Stack;

void lixo(void)
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void input(char *string, int max)
{
  long unsigned int i = 0;

  fgets(string, max, stdin);
  do {
    if (string[i] == '\n') {
      string[i] = '\0';
      break;
    }
    i++;
  } while (i < strlen(string));
}

void limpar(void)
{
  #ifdef __linux__
    system("clear");

  #elif _WIN32
    system("cls");
  #else

  #endif
}

Deque* criar()
{
	Deque* deque = malloc(sizeof(Deque));
	deque->cabeca = NULL;
	deque->cauda = NULL;

	return deque;
}

Stack* criarS()
{
	Stack* stack = malloc(sizeof(Stack));
  stack->topo = NULL;

  return stack;
}

int dequeVazio(Deque* deque)
{
  return deque->cabeca == NULL && deque->cauda == NULL;
}

int stackVazia(Stack* stack)
{
	return stack->topo == NULL;
}

int menuPrincipal()
{
  int option;
	printf("\n--------\n AGENDA \n--------\n");
	printf("(0) Sair\n");
	printf("(1) Adicionar contato\n");
	printf("(2) Alterar contato\n");
	printf("(3) Desfazer ultima alteracao do contato\n");
	printf("(4) Remover contato\n");
	printf("(5) Exibir contatos\n\n");

  printf("Sua opcao: ");
  scanf("%d", &option);

  limpar();

  return option;
}

int menuReduzido()
{
  int option;
  
	printf("\n--------\n AGENDA \n--------\n");
	printf("(0) Sair\n");
	printf("(1) Adicionar contato\n");

  printf("Sua opcao: ");
  scanf("%d", &option);

  limpar();

  return option;
}

void adicionar(Deque* deque, char *email, char *numero, char *nome, int id) 
{
	Pessoa* pessoa = malloc(sizeof(Pessoa));
	pessoa->stack = malloc(sizeof(Stack));
	pessoa->stack->topo = malloc(sizeof(Contato));
	pessoa->stack->topo->nome = malloc(strlen(nome)+1);
	strcpy(pessoa->stack->topo->nome, nome);
	pessoa->stack->topo->email = malloc(strlen(email)+1);
	strcpy(pessoa->stack->topo->email, email);
	pessoa->stack->topo->numero = malloc(strlen(numero)+1);
	strcpy(pessoa->stack->topo->numero, numero);
 	pessoa->stack->topo->anterior = NULL;
	pessoa->id = id;
	
	pessoa->proximo = NULL;
	pessoa->anterior = (struct Pessoa*) deque->cauda;

	if (dequeVazio(deque))
	{
		deque->cabeca = pessoa;
	}
	else
	{        
		deque->cauda->proximo = (struct Pessoa*) pessoa;
	}

	deque->cauda = pessoa;
}

void percorrer(Deque* deque)
{
	Pessoa* pessoa = deque->cabeca;

	while(pessoa != NULL)
	{	
		printf("\n");
		printf("ID#%d", pessoa->id);
		printf("\n");
		printf("Nome: %s", pessoa->stack->topo->nome);
		printf("\n");
		printf("Email: %s", pessoa->stack->topo->email);
		printf("\n");
		printf("Numero: %s", pessoa->stack->topo->numero);
		printf("\n");
		pessoa = (Pessoa*) pessoa->proximo;
		printf("\n");
	}
	printf("###############################\n");
}

void remover(Deque* deque, int id)
{
	Pessoa* pessoa = deque->cabeca;

	Pessoa* remove = NULL;
	if(deque->cabeca != NULL && deque->cabeca->id == id)
	{
		remove = deque->cabeca;
		deque->cabeca = (Pessoa *)deque->cabeca->proximo;
	}
		else
		{
			while(pessoa != NULL && pessoa->proximo !=NULL && pessoa->proximo->id == id)
			{
				remove = pessoa->proximo;
				pessoa->proximo = remove->proximo;
			}
		}
		if(remove)
		{
			free(remove);
		}
	printf("\n");
}

Pessoa* capturar(Deque* deque, int id)
{
	int num;
	Pessoa* aux = malloc(sizeof(Pessoa));
	aux = deque->cabeca;
	Pessoa* temp = NULL;

	do
	{
		if (aux->id == id)
		{
			temp = malloc(sizeof(Pessoa));
			temp = aux;
			break;
		}
		aux = aux->proximo;
	}
	while(aux);

	return temp;
}

void desfazer(Pessoa* pessoa)
{
	if (stackVazia(pessoa->stack))
	{
		printf("Contato nao existe\n");
	}
	else if (pessoa->stack->topo->anterior == NULL)
	{
		printf("Nao ha alteracao para ser feita desfeita.\n");
	}
	else
	{
		Contato* backup = malloc(sizeof(Contato));
		backup = pessoa->stack->topo;
		pessoa->stack->topo = backup->anterior;
		
		free(backup);
		printf("Alteracao desfeita com sucesso.\n");
	}
}


Contato* editarContato() 
{
	Contato* contato = malloc(sizeof(Contato));
	printf("Nome: ");
	contato->nome = malloc(100);
	input(contato->nome, 100);

	printf("Email: ");
	contato->email = malloc(100);
	input(contato->email, 100);

	printf("Numero: ");
	contato->numero = malloc(15);
	input(contato->numero, 15);

	return contato;
}

void retorne(Stack* stack, Contato* contato)
{
	Contato* noPilha = malloc(sizeof(Contato));
	noPilha->nome = contato->nome;
	noPilha->email = contato->email;
	noPilha->numero = contato->numero;
	noPilha->anterior = stack->topo;
	stack->topo = noPilha;
}

int main() 
{
	char email[100], nome[100], telefone[15];
	int id = 0;
	int opcao, num;
	Pessoa* pessoa = NULL;

	Deque* deque = criar();
	while(1)
	{
		if(!dequeVazio(deque))
		{
			opcao = menuPrincipal();
		}
		else
		{
			opcao = menuReduzido();
		}

		lixo();

    switch(opcao)
    {
			case 0 :
				limpar();
				printf("Encerrando o programa.\n");
				return 0;
			break;

			case 1 :
				// Adicionar contato;

				limpar();
				printf("Adicionar novo contato a lista\n");
				printf("Nome: ");
				input(nome, 100);

				printf("Email: ");
				input(email, 100);

				printf("Numero: ");
				input(telefone, 15);
				id++;

				adicionar(deque, email, telefone, nome, id);
				limpar();
				printf("Contato criado com sucesso\n");
			break;

			case 2 :
				// Alterar contato;
				limpar();

				if (dequeVazio(deque))
				{
					printf("Lista vazia.\n");
				}
				else
				{
					printf("\nQual dos seguintes contatos deseja editar?\n");
					percorrer(deque);
					printf("\nID#");
					scanf("%d", &num);
					lixo();

					Pessoa* pessoa = malloc(sizeof(Pessoa));
					pessoa = capturar(deque, num);
					if (pessoa)
					{
						retorne(pessoa->stack, editarContato());
					}
					else
					{
						printf("Contato inexistente.\n");
					}
				}
				break;
			case 3 :
				// Desfazer ultima alteracao do contato;
				limpar();

				if (dequeVazio(deque))
				{
					printf("Lista vazia.\n");
				}
				else
				{
					printf("\nQual dos seguintes contatos deseja desfazer a ultima alteracao?\n");
					percorrer(deque);
					printf("\nID#");
					scanf("%d", &num);
					lixo();
					pessoa = malloc(sizeof(Pessoa));
					pessoa = capturar(deque, num);
					if (pessoa)
					{
						desfazer(pessoa);
					}
					else
					{
						printf("Contato inexistente.\n");
					}
				}
			break;

			case 4 :
				// Remover contato;
				limpar();

				if (dequeVazio(deque))
				{
					printf("Lista vazia.\n");
				}
				else
				{
					printf("\nQual dos seguintes contatos deseja excluir?\n");
					percorrer(deque);
					printf("\nID#");
					scanf("%d", &num);
					lixo();

					Pessoa* pessoa = malloc(sizeof(Pessoa));
					pessoa = capturar(deque, num);
					if (pessoa)
					{
						remover(deque, num);
						limpar();
						printf("Contato removido com sucesso.\n");
					}
					else
					{
						printf("Contato inexistente.\n");
					}
				}
			break;

			case 5:
				// Exibir contatos;
				limpar();

				if (!dequeVazio(deque))
				{
					printf("######### Contatos ############\n");
					percorrer(deque);
				}
				else
				{
					printf("Lista vazia.\n");
				}

			break;

			default :
				printf("Opcao invalida, tente novamente!\n");
			break;
		}
	}
}
