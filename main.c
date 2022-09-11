#include <stdio.h>
#include <locale.h>

//cria o jogo
void preencher_jogo(char jogo[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            jogo[i][j] = '~';
        }
    }
}

//imprime o jogo na tela
void mostrar_jogo(char jogo[3][3]){
    printf("      JOGO\n");
    printf("      0   1   2\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d ->", i);
        for (int j = 0; j < 3; ++j) {
            printf(" [%c]", jogo[i][j]);
        }
        printf("\n");
    }
}

//checa se naquela posição da matriz é possível colocar um caractere
int checa_espaco_vazio(char jogo[3][3], int linha, int coluna) {
    if (jogo[linha][coluna] == '~')
        return 1;
    return 0;
}

// checa se o jogo está empatado, se estiver retorna 1 se não estiver retorna 0
int checa_empate(char jogo[3][3]){
    int cont = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (jogo[i][j] != '~'){
                cont++;
            }
        }
    }
    if(cont == 9)
        return 1;
    return 0;
}

//retorna 1 se o jogador tiver ganho e 0 se não
int checa_vitoria(char jogo[3][3]){
    for (int x = 0; x < 3; ++x) {
        if (jogo[x][0] == 'X' && jogo[x][1] == 'X' && jogo[x][2] == 'X') {
            printf("\nJOGADOR 1 VENCEU !!!!");
            return 1;
        }
        if (jogo[x][0] == 'O' && jogo[x][1] == 'O' && jogo[x][2] == 'O') {
            printf("\nJOGADOR 2 VENCEU !!!!");
            return 1;
        }
        if (jogo[0][x] == 'X' && jogo[1][x] == 'X' && jogo[2][x] == 'X') {
            printf("\nJOGADOR 1 VENCEU !!!!");
            return 1;
        }
        if (jogo[0][x] == 'O' && jogo[1][x] == 'O' && jogo[2][x] == 'O') {
            printf("\nJOGADOR 2 VENCEU !!!!");
            return 1;
        }}
    if (jogo[3][3] == 'X' && jogo[2][2] == 'X' && jogo[1][1] == 'X') {
        printf("\nJOGADOR 1 VENCEU !!!!");
        return 1;
    }
    if (jogo[3][3] == 'O' && jogo[2][2] == 'O' && jogo[1][1] == 'O') {
        printf("\nJOGADOR 2 VENCEU !!!!");
        return 1;
    }
    if (jogo[1][1] == 'X' && jogo[2][2] == 'X' && jogo[3][3] == 'X') {
        printf("\nJOGADOR 1 VENCEU !!!!");
        return 1;
    }
    if (jogo[1][1] == 'O' && jogo[2][2] == 'O' && jogo[3][3] == 'O') {
        printf("\nJOGADOR 2 VENCEU !!!!");
        return 1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char jogo[3][3];

    printf("JOGO DA VELHA\nX -> PLAYER 1\nO -> PLAYER 2\n\n");
    preencher_jogo(jogo);

    while(1){
        int linha=0, coluna=0;
        if(checa_empate(jogo) || checa_vitoria(jogo))
            break;
        mostrar_jogo(jogo);
        printf("\nVEZ DO JOGADOR 1");
        printf("\nFACA SUA JOGADA\n");
        printf("\nLINHA -> ");
        scanf("%d", &linha);
        printf("COLUNA -> ");
        scanf("%d", &coluna);
        if (checa_espaco_vazio(jogo, linha, coluna) == 1){
            printf("X ADICIONADO NA LINHA %d COLUNA %d", linha, coluna);
            jogo[linha][coluna] = 'X';
        }
        else
            while (1){
                printf("\nJÁ EXISTE X OU O NA LINHA %d COLUNA %d, DIGITE NOVAMENTE", linha, coluna);
                printf("\nLINHA -> ");
                scanf("%d", &linha);
                printf("COLUNA -> ");
                scanf("%d", &coluna);
                if (checa_espaco_vazio(jogo, linha, coluna)){
                    printf("X ADICIONADO NA LINHA %d COLUNA %d", linha, coluna);
                    jogo[linha][coluna] = 'X';
                    break;
                }
            }
        printf("\n");

        mostrar_jogo(jogo);
        if(checa_vitoria(jogo) || checa_empate(jogo))
            break;
        printf("\nVEZ DO JOGADOR 2");
        printf("\nFACA SUA JOGADA");
        printf("\nLINHA -> ");
        scanf("%d", &linha);
        printf("COLUNA -> ");
        scanf("%d", &coluna);
        if (checa_espaco_vazio(jogo, linha, coluna) == 1){
            printf("O ADICIONADO NA LINHA %d COLUNA %d", linha, coluna);
            jogo[linha][coluna] = 'O';
        }
        else
            while (1){
                printf("\nJÁ EXISTE X OU O NA LINHA %d COLUNA %d, DIGITE NOVAMENTE", linha, coluna);
                printf("\nLINHA -> ");
                scanf("%d", &linha);
                printf("COLUNA -> ");
                scanf("%d", &coluna);
                if (checa_espaco_vazio(jogo, linha, coluna)){
                    printf("O ADICIONADO NA LINHA %d COLUNA %d", linha, coluna);
                    jogo[linha][coluna] = 'O';
                    break;
                }
            }
        printf("\n");
    }
    printf("\nFIM DE JOGO");

    return 0;
}