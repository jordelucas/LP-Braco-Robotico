#include "superficie.h"

struct braco {
    braco();

    bool escrever;
    int posicao_atual;
    
    void subir ();
    int abaixar ();
    void mover_baixo (superficie &superficie, int qtd_posicoes);
    void mover_cima (superficie &superficie, int qtd_posicoes);
    void mover_direita (superficie &superficie, int qtd_posicoes);
    void mover_esquerda (superficie &superficie, int qtd_posicoes);
};