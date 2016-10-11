
#include <stdlib.h>
#include <stdio.h>

int main() {

    int tamanhoTabuleiro, quantidadePedras;
    int x, y, tempMath, cTemp, lTemp;
    int play, turnos, jogadaSucesso;


    do {
        printf("Qual é tamnho do tabuleiro ?\n");
        scanf("%i", &tamanhoTabuleiro);
            
         // verificando se o tabuleiro é maior que dois e menor que 500
        if (!(tamanhoTabuleiro >= 2 && tamanhoTabuleiro <= 500)) {


            printf("O tabuleiro deve ser maior ou igual a 2 e menor ou igual a 500 \n");

        }
     // caso não seja repedir o loop
    } while (!(tamanhoTabuleiro >= 2 && tamanhoTabuleiro <= 500));



    do {
        printf("Com quantas pedras você quer jogar ?\n");
        scanf("%i", &quantidadePedras);


        if (!(quantidadePedras >= 1 && tamanhoTabuleiro <= 250)) {


            printf("As pedras deve ser maior ou igual a 1 e menor ou igual a 500 \n");

        }


        tempMath = ((tamanhoTabuleiro * tamanhoTabuleiro) / 2);

        if (!(quantidadePedras <= tempMath)) {
            printf(" As pedras tem que ser menor que %d \n", tempMath);

        }

    } while (!(quantidadePedras >= 1 && tamanhoTabuleiro <= 250));



    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    turnos = quantidadePedras * 2;
    play = 1;

    printf("=======================================================\n");

    /// Imprimendo o tabuleiro pela primeira vez
    for (x = 0; x < tamanhoTabuleiro; x++) {


        for (y = 0; y < tamanhoTabuleiro; y++) {
            tabuleiro[x][y] = 0;
            printf(" %d |", tabuleiro[x][y]);
            
        }
        printf("\n");


    }

    printf("=======================================================\n");

    while (turnos > 0) {



        printf("Jogador %i é sua vez \n", play);
        printf("Qual coluna deseja colocar a pedra \n");
        scanf("%i", &cTemp);
        printf("Qual linha deseja colocar a pedra \n");
        scanf("%i", &lTemp);


        cTemp -= 1;
        lTemp -= 1;

       
        if ((0 > cTemp || cTemp > tamanhoTabuleiro) || (0 > lTemp || lTemp > tamanhoTabuleiro)) {

            printf("Ops local invalido! \n");
            jogadaSucesso = 0;

        } else {

            if (tabuleiro[lTemp][cTemp]) {

                printf("Ops local já está o cupado por uma peça\n");
                jogadaSucesso = 0;


            } else {

                tabuleiro[lTemp][cTemp] = play == 1 ? 1 : 2;
                jogadaSucesso = 1;

            }

        }

        if (jogadaSucesso) {
            // passando para outro jogador;
            play = play == 1 ? 2 : 1;
            // dimindo a quantidade de turnos
            turnos -= 1;

            /// Imprimendo o tabuleiro
            printf("====================================================\n");
             for (x = 0; x < tamanhoTabuleiro; x++) {


                for (y = 0; y < tamanhoTabuleiro; y++) {

                    printf(" %d |", tabuleiro[x][y]);

                }
                printf("\n");


            }
            printf("======================= Faltam %d turnos ================================\n", turnos);


        }
    }

    return 0;
}

