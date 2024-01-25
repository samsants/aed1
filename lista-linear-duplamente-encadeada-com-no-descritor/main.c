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
/* main.c   -- este arquivo, com o código do programa principal              */
/* lldecd.h -- arquivo com as declarações globais e os protótipos das        */
/*             funções                                                       */
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
#include "lldecd.h"

#define  MSG_CONTINUAR "Por favor, pressione <ENTER> para continuar."

int MostrarMenu(void) {
   int opcao;

   puts("================================================================================");
   puts("Lista Linear Duplamente Encadeada com Nó Descritor                              ");
   puts("================================================================================");
   puts("MENU                                                                            "); 
   puts("   [ 1] Criar descritor para lista                                              ");
   puts("   [ 2] Mostrar tamanho da lista                                                "); 
   puts("   [ 3] Mostrar a lista                                                         ");
   puts("   [ 4] Inserir no ínicio da lista                                              ");
   puts("   [ 5] Inserir no final  da lista                                              ");
   puts("   [ 6] Remover no início da lista                                              ");
   puts("   [ 7] Remover no final  da lista                                              ");
   puts("   [ 8] Remover usando a chave primária                                         ");
   puts("   [ 9] Ordenar a lista pela chave primária                                     "); 
   puts("   [10] Concatenar duas listas                                                  ");
   puts("   [11] Uso futuro                                                              ");
   puts("   [12] Uso futuro                                                              ");
   puts("   [13] Uso futuro                                                              ");
   puts("                                                                                ");
   puts("   [ 0] Sair                                                                    ");
   puts("================================================================================");
   do {
      printf("Opcao: ");
      scanf("%d", &opcao);
   } while ((opcao < 0) && (opcao > 10));
   return(opcao);
}

/*
 * Realiza a leitura da <chave primária> e dos <dados> da célula recebida como
 * parâmetro.
 * Inicializa os campos <ant> e <prox> com NULL (apesar disto não ser obrigatório).
 *
 * Observação: Somente aceita chave primária inteira e estritamente positiva.
 */
int LerCelula(Celula * cel) {
    int intChave, intDado;
    do
      {
        puts("Por favor, informe o valor da CHAVE PRIMÁRIA: ");
        scanf("%d",&intChave);
        if (intChave > CHAVE_INVALIDA) {
            puts("Por favor, informe o valor do DADO: ");
            scanf("%d",&intDado);
            cel->chave = intChave;
            cel->dado  = intDado;
            cel->ant   = (ApontadorCelula) NULL;
            cel->prox  = (ApontadorCelula) NULL;
        }
        else {
          puts("A chave primária informada é inválida e, por isso,");
          puts("outro valor para ela deve ser informado.");
        }
    } while (intChave <= CHAVE_INVALIDA);
    return(SUCESSO);
}

int main (void) {

    ApontadorDescritor descritorLista;
    char               tecla;
    int                opcao, statusOperacao;
    int                intChave, intValor; 
    Celula             celulaAuxiliar;
    
    descritorLista = (ApontadorDescritor) NULL;
    do {
      opcao = MostrarMenu();
      switch (opcao) {
          case  1 : {
            statusOperacao = CriarDescritorLista(&descritorLista);
            if (statusOperacao == SUCESSO) {
              puts("Descritor da lista linear duplamente encadeada criado com sucesso.");
            }
            else {
              puts("Houve um erro ao criar o descritor da lista linear duplamente encadeada.");
            }
            break;
          }
          case  2 : {
            statusOperacao = TamLista(descritorLista);
            if (statusOperacao != FALHA) {
               printf("A lista possui %d elementos.\n", statusOperacao);
            }
            else {
               puts("A lista não foi criada e, por isso, não é possível mostrar seu tamanho.");
            }
            break;
          }
          case  3 : {
            statusOperacao = MostrarLista(descritorLista);
            break;
          }
          case  4 : {
            LerCelula(&celulaAuxiliar);
            statusOperacao = InsInicio(&descritorLista, celulaAuxiliar);
            if (statusOperacao == SUCESSO) {
              puts("Célula inserida com sucesso no início da lista.");
            }
            else {
              puts("Houve um erro inserir a célula no início da lista e, por isso,");
              puts("a operação não foi realizada.");
            }
            break;
          }
          case  5 : {
            LerCelula(&celulaAuxiliar);
            statusOperacao = InsFinal(&descritorLista, celulaAuxiliar);
            if (statusOperacao == SUCESSO) {
              puts("Célula inserida com sucesso no final da lista.");
            }
            else {
              puts("Houve um erro inserir a célula no final da lista e, por isso,");
              puts("a operação não foi realizada.");
            }
            break;
          }
          case  6 : {
            puts("A operação de remover a célula do início da lista não está disponível.");
            break;
          }
          case  7 : {
            puts("A operação de remover a célula do final da lista não está disponível.");
            break;
          }
          case  8 : {
            puts("A operação de remover a célula com determinada chave primária não está disponível.");
            break;
          }
          case  9 : {
            puts("A operação de ordenar a lista pela chave primária não está disponível.");
            break;
          }
          case 10 : {
            puts("A operação de concatenar duas listas não está disponível.");
            break;
          }
          case  0 : {
            puts("Obrigado por utilizar esta aplicação.");
            puts("Espero ter atendido suas necessidades. Até mais!");
            break;
          }
          default : {
            puts("Esta opção não esta na lista de opções possíveis.");
            puts("Por favor, escolha outra opção.");
          }
      }
    } while (opcao != 0);

    return (EXIT_SUCCESS);
}
