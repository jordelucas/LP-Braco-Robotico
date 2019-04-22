#include "superficie.h"

superficie::superficie(int alt, int larg) {
    Altura = alt;
    Largura = larg;
    posicoes = new int[alt*larg];
}
/*
superficie::~superficie() {
    delete[] posicoes;
}
*/  
int superficie::getTamanho () {
    return Altura * Largura;
}
