#include<stdio.h>

int main(){
    // Inicialização das variáveis 
    int jogadores[4], carta, pontuacoes[4] = {0,0,0,0}, caso[4][2], pontuacao = 0, maior, menor;
    char naipe, vencedor, perdedor;

    do{
        // As linhas se referem aos 4 jogadores
        for(int i=0; i<4; i++ ){
            // Coluna 0 se refere a verificação se o jogador possui a carta 12-E
            // Coluna 1 se refere à soma da quantidade de cartas de Copas que o jogador possui 
            for (int j=0; j<2; j++){
                // Faz a inicialização de todas as linhas e colunas da matriz
                caso[i][j]=0;
            }
        }

        // Entrada da quantidade de cartas que cada jogador possui
        scanf("%d %d %d %d", &jogadores[0], &jogadores[1], &jogadores[2], &jogadores[3]);

        // Passar por todos os jogadores que compõem o array
        for(int y=0; y<4; y++){
            pontuacao = 0;
            // Passar pela quantidade de cartas que o jogador[y] possui
            for(int x=0; x<jogadores[y]; x++){

                // Leitura x cartas do jogador[y]
                scanf("%d-%c", &carta, &naipe);
                getchar();

                // Verificação das cartas para a somatória de pontos
                if(carta == 12 && naipe == 'E'){
                    // Se o jogador possuir 12-E, recebe 13 pontos 
                    pontuacao+=13;
                    // Retorna ao vetor de verificação que o jogador[y] possui a carta 12-E 
                    caso[y][0]=1;
                }
                // Verificação se o jogador possui quaisquer carta de Copas
                else if(naipe == 'C'){
                    // Somatória de 1 ponto caso possua a carta de Copas
                    pontuacao++;
                    // Somatória da quantidade de cartas de Copas que o jogador possui 
                    caso[y][1]++;
                }
            }
            // Verificação de o jogador y entra nas condições do caso
            if(caso[y][0]==1 && caso[y][1]==13){
                // Adiciona 13 pontos aos demais jogadores
                for(int p=0; p<4; p++){
                    if(pontuacoes[p]!=pontuacoes[y]){
                        pontuacoes[p]+=26;
                    }
                }
            // Caso o jogador não entre no caso, ele recebe as pontuações da partida
            }else{
                pontuacoes[y]+=pontuacao;
            }
        }
        // Apresenta as pontuações dos jogadores naquela rodada
        printf("A: %d B: %d C: %d D: %d\n", pontuacoes[0], pontuacoes[1], pontuacoes[2], pontuacoes[3]);
    // Continua o laço de repetição (jogadas) até um dos jogadores atingir 100 pontos ou mais 
    }while(pontuacoes[0] <= 100 && pontuacoes[1] <= 100 && pontuacoes[2] <= 100 && pontuacoes[3] <= 100);

    maior = pontuacoes[0];
    perdedor = 65;
    for(int x=1; x<4; x++){
        if(pontuacoes[x] > maior){
            maior = pontuacoes[x];
            perdedor = x+65;
        }
    }

    menor = pontuacoes[0];
    vencedor = 65;
    for(int x=1; x<4; x++){
        if(pontuacoes[x] < menor){
            menor = pontuacoes[x];
            vencedor = x+65;
        }
    }

    // Exibe o resultado do jogo
    printf("Vencedor: jogador %c; Ultimo lugar: jogador %c\n", vencedor, perdedor);
    
    return 0;
}