#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_CARACTERES 9040
#define MAX_PARAGRAFOS 10
#define MAX_QUESTOES 13
#define MAX_PALAVRAS 70
#define MAX_CARACTERES_PALAVRA 50

char texto[MAX_CARACTERES];
char frase_longa[MAX_CARACTERES];
char frase_curta[MAX_CARACTERES];
int qtd_paragrafos;
int tam_palavras_positivas, tam_palavras_negativas;
char palavras_positivas[MAX_PALAVRAS][MAX_CARACTERES_PALAVRA];
char palavras_negativas[MAX_PALAVRAS][MAX_CARACTERES_PALAVRA];


void converter_minusculo(char paragrafo[MAX_PARAGRAFOS][MAX_CARACTERES], char mini_texto[MAX_PARAGRAFOS][MAX_CARACTERES]){
    for (int i = 0; i < MAX_PARAGRAFOS; i++) {
        int j = 0;
        while (paragrafo[i][j] != '\0' && paragrafo[i][j] != '\n' && j < MAX_CARACTERES - 1) {
            mini_texto[i][j] = tolower(paragrafo[i][j]);
            j++;
        }
    }
}

int separar_palavras(char texto[MAX_CARACTERES], char palavras[MAX_PALAVRAS][MAX_CARACTERES_PALAVRA]){
    int qtd_palavras = 0, j = 0, k = 0;

    while(texto[k] != '\0' && qtd_palavras < MAX_PALAVRAS){
        if(texto[k] == ' ' || texto[k] == '\n'){
            palavras[qtd_palavras][j] = '\0';
            qtd_palavras++;
            j = 0;
        } else {
            palavras[qtd_palavras][j] = texto[k];
            j++;
        }
        k++;
    }

    return qtd_palavras;
}


void encontrar_frase_longa(char paragrafo[MAX_PARAGRAFOS][MAX_CARACTERES]) {
    int x = 0;
    int maior = -1;
    char aux_frase[MAX_CARACTERES] = {0};

    frase_longa[0] = '\0';

    for(int i = 0; i < qtd_paragrafos; i++) {
        for(int j = 0; j < MAX_CARACTERES; j++) {
            if(paragrafo[i][j] == '\n' || paragrafo[i][j] == '\0') {
                break;
            } else {
                if(paragrafo[i][j] != '.') {
                    aux_frase[x] = paragrafo[i][j];
                    x++;
                } else {
                    aux_frase[x] = '\0';
                    
                    if(x > maior) {
                        maior = x;
                        strcpy(frase_longa, aux_frase);
                    }

                    x = 0;
                    aux_frase[0] = '\0';
                }
            }
        }
    }
}

void encontrar_frase_curta(char paragrafo[MAX_PARAGRAFOS][MAX_CARACTERES]) {
    int menor = MAX_CARACTERES + 1, qtd_palavras = 0;
    char aux_frase[MAX_CARACTERES] = {0};
    
    for(int i = 0; i < MAX_PARAGRAFOS; i++) {
        if(paragrafo[i][0] == '\0') {
            break;
        }
        
        int x = 0;
        for(int j = 0; j < MAX_CARACTERES; j++) {
            if(paragrafo[i][j] == '\0') {
                break;
            }

            aux_frase[x] = paragrafo[i][j];
            x++;
            
            if (isspace(paragrafo[i][j])) {
                qtd_palavras++;
            }

            if (paragrafo[i][j] == '.') {
                aux_frase[x - 1] = '\0';
                qtd_palavras++;
                j++;
                
                if(qtd_palavras < menor) {
                    strcpy(frase_curta, aux_frase);
                    menor = qtd_palavras;
                }

                x = 0;
                qtd_palavras = 0;
                memset(aux_frase, 0, sizeof(aux_frase));
            }
        }
    }
}

void contar_texto(int *qtd_frases_positivas, int *qtd_frases_negativas, int *polaridade, char paragrafo[MAX_PARAGRAFOS][MAX_CARACTERES]){
    *qtd_frases_positivas = 0;
    *qtd_frases_negativas = 0;

    char caracteres_especiais[] = " .,;:!?";
    caracteres_especiais[strlen(caracteres_especiais)] = '\0';

    for(int i = 0; i < qtd_paragrafos; i++){
        char temp_paragrafo[MAX_CARACTERES];
        strcpy(temp_paragrafo, paragrafo[i]);

        char *token = strtok(temp_paragrafo, caracteres_especiais);
        while(token != NULL){
            for(int aux = 0; aux < tam_palavras_positivas; aux++){
                if(strcmp(token, palavras_positivas[aux]) == 0){
                    (*qtd_frases_positivas)++;
                }
            }
            for(int aux = 0; aux < tam_palavras_negativas; aux++){
                if(strcmp(token, palavras_negativas[aux]) == 0){
                    (*qtd_frases_negativas)++;
                }
            }
            token = strtok(NULL, caracteres_especiais);
        }
    }

    if(((*qtd_frases_positivas - *qtd_frases_negativas) > 3) || ((*qtd_frases_positivas > 0) && (*qtd_frases_negativas == 0))){
        *polaridade = 1;
    } else if(((*qtd_frases_negativas - *qtd_frases_positivas) > 3) || (*qtd_frases_positivas == 0 && *qtd_frases_negativas > 0)){
        *polaridade = -1;
    } else if((*qtd_frases_positivas > 0) && (*qtd_frases_negativas > 0) && (abs(*qtd_frases_positivas - *qtd_frases_negativas) <= 3)){
        *polaridade = 0;
    } else {
        *polaridade = 0;
    }

    if(*polaridade == 1){
        printf("%d Palavras positivas, %d Palavras negativas: Polaridade positiva\n", *qtd_frases_positivas, *qtd_frases_negativas);
    } else if(*polaridade == -1){
        printf("%d Palavras positivas, %d Palavras negativas: Polaridade negativa\n", *qtd_frases_positivas, *qtd_frases_negativas);
    } else if(*polaridade == 0){
        printf("%d Palavras positivas, %d Palavras negativas: Polaridade neutra\n", *qtd_frases_positivas, *qtd_frases_negativas);
    }
}

