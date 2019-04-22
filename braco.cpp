#include <iostream>

#include "braco.h"

braco::braco () {
    escrever = false;
    posicao_atual = 0;
}

void braco::subir () {
    escrever = false;
}

int braco::abaixar () {
    escrever = true;
    return 1;
}

void braco::mover_baixo (superficie &superficie, int qtd_posicoes) {
    for (int i = posicao_atual; i <= superficie.getTamanho() -1 && qtd_posicoes >= 0; i+=superficie.Largura) {
        if (escrever) {
            superficie.posicoes[i] = 1;
        }
        posicao_atual = i;
        qtd_posicoes--;
    }
}

void braco::mover_cima (superficie &superficie, int qtd_posicoes) {
    for (int i = posicao_atual; i >= 0 && qtd_posicoes >= 0; i-=superficie.Largura) {
        if (escrever) {
            superficie.posicoes[i] = 1;
        }
        posicao_atual = i;
        qtd_posicoes--;
    }
}

void braco::mover_direita (superficie &superficie, int qtd_posicoes) {
    for (int i = posicao_atual+1; i % superficie.Largura != 0 && qtd_posicoes > 0; i++) {
        if (escrever) {
            superficie.posicoes[i] = 1;
        }
        posicao_atual = i;
        qtd_posicoes--;
    }
}

void braco::mover_esquerda (superficie &superficie, int qtd_posicoes) {
    for (int i = posicao_atual-1; posicao_atual != 0 && (i % superficie.Largura != (superficie.Largura-1)) && qtd_posicoes > 0; i--) {
        if (escrever) {
            superficie.posicoes[i] = 1;
        }
        posicao_atual = i;
        qtd_posicoes--;
    }
}