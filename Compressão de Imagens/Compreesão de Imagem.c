#include <stdio.h>
#define N 12
int main()
{

    int i, j;
    int matrizOriginal[N][N * 3], matrizComprimida[N][5] = {{0}};
    int cores[5] = {0};
    int nlin, ncol;
    
    scanf("P3 %d %d 255", &nlin, &ncol);
    getchar();

    for (i = 0; i < nlin; i++){
        for (j = 0; j < ncol * 3; j++){
            scanf("%d", &matrizOriginal[i][j]);
        }
    }

    int num1, num2, num3;

    // contagem de valores consecutivos
    for (i = 0; i < nlin; i++){
        for (j = 0; j < ncol * 3; j += 3){
            num1 = matrizOriginal[i][j];
            num2 = matrizOriginal[i][j + 1];
            num3 = matrizOriginal[i][j + 2];

            if (num1 == 0 && num2 == 0 && num3 == 0){
                matrizComprimida[i][0]++;
            }
            else if (num1 == 255 && num2 == 0 && num3 == 0){
                matrizComprimida[i][1]++;
            }
            else if (num1 == 0 && num2 == 255 && num3 == 0){
                matrizComprimida[i][2]++;
            }
            else if (num1 == 0 && num2 == 0 && num3 == 255){
                matrizComprimida[i][3]++;
            }
            else if (num1 == 255 && num2 == 255 && num3 == 0){
                matrizComprimida[i][4]++;
            }
        }
    }

    for (i = 0; i < nlin; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", matrizComprimida[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 5; i++){
        for (j = 0; j < nlin; j++){
            cores[i] += matrizComprimida[j][i];
        }
    }

    int valor_cor_maj = cores[0];
    int rec_valor_cor_maj = 0; 

    for (i = 1; i < 5; i++){
        if (cores[i] > valor_cor_maj){
            valor_cor_maj = cores[i];
        }
    }

    for (i = 0; i < 5; i++){
        if (cores[i] == valor_cor_maj){
            rec_valor_cor_maj++;
            cores[i] = 1;
        }
        else
            cores[i] = 0;
    }

    if (rec_valor_cor_maj == 1){
        //modificação em caso de nça empate
        for (i = 0; i < nlin; i++){
            for (j = 0; j < ncol * 3; j += 3){
                num1 = matrizOriginal[i][j];
                num2 = matrizOriginal[i][j + 1];
                num3 = matrizOriginal[i][j + 2];

                if (num1 == 0 && num2 == 0 && num3 == 0 && cores[0] == 1){
                    matrizOriginal[i][j] = 0;
                    matrizOriginal[i][j + 1] = 0;
                    matrizOriginal[i][j + 2] = 0;
                }
                
                else if (num1 == 255 && num2 == 0 && num3 == 0 && cores[1] == 1){
                    matrizOriginal[i][j] = 0;
                    matrizOriginal[i][j + 1] = 0;
                    matrizOriginal[i][j + 2] = 0;
                }
                
                else if (num1 == 0 && num2 == 255 && num3 == 0 && cores[2] == 1){
                    matrizOriginal[i][j] = 0;
                    matrizOriginal[i][j + 1] = 0;
                    matrizOriginal[i][j + 2] = 0;
                }
                else if (num1 == 0 && num2 == 0 && num3 == 255 && cores[3] == 1){
                    matrizOriginal[i][j] = 0;
                    matrizOriginal[i][j + 1] = 0;
                    matrizOriginal[i][j + 2] = 0;
                }
                else if (num1 == 255 && num2 == 255 && num3 == 0 && cores[4] == 1){
                    matrizOriginal[i][j] = 0;
                    matrizOriginal[i][j + 1] = 0;
                    matrizOriginal[i][j + 2] = 0;
                }
                else {
                    matrizOriginal[i][j] = 255;
                    matrizOriginal[i][j + 1] = 255;
                    matrizOriginal[i][j + 2] = 255;
                }
            }
        }
    }
    else{
        for (i = 0; i < nlin; i++){
            for (j = 0; j < ncol * 3; j += 3){

                num1 = matrizOriginal[i][j];
                num2 = matrizOriginal[i][j + 1];
                num3 = matrizOriginal[i][j + 2];

                if (num1 == 0 && num2 == 0 && num3 == 0 && cores[0] != 1){
                    matrizOriginal[i][j] = 255;
                    matrizOriginal[i][j + 1] = 255;
                    matrizOriginal[i][j + 2] = 255;
                }
                
                else if (num1 == 255 && num2 == 0 && num3 == 0 && cores[1] != 1){
                    matrizOriginal[i][j] = 255;
                    matrizOriginal[i][j + 1] = 255;
                    matrizOriginal[i][j + 2] = 255;
                }
                
                else if (num1 == 0 && num2 == 255 && num3 == 0 && cores[2] != 1){
                    matrizOriginal[i][j] = 255;
                    matrizOriginal[i][j + 1] = 255;
                    matrizOriginal[i][j + 2] = 255;
                }
                else if (num1 == 0 && num2 == 0 && num3 == 255 && cores[3] != 1){
                    matrizOriginal[i][j] = 255;
                    matrizOriginal[i][j + 1] = 255;
                    matrizOriginal[i][j + 2] = 255;
                }
                else if (num1 == 255 && num2 == 255 && num3 == 0 && cores[4] != 1){
                    matrizOriginal[i][j] = 255;
                    matrizOriginal[i][j + 1] = 255;
                    matrizOriginal[i][j + 2] = 255;
                }
            }
        }
    }

    // Impressão da matriz original modificada
    for (i = 0; i < nlin; i++){
        for (j = 0; j < ncol * 3; j += 3){
            printf("%d %d %d ", matrizOriginal[i][j], matrizOriginal[i][j + 1], matrizOriginal[i][j + 2]);
        }
        printf("\n");
    }
    return 0;
}