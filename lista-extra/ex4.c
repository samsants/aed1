#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA -1

typedef struct nodo {
    int data;
    struct nodo*depois;
    struct nodo*prev;
} nodo;

typedef struct {
    nodo*frente;
    nodo*tras;
} Deque;

typedef struct {
    char operacao[15];
    int elem;
} Operacao;

int criarDeque(Deque*d) {
    d->frente=NULL;
    d->tras=NULL;
    return SUCESSO;
}

int pushEsquerda(Deque*d,int elem) {
    nodo*novonodo=(nodo*)malloc(sizeof(nodo));
    if (!novonodo) {
        return FALHA;
    }

    novonodo->data=elem;
    novonodo->depois=d->frente;
    novonodo->prev=NULL;

    if (d->frente==NULL) {
        d->frente=novonodo;
        d->tras=novonodo;
    } else {
        d->frente->prev=novonodo;
        d->frente=novonodo;
    }

    return SUCESSO;
}

int pushDireita(Deque*d,int elem) {
    nodo*novonodo=(nodo *)malloc(sizeof(nodo));
    if (!novonodo) {
        return FALHA;
    }

    novonodo->data=elem;
    novonodo->depois=NULL;
    novonodo->prev=d->tras;

    if (d->tras==NULL) {
        d->frente=novonodo;
        d->tras=novonodo;
    } else {
        d->tras->depois=novonodo;
        d->tras=novonodo;
    }

    return SUCESSO;
}

int popEsquerda(Deque *d) {
    if (d->frente==NULL) {
        return FALHA;
    }

    int elem=d->frente->data;
    nodo*temp=d->frente;

    if (d->frente==d->tras) {
        d->frente=NULL;
        d->tras=NULL;
    } else {
        d->frente=d->frente->depois;
        d->frente->prev=NULL;
    }

    free(temp);
    return elem;
}

int popDireita(Deque *d) {
    if(d->tras==NULL) {
        return FALHA;
    }

    int elem=d->tras->data;
    nodo*temp=d->tras;

    if (d->frente==d->tras) {
        d->frente=NULL;
        d->tras=NULL;
    } else {
        d->tras=d->tras->prev;
        d->tras->depois=NULL;
    }

    free(temp);
    return elem;
}

int listEsquerda(Deque*d) {
    if (d->frente==NULL) {
        printf("vazio\n");
        return FALHA;
    }

    nodo*atual=d->frente;
    while (atual!=NULL) {
        printf("%d ",atual->data);
        atual=atual->depois;
    }

    printf("\n");
    return SUCESSO;
}

int listDireita(Deque*d) {
    if (d->tras==NULL) {
        printf("vazio\n");
        return FALHA;
    }

    nodo*atual=d->tras;
    while (atual!=NULL) {
        printf("%d ",atual->data);
        atual=atual->prev;
    }

    printf("\n");
    return SUCESSO;
}

int main() {
    Deque d;
    Operacao operacoes[100]; 
    int numOperacoes = 0;

    do {
        scanf("%s", operacoes[numOperacoes].operacao);

        if (strcmp(operacoes[numOperacoes].operacao,"pushEsquerda(d,")==0||
            strcmp(operacoes[numOperacoes].operacao,"pushDireita(d,")==0) {
            scanf("%d", &operacoes[numOperacoes].elem);
        }

        numOperacoes++;
    } while (strcmp(operacoes[numOperacoes-1].operacao,"fim")!=0);

    for (int i = 0; i < numOperacoes; i++) {
        if (strcmp(operacoes[i].operacao,"criarDeque(d)")==0) {
            criarDeque(&d);
        } else if (strcmp(operacoes[i].operacao,"pushEsquerda(d,")==0) {
            if (pushEsquerda(&d,operacoes[i].elem)==FALHA) {
                printf("falha\n");
                return 0;
            }
        } else if (strcmp(operacoes[i].operacao,"pushDireita(d,")==0) {
            if (pushDireita(&d, operacoes[i].elem)==FALHA) {
                printf("falha\n");
                return 0;
            }
        } else if (strcmp(operacoes[i].operacao,"popEsquerda(d)")==0) {
            int resultado=popEsquerda(&d);
            if (resultado==FALHA) {
                printf("falha\n");
            }
        } else if (strcmp(operacoes[i].operacao,"popDireita(d)")==0) {
            int resultado=popDireita(&d);
            if (resultado==FALHA) {
                printf("falha\n");
            }
        } else if (strcmp(operacoes[i].operacao,"listEsquerda(d)")==0) {
            listEsquerda(&d);
        } else if (strcmp(operacoes[i].operacao,"listDireita(d)")==0) {
            listDireita(&d);
        }
    }

    return 0;
}
