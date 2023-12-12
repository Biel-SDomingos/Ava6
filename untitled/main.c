#include "Arvore_Binaria.h"
#include <stdio.h>

int main() {
    struct Usuario usuarios[500];
    struct Node *raiz = NULL;
    FILE *Arq;
    char login[10];
    char senha[10];

    Arq = fopen("../database.dat", "rb");
    if (Arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    fread(usuarios, sizeof(struct Usuario), 500, Arq);
    for (int i = 0; i < 500; i++) {
        raiz = inserir(raiz, usuarios[i]);
    }
    fclose(Arq);

    printf("Digite o login: ");
    scanf("%s", login);

    printf("Digite a senha: ");
    scanf("%s", senha);

    verificarCredenciais(raiz, login, senha);

    liberarArvore(raiz);

    return 0;
}
