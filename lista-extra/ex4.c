#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define SUCESSO 1
#define FALHA -1

typedef struct {
    int elementos[MAX];
    int inicio;
    int fim;
} Deque;

int criarDeque(Deque *d) {
    d->inicio = -1;
    d->fim = -1;
    return SUCESSO;
}

int estaVazio(Deque *d) {
    return d->inicio == -1 && d->fim == -1;
}

int estaCheio(Deque *d) {
    return (d->fim + 1) % MAX == d->inicio;
}

int pushEsquerda(Deque *d, int elem) {
    if (estaCheio(d)) {
        return FALHA;
    }

    if (estaVazio(d)) {
        d->inicio = 0;
        d->fim = 0;
    } else {
        d->inicio = (d->inicio - 1 + MAX) % MAX;
    }

    d->elementos[d->inicio] = elem;

    return SUCESSO;
}

int pushDireita(Deque *d, int elem) {
    if (estaCheio(d)) {
        return FALHA;
    }

    if (estaVazio(d)) {
        d->inicio = 0;
        d->fim = 0;
    } else {
        d->fim = (d->fim + 1) % MAX;
    }

    d->elementos[d->fim] = elem;

    return SUCESSO;
}

int popEsquerda(Deque *d) {
    if (estaVazio(d)) {
        return FALHA;
    }

    int elem = d->elementos[d->inicio];

    if (d->inicio == d->fim) {
        // O deque ficou vazio após a remoção
        d->inicio = -1;
        d->fim = -1;
    } else {
        d->inicio = (d->inicio + 1) % MAX;
    }

    return elem;
}

int popDireita(Deque *d) {
    if (estaVazio(d)) {
        return FALHA;
    }

    int elem = d->elementos[d->fim];

    if (d->inicio == d->fim) {
        // O deque ficou vazio após a remoção
        d->inicio = -1;
        d->fim = -1;
    } else {
        d->fim = (d->fim - 1 + MAX) % MAX;
    }

    return elem;
}

void listEsquerda(Deque *d) {
    if (estaVazio(d)) {
        return;
    }

    int i = d->inicio;
    while (i != d->fim) {
        printf("%d ", d->elementos[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", d->elementos[i]);
}

void listDireita(Deque *d) {
    if (estaVazio(d)) {
        printf("vazio\n");
        return;
    }

    int i = d->fim;
    while (i != d->inicio) {
        printf("%d ", d->elementos[i]);
        i = (i - 1 + MAX) % MAX;
    }
    printf("%d\n", d->elementos[i]);
}

int main() {
    Deque d;
    criarDeque(&d);

    char operacao[15];

    while (1) {
        scanf("%s", operacao);

        if (strcmp(operacao, "criarDeque(d)") == 0) {
            criarDeque(&d);
        } else if (strcmp(operacao, "pushEsquerda(d,") == 0) {
            int elem;
            scanf("%d", &elem);
            if (pushEsquerda(&d, elem) == FALHA) {
                return 0;
            }
        } else if (strcmp(operacao, "pushDireita(d,") == 0) {
            int elem;
            scanf("%d", &elem);
            if (pushDireita(&d, elem) == FALHA) {
                return 0;
            }
        } else if (strcmp(operacao, "popEsquerda(d)") == 0) {
            int result = popEsquerda(&d);
            if (result == FALHA) {
                return 0;
            } 
        } else if (strcmp(operacao, "popDireita(d)") == 0) {
            int result = popDireita(&d);
            if (result == FALHA) {
                return 0;
            }
        } else if (strcmp(operacao, "listEsquerda(d)") == 0) {
            listEsquerda(&d);
        } else if (strcmp(operacao, "listDireita(d)") == 0) {
            listDireita(&d);
        } else if (strcmp(operacao, "fim") == 0) {
            break;
        }
    }

    return 0;
}