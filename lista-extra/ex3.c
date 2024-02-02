    #include <stdio.h>
     
    // Função para verificar se um número é primo
    int ehPrimo(int num) {
        int i;
        if (num <= 1) {
            return 0; // Números menores ou iguais a 1 não são primos
        }
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return 0; // Números divisíveis por outros além de 1 e ele mesmo não são primos
            }
        }
        return 1; // Se passou pelos testes, é primo
    }
     
    int main() {
        // Entrada de dados
        int x, y;
        int i;
        scanf("%d %d", &x, &y);
     
        // Contagem de números primos no intervalo
        int quantidadePrimos = 0;
        for (i = x; i <= y; i++) {
            if (ehPrimo(i)) {
                quantidadePrimos++;
            }
        }
     
        // Saída de resultados
        printf("%d\n", quantidadePrimos);
     
        return 0;
    }