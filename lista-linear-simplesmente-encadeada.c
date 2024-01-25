/*---------------------------------------------------------------------------*/
/* UNIVERSIDADE FEDERAL DE GOIÁS - UFG                                       */
/* INSTITUTO DE INFORMÁTICA - INF                                            */
/*                                                                           */
/* Disciplina: Algoritmos e Estruturas de Dados - 1                          */
/* Professor.: Wanderley de Souza Alencar                                    */
/* Programa..: Lista Linear Simplesmente Encadeada                           */
/*                                                                           */
/* A estrutura da lista obedece o seguinte lay-out:                          */
/*                                                                           */
/*   numero in-  <---------+       +--> ApontadorCelula para a proxima       */
/*   teiro                 |       |    Celula                               */
/*   (exemplo)         +-------+------+                                      */
/*                     | dado  | prox |                                      */
/*                     +-------+------+                                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define SUCESSO          1
#define FALHA           -1

#define CHAVE_INVALIDA   0 

typedef struct Celula*  ApontadorCelula;

typedef struct Celula { 
     int             chave;
     int             dado;
     ApontadorCelula prox;
} Celula;  

int  CriarListaVazia    (ApontadorCelula * p); 
int  CriarListaChave    (ApontadorCelula * p, Celula celula);
int  InsInicio          (ApontadorCelula * p, Celula celula);
int InsFinal (ApontadorCelula * p, Celula celula);
int TamLista (ApontadorCelula p);

int CriarListaVazia(ApontadorCelula * p) {
    (*p) = (ApontadorCelula) NULL;
    return (SUCESSO);
}

int CriarListaChave(ApontadorCelula * p, Celula celula) {
    int statusOperacao;

    (*p) = (ApontadorCelula) NULL;
    statusOperacao = InsInicio(p, celula);
    return (statusOperacao);
}

int InsInicio (ApontadorCelula * p, Celula celula) {
    ApontadorCelula q;

    q = (ApontadorCelula) malloc(sizeof(Celula));
    if (q != NULL) {
       q->chave = celula.chave;
       q->dado  = celula.dado;
       q->prox  = (ApontadorCelula) p;
       (*p)     = q;
    }
    else {
       return(FALHA);
    }
    return(SUCESSO);
}


int TamLista (ApontadorCelula p) {
    unsigned int  tam;
    ApontadorCelula r;

    r   = p;
    tam = 0;
    if (r == NULL) {
        return(tam);
    }
    else {
        while (r != NULL) {
            r = r->prox;
            tam++;
        }
        return(tam);
    }
}

int InsFinal(ApontadorCelula * p, Celula celula) {

    ApontadorCelula q, r;

    q = (ApontadorCelula) malloc(sizeof(Celula));
    if (q != NULL) {
        printf("Aloquei memória...\n");
        q->chave = celula.chave;
        q->dado  = celula.dado;
        q->prox  = NULL;
        r = (*p);
        if (r == NULL) {    // a lista está vazia inicialmente
           (*p) = q;
        }
        else {
           printf("Iniciando rastreamento...\n");
           while (r->prox != NULL) {
               r = r->prox;
           }
           printf("Inserindo o nó no final...\n");
           r->prox = q;
        }
        return (SUCESSO);
    }
    else {
        return(FALHA);
    }p
}


int main (void) {
    
    int             intResultado, opcao;
    Celula          celula;
    ApontadorCelula lista1, lista2;
    

    intResultado = CriarListaVazia(&lista1);

    if (intResultado == SUCESSO) {
       printf("Sucesso: lista 1 criada.\n");
       printf("%p\n", lista1);

       printf("Digite a CHAVE: ");
       scanf("%d",&celula.chave);
       printf("Digite o DADO: ");
       scanf("%d",&celula.dado);
       celula.prox = NULL;

       printf("Digite [1] para InsInicio, [2] InsFinal: ");
       scanf("%d",&opcao);
       if (opcao == 1) {
          intResultado = InsInicio(&lista1, celula);
          if (intResultado == SUCESSO) {
              printf("Inserida no início\n");
              printf("Tamanho = %d\n", TamLista(lista1));
          }
          else {
              printf("Falha: Sem memória.\n");
          }
        }
        else {
            if (opcao == 2) {
               intResultado = InsFinal(&lista1, celula);
               if (intResultado == SUCESSO) {
                  printf("Inserida no final\n");
                  printf("Tamanho = %d\n", TamLista(lista1));
               }
               else {
                  printf("Falha: Sem memória.\n");
               }
            }
        }
    }
    else { 
       printf("Erro: Não foi possível criar a lista.");
       return(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
