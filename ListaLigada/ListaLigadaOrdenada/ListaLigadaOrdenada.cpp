#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;


// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL) //verifica se tem espaço na memória
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* encontrado = posicaoElemento(novo->valor);
	if (encontrado) {
		cout << "Nao e permitido a insercao de valores repetidos na lista.\nTente novamente: \n\n";
		inserirElemento();
	}
	
	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		NO* valoresSeguintes;
		NO* aux = primeiro;

		if (novo->valor < primeiro->valor) {
			valoresSeguintes = novo;
			valoresSeguintes->prox = aux;
			aux = NULL;
			aux = valoresSeguintes;

			//return;
		}
		else {
			// procura o final da lista
			while (aux->prox != NULL) {
				if (novo->valor < aux->prox->valor) {
					valoresSeguintes = aux->prox;
					novo->prox = valoresSeguintes;
					aux->prox = novo;
					return;
				}
				aux = aux->prox;
			}
			aux->prox = novo;
			ultimo = novo;
		}
	}	
}

void excluirElemento()
{

}


void buscarElemento()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	if (valor < primeiro->valor || valor > ultimo->valor) {
		cout << "Valor nao incluso na lista\n\n\n";
		return;
	}
	else {
		NO* elementoExistente = posicaoElemento(valor);
		if (elementoExistente) {
			cout << "ENCONTRADO\n\n";
		}
		else {
			cout << "ELEMENTO NAO ENCONTRADO\n\n";
		}
	}
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}



