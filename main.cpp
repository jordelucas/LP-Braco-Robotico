#include <iostream>
#include <fstream>

#include "braco.h"

int main() {
    int L, A, qtd_comandos, qtd_posicoes = 0;
    char comando;

    std::ofstream arq;
    std::ifstream arq_in;

    braco braco;

    arq_in.open("exemplo8.txt");

    arq_in >> L;
    arq_in >> A;
        
    superficie superficie(A, L);
    
    arq_in >> qtd_comandos;
    
    while (qtd_comandos > 0) {
        arq_in >> comando;
        
        switch (comando) {
            case 's':
                braco.subir();
                break;
            case 'a':
                superficie.posicoes[braco.posicao_atual] = braco.abaixar();    
                break;
            case 'b':
                arq_in >> qtd_posicoes;
                braco.mover_baixo(superficie, qtd_posicoes);
                break;
            case 'c':
                arq_in >> qtd_posicoes;
                braco.mover_cima(superficie, qtd_posicoes);
                break;
            case 'd':
                arq_in >> qtd_posicoes;
                braco.mover_direita(superficie, qtd_posicoes);
                break;     
            case 'e':
                arq_in >> qtd_posicoes;
                braco.mover_esquerda(superficie, qtd_posicoes);
                break;           
            default:
                std::cout << "Opção inválida!\n";
                break;
        }
        qtd_comandos--;
    }

    arq_in.close();
    
    arq.open("arquivo.bpm");


    std::cout << A << "\n";
    std::cout << L << "\n";
    std::cout << comando << "\n";

    arq << "P1\n";
    arq << "# Jordevá Lucas Santos da Silva\n";
    arq << superficie.Largura << "\t" << superficie.Altura << "\n";

    for (int i = 1; i <= superficie.getTamanho(); i++) {
        arq << superficie.posicoes[i-1] << "\n";
    }

    arq.close();
    /*
    superficie.~superficie();
    */
    return 0;
}