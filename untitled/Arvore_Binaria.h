#ifndef UNTITLED_ARVORE_BINARIA_H
#define UNTITLED_ARVORE_BINARIA_H

struct Usuario {
    char login[10];
    char senha[10];
    char nome[30];
};

// Estrutura que representa um nó da árvore binária
struct Node {
    struct Usuario usuario;
    struct Node *esquerda;
    struct Node *direita;
};

struct Node *criarNo(struct Usuario usuario);
struct Node *inserir(struct Node *raiz, struct Usuario usuario);
void verificarCredenciais(struct Node *raiz, char login[], char senha[]);
void liberarArvore(struct Node *raiz);


#endif
