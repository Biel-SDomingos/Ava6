#include "Arvore_Binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para criar um novo nó da árvore com um usuário
struct Node *criarNo(struct Usuario usuario) {
    // Aloca memória para o novo nó
    struct Node *novoNo = (struct Node *)malloc(sizeof(struct Node));

    novoNo->usuario = usuario;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

// Função para inserir um usuário na árvore
struct Node *inserir(struct Node *raiz, struct Usuario usuario) {

    if (raiz == NULL) {
        return criarNo(usuario);
    }

    // Compara o login do usuário com o login do nó atual
    if (strcmp(usuario.login, raiz->usuario.login) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, usuario);
    } else if (strcmp(usuario.login, raiz->usuario.login) > 0) {
        raiz->direita = inserir(raiz->direita, usuario);
    }

    return raiz;
}

// Função para verificar as credenciais (login e senha) na árvore
void verificarCredenciais(struct Node *raiz, char login[], char senha[]) {

    if (raiz == NULL) {
        printf("Credenciais invalidas!\n");
        return;
    }

    // Compara o login e a senha com o nó atual
    int cmpLogin = strcmp(login, raiz->usuario.login);
    int cmpSenha = strcmp(senha, raiz->usuario.senha);

    if (cmpLogin == 0) {
        if (cmpSenha == 0) {
            printf("Saudacoes, %s!\n", raiz->usuario.nome);
        } else {
            printf("Senha inválida!\n");
        }
        return;
    }

    if (cmpLogin < 0) {
        verificarCredenciais(raiz->esquerda, login, senha);
    } else {
        verificarCredenciais(raiz->direita, login, senha);
    }
}

// Função para liberar a memória alocada para a árvore
void liberarArvore(struct Node *raiz) {

    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);

        free(raiz);
    }
}