void contar_frase(int *qtd_frases_positivas, int *qtd_frases_negativas, int *polaridade, char frase[MAX_CARACTERES]){
    *qtd_frases_positivas = 0;
    *qtd_frases_negativas = 0;

    char caracteres_especiais[] = " .,;:!?";
    caracteres_especiais[strlen(caracteres_especiais)] = '\0';

    char temp_frase[MAX_CARACTERES];
    strcpy(temp_frase, frase);

    char *token = strtok(temp_frase, caracteres_especiais);
    while(token != NULL){
        for(int aux = 0; aux < tam_palavras_positivas; aux++){
            if(strcmp(token, palavras_positivas[aux]) == 0){
                (*qtd_frases_positivas)++;
            }
        }
        for(int aux = 0; aux < tam_palavras_negativas; aux++){
            if(strcmp(token, palavras_negativas[aux]) == 0){
                (*qtd_frases_negativas)++;
            }
        }
        token = strtok(NULL, caracteres_especiais);
    }

    if(((*qtd_frases_positivas - *qtd_frases_negativas) > 3) || ((*qtd_frases_positivas > 0) && (*qtd_frases_negativas == 0))){
        *polaridade = 1;
    } else if(((*qtd_frases_negativas - *qtd_frases_positivas) > 3) || (*qtd_frases_positivas == 0 && *qtd_frases_negativas > 0)){
        *polaridade = -1;
    } else if((*qtd_frases_positivas > 0) && (*qtd_frases_negativas > 0) && (abs(*qtd_frases_positivas - *qtd_frases_negativas) <= 3)){
        *polaridade = 0;
    } else {
        *polaridade = 0;
    }

    if(*polaridade == 1){
        printf("%d Palavras positivas, %d Palavras negativas: Polaridade positiva\n", *qtd_frases_positivas, *qtd_frases_negativas);
    } else if(*polaridade == -1){
        printf("%d Palavras positivas, %d Palavras negativas: Polaridade negativa\n", *qtd_frases_positivas, *qtd_frases_negativas);
    } else if(*polaridade == 0){
        printf("%d Palavras positivas, %d Palavras negativas: Polaridade neutra\n", *qtd_frases_positivas, *qtd_frases_negativas);
    }
}

int main(){
    char paragrafo[MAX_PARAGRAFOS][MAX_CARACTERES];
    char paragrafo_minusculo[MAX_PARAGRAFOS][MAX_CARACTERES];
    int qtd_questoes;
    int questoes[MAX_QUESTOES] = {0};
    int paragrafo_questao2[MAX_QUESTOES] = {0};
    int qtd_positivas, qtd_negativas, polaridade;

    scanf("%d", &qtd_paragrafos);
    getchar();

    if(qtd_paragrafos <= MAX_PARAGRAFOS){
        for(int i = 0; i < qtd_paragrafos; i++){
            fgets(paragrafo[i], MAX_CARACTERES, stdin);
        }
    }

    fgets(texto, MAX_CARACTERES, stdin);
    tam_palavras_positivas = separar_palavras(texto, palavras_positivas);

    fgets(texto, MAX_CARACTERES, stdin);
    tam_palavras_negativas = separar_palavras(texto, palavras_negativas);

    scanf("%d", &qtd_questoes);
    getchar();

    for(int i = 0; i < qtd_questoes; i++){
        scanf("%d", &questoes[i]);
        getchar();
        if(questoes[i] == 2){
            scanf("%d", &paragrafo_questao2[i]);
            getchar();
        } 
    }

    converter_minusculo(paragrafo, paragrafo_minusculo);
    encontrar_frase_curta(paragrafo_minusculo);
    encontrar_frase_longa(paragrafo_minusculo);
    
    printf("curta: %s\n", frase_curta);
    printf("longa: %s\n", frase_longa);

    for(int i = 0; i < qtd_questoes; i++){
        switch (questoes[i]){
        case 1:
            contar_texto(&qtd_positivas, &qtd_negativas, &polaridade, paragrafo_minusculo);
            break;
        case 2:
            contar_frase(&qtd_positivas, &qtd_negativas, &polaridade, paragrafo_minusculo[paragrafo_questao2[i]]);
            break;
        case 3:
            contar_frase(&qtd_positivas, &qtd_negativas, &polaridade, frase_longa);
            break;
        case 4:
            contar_frase(&qtd_positivas, &qtd_negativas, &polaridade, frase_curta);
            break;
        default:
            break;
        }
    }

    return 0;
}