/*---------------------------------------------------------------------------*/
/* UNIVERSIDADE FEDERAL DE GOIÁS - UFG                                       */
/* INSTITUTO DE INFORMÁTICA - INF                                            */
/*                                                                           */
/* Disciplina: Algoritmos e Estruturas de Dados - 1                          */
/* Professor.: Wanderley de Souza Alencar                                    */
/*                                                                           */
/* Observacoes:                                                              */
/*                                                                           */
/* Este programa implementa, de maneira simples e com finalidade didática,   */
/* um conjunto basico de operacoes sobre a estrutura de LISTA LINEAR         */
/* DUPLAMENTE ENCADEADA COM NO DESCRITOR.                                    */
/*                                                                           */
/* A estrutura da lista obedece o seguinte lay-out:                          */
/*                                                                           */
/*   numero in-  <---------+               +--> ponteiro para a proxima      */
/*   teiro                 |               |    Celula                       */
/*   (exemplo)  +------+-------+-------+------+                              */
/*              | ant  | chave | dados | prox |                              */
/*              +------+-------+-------+------+                              */
/*                 |                                                         */
/*                 +----> ponteiro para a proxima Celula                     */
/*                                                                           */
/* O programa é formado por três arquivos:                                   */
/*                                                                           */
/* main.c   -- código do programa principal                                  */
/* lldecd.h -- arquivo com as declarações globais e os protótipos das        */
/*             funções                                                       */
/* lldecd.c -- arquivo com as implementações das funções declaradas no .h    */
/*             (este arquivo)                                                */
/* Para compilar o programa, use:                                            */
/*             gcc lldecd.c main.c -o lldecd.out                             */
/*                                                                           */
/* Para executar o programa, use:                                            */
/*             ./lldecd.out                                                  */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "lldecd.h"

int CriarDescritorLista (ApontadorDescritor* desc) {

    (*desc) = (ApontadorDescritor) malloc( sizeof(Descritor) );
    if ((*desc) == NULL) {
       return (FALHA);
    }
    else {
       (*desc)->prim = (ApontadorCelula) NULL;
       (*desc)->tam  = 0;
       (*desc)->ult  = (ApontadorCelula) NULL;
       return (SUCESSO);
    }
}

int InsInicio (ApontadorDescritor* desc, Celula celula) {
    ApontadorCelula q;

    q = (ApontadorCelula) malloc( sizeof(Celula) );
    if (q == NULL) {
        return(FALHA);
    }
    else {
        q->chave = celula.chave;
        q->dado  = celula.dado;
        q->ant   = (ApontadorCelula) NULL;
        q->prox  = (*desc)->prim;

        if ((*desc)->tam == 0) {
           (*desc)->ult  = q;
        }
        else {
           ((*desc)->prim)->ant = q;
        }
        (*desc)->prim = q;
        (*desc)->tam++;
        return(SUCESSO);
    }
}

int InsFinal (ApontadorDescritor* desc, Celula celula) {
    //
    // Estudante elaborar o código...
    //
    return(SUCESSO);
}

/*
 * Apresenta, no dispositivo de saída (normalmente o monitor de vídeo),
 * os elementos presentes na lista.
 */

int MostrarLista (ApontadorDescritor desc) {
    ApontadorCelula r;

    if (desc == NULL) {
       return(FALHA);
    }
    else {
       if (desc->tam == 0) {
         puts("A lista está VAZIA.");
       }
       else {
         r = desc->prim;
         puts("Lista linear [elementos do primeiro ao último]");
         do {
            printf("[chave = %d, dado = %d]\n",r->chave,r->dado);
            r = r->prox;
         } while (r != NULL);
       }
    }
    return(SUCESSO);
}

int RemInicio (ApontadorDescritor* desc) {
    //
    // Estudante elaborar o código...
    //
    return(SUCESSO);
}

int RemFinal (ApontadorDescritor* desc) {
    //
    // Estudante elaborar o código...
    //
    return(SUCESSO);
}

int RemChave (ApontadorDescritor* desc, int chave) {
    //
    // Estudante elaborar o código...
    //
    return(SUCESSO);
}

int TamLista (ApontadorDescritor  desc) {
    if (desc != NULL) {
       return(desc->tam);
    }
    else {
       return(FALHA);
    }
}
