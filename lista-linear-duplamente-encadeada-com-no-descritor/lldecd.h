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
/*             funções (este arquivo)                                         */
/* lldecd.c -- arquivo com as implementações das funções declaradas no .h    */
/*                                                                           */
/* Para compilar o programa, use:                                            */
/*             gcc lldecd.c main.c -o lldecd.out                             */
/*                                                                           */
/* Para executar o programa, use:                                            */
/*             ./lldecd.out                                                  */
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO        1
#define FALHA         -1
#define CHAVE_INVALIDA 0
//
// Declaração de tipos globais
//
typedef
   struct Celula*    ApontadorCelula;
typedef
   struct Descritor* ApontadorDescritor;

typedef struct Descritor {
     ApontadorCelula prim;
     int             tam;
     ApontadorCelula ult;
} Descritor;

typedef struct Celula {
     ApontadorCelula ant;
     int             chave; 
     int             dado;
     ApontadorCelula prox;
} Celula;

//
// Protótipos das funções...
// 
int                 CriarDescritorLista (ApontadorDescritor* desc);
int                 InsInicio           (ApontadorDescritor* desc, Celula celula);
int                 InsFinal            (ApontadorDescritor* desc, Celula celula);
int                 MostrarLista        (ApontadorDescritor  desc);
int                 RemInicio           (ApontadorDescritor* desc);
int                 RemFinal            (ApontadorDescritor* desc);
int                 RemChave            (ApontadorDescritor* desc, int chave);
int                 TamLista            (ApontadorDescritor  desc);
/*
 * Futuras funções...
 *
int                 InsOrdem (ApontadorDescritor* desc, struct Celula celula);
ApontadorDescritor  ConcatListas(ApontadorDescritor *desc1, ApontadorDescritor *desc);
*
*/
