#include <iostream>

typedef struct node{
	int valor;
	node *left;
	node *right;
}No;

No* criarNo(int novoValor){
	No *buildNo = new(No);
	buildNo->valor = novoValor;
	buildNo->left = nullptr;
	buildNo->right = nullptr;
	return buildNo;
}

int percorrerAltura(No *raiz){
	int i = 1;
	if (raiz == nullptr)
		return 0;
	if (raiz != nullptr){
		i += percorrerAltura(raiz->left);
		i += percorrerAltura(raiz->right);
	}
	return i;
}

No* rotacionarDireita(No* raiz){
	No* novaRaiz = raiz->left;
	No* auxiliar = novaRaiz->right;

	novaRaiz->right = raiz;
	raiz->left = auxiliar;
	
	return novaRaiz;
}


No* rotacionarEsquerda(No* raiz){
	No* novaRaiz = raiz->right;
	No* auxiliar = novaRaiz->left;

	novaRaiz->left = raiz;
	raiz->right = auxiliar;
	
	return novaRaiz;
}

No* inserir(No *raiz, int valor){
	if (raiz == nullptr)
		return criarNo(valor);
	if (valor < raiz->valor)
		raiz->left = inserir(raiz->left, valor);
	else if (valor > raiz->valor)
		raiz->right = inserir(raiz->right, valor);

	int alturaEsquerda = percorrerAltura(raiz->left);
	int alturaDireita = percorrerAltura(raiz->right);

	int balanco = alturaEsquerda - alturaDireita;
	if (balanco > 1){
		if (valor < raiz->left->valor)
			return rotacionarDireita(raiz);
		else{
			raiz->left = rotacionarEsquerda(raiz->left);
			return rotacionarDireita(raiz);
		}
	}

	if (balanco < -1){
		if (valor >raiz->right->valor)
			return rotacionarEsquerda(raiz);
		else{
			raiz->right = rotacionarDireita(raiz->right);
			return rotacionarEsquerda(raiz);
		}
	}
	return raiz;
}

void emOrdem(No* root) {
    if (root != nullptr) {
        emOrdem(root->left);
        std::cout << root->valor << " ";
        emOrdem(root->right);
    }
}

int main() {
    No* root = nullptr;
    root = inserir(root, 50);
    root = inserir(root, 30);
    root = inserir(root, 20);
    root = inserir(root, 40);
    root = inserir(root, 70);
    root = inserir(root, 60);
    root = inserir(root, 80);
    std::cout << "Em ordem essa bagaça fica assim: ";
    emOrdem(root);
    return 0;
}
