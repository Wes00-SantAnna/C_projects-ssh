#include <stdio.h>

// Função para calcular fatorial
int fatorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função para contar dígitos
int contar_digitos(int n) {
    if (n == 0) return 1;
    int cont = 0;
    while (n != 0) {
        cont++;
        n /= 10;
    }
    return cont;
}

// Função para converter de TMTL para decimal
int tmtl_para_decimal(int numero) {
    int resultado = 0;
    int i = 1;

    while (numero > 0) {
        int digito = numero % 10;
        resultado += digito * fatorial(i);
        numero /= 10;
        i++;
    }

    return resultado;
}

int main() {
    
    int entrada;

    while (1) {
        scanf("%d", &entrada);
        if (entrada == -1) 
            break;
        printf("%d\n", tmtl_para_decimal(entrada));
    }

    return 0;
}