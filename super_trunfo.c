#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    int ataque;
    int defesa;
    int magia;
} Carta;

void mostrarCarta(Carta c) {
    printf("\nCarta: %s\n", c.nome);
    printf("Ataque: %d\n", c.ataque);
    printf("Defesa: %d\n", c.defesa);
    printf("Magia: %d\n", c.magia);
}

int main() {
    Carta cartas[5] = {
        {"Dragao", 90, 70, 50},
        {"Mago", 60, 50, 95},
        {"Guerreiro", 80, 85, 40},
        {"Elfo", 70, 60, 80},
        {"Goblin", 50, 40, 30}
    };

    int escolha, jogadorPontos = 0, oponentePontos = 0;
    srand(time(NULL)); // inicializa a aleatoriedade

    char jogarNovamente;
    do {
        int idxJogador = rand() % 5;
        int idxOponente;
        do {
            idxOponente = rand() % 5;
        } while (idxOponente == idxJogador); // garante cartas diferentes

        Carta jogador = cartas[idxJogador];
        Carta oponente = cartas[idxOponente];

        printf("\nBem-vindo ao Super Trunfo!\n");
        printf("Sua carta:\n");
        mostrarCarta(jogador);

        printf("\nEscolha o atributo para competir:\n");
        printf("1 - Ataque\n2 - Defesa\n3 - Magia\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);

        printf("\nCarta do oponente:");
        mostrarCarta(oponente);

        printf("\nResultado:\n");
        switch (escolha) {
            case 1:
                if(jogador.ataque > oponente.ataque) {
                    printf("Você venceu!\n");
                    jogadorPontos++;
                } else if(jogador.ataque < oponente.ataque) {
                    printf("O oponente venceu!\n");
                    oponentePontos++;
                } else printf("Empate!\n");
                break;
            case 2:
                if(jogador.defesa > oponente.defesa) {
                    printf("Você venceu!\n");
                    jogadorPontos++;
                } else if(jogador.defesa < oponente.defesa) {
                    printf("O oponente venceu!\n");
                    oponentePontos++;
                } else printf("Empate!\n");
                break;
            case 3:
                if(jogador.magia > oponente.magia) {
                    printf("Você venceu!\n");
                    jogadorPontos++;
                } else if(jogador.magia < oponente.magia) {
                    printf("O oponente venceu!\n");
                    oponentePontos++;
                } else printf("Empate!\n");
                break;
            default:
                printf("Escolha inválida!\n");
        }

        printf("\nPlacar: Você %d x %d Oponente\n", jogadorPontos, oponentePontos);
        printf("\nQuer jogar outra rodada? (s/n): ");
        scanf(" %c", &jogarNovamente);

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nObrigado por jogar! Placar final: Você %d x %d Oponente\n", jogadorPontos, oponentePontos);
    return 0;
}
