#include <stdio.h>
#include <stdlib.h>

void imprimeCasaCentenas(int n){
    switch(n){
        case 100: 
        printf("CEM ");
        break;
        case 200: 
        printf("DUZENTOS ");
        break;
        case 300: 
        printf("TREZENTOS ");
        break;
        case 400: 
        printf("QUATROCENTOS ");
        break;
        case 500: 
        printf("QUINHENTOS ");
        break;
        case 600: 
        printf("SEISCENTOS ");
        break;
        case 700: 
        printf("SETECENTOS ");
        break;
        case 800: 
        printf("OITOCENTOS ");
        break;
        case 900: 
        printf("NOVECENTOS ");
        break;
    }
}

void imprimeCasaDezenas(int n){
    switch(n){
        case 20: 
        printf("VINTE ");
        break;
        case 30: 
        printf("TRINTA ");
        break;
        case 40: 
        printf("QUARENTA ");
        break;
        case 50: 
        printf("CINQUENTA ");
        break;
        case 60: 
        printf("SESSENTA ");
        break;
        case 70: 
        printf("SETENTA ");
        break;
        case 80: 
        printf("OITENTA ");
        break;
        case 90: 
        printf("NOVENTA ");
        break;
    }
}

void imprimeDezenas(int n){
    switch(n){
        case 10: 
        printf("DEZ ");
        break;
        case 11: 
        printf("ONZE ");
        break;
        case 12: 
        printf("DOZE ");
        break;
        case 13: 
        printf("TREZE ");
        break;
        case 14: 
        printf("CATORZE ");
        break;
        case 15: 
        printf("QUINZE ");
        break;
        case 16: 
        printf("DEZESSEIS ");
        break;
        case 17: 
        printf("DEZESSETE ");
        break;
        case 18: 
        printf("DEZOITO ");
        break;
        case 19: 
        printf("DEZENOVE ");
        break;
    }
}

void imprimeUnidade(int n){
    switch(n){
        case 1: 
        printf("UM ");
        break;
        case 2: 
        printf("DOIS ");
        break;
        case 3: 
        printf("TRES ");
        break;
        case 4: 
        printf("QUATRO ");
        break;
        case 5: 
        printf("CINCO ");
        break;
        case 6: 
        printf("SEIS ");
        break;
        case 7: 
        printf("SETE ");
        break;
        case 8: 
        printf("OITO ");
        break;
        case 9: 
        printf("NOVE ");
        break;
    }
}

void imprimeInteiros(int inteiros){
    int milhaoInteiro = inteiros / 1000000; //
    int restoMilhao = inteiros % 1000000;

    int centenaDeMilharInteiro = restoMilhao / 100000;//
    int restoCentenaDeMilhar = restoMilhao % 100000;

    int dezenaDeMilharInteiro = restoCentenaDeMilhar / 10000;//
    int restoDezenaDeMilhar = restoCentenaDeMilhar % 10000;

    int milharInteiro = restoDezenaDeMilhar / 1000;//
    int restoMilhar = restoDezenaDeMilhar % 1000;

    int centenaInteiro = restoMilhar / 100;//
    int restoCentena = restoMilhar % 100;

    int dezenaInteiro = restoCentena / 10;//
    int unidadeInteiro = restoCentena % 10;//

    if(milhaoInteiro==1){
        imprimeUnidade(milhaoInteiro);
        printf("MILHAO ");
    }

    if(milhaoInteiro>1){
        imprimeUnidade(milhaoInteiro);
        printf("MILHOES ");
    }

    if(centenaDeMilharInteiro>1){
        imprimeCasaCentenas(centenaDeMilharInteiro*100);
        if(dezenaDeMilharInteiro>=1||milharInteiro>=1){
            printf("E ");
        }
    }
    else if(centenaDeMilharInteiro==1){
        printf("CENTO ");
        if(dezenaDeMilharInteiro>=1||milharInteiro>=1){
            printf("E ");
        }
    }

    if(dezenaDeMilharInteiro>=2){
        imprimeCasaDezenas(dezenaDeMilharInteiro*10);
        if(milharInteiro>=1){
            printf("E ");
        }
    }

    if(dezenaDeMilharInteiro==1){
        if(milharInteiro==0){
            imprimeDezenas(dezenaDeMilharInteiro*10);
        }else{
            imprimeDezenas(dezenaDeMilharInteiro*10+milharInteiro);
        }
    }
}

void imprimeNomeCentavosPlural(){
    printf("CENTAVOS");
}

void imprimeNomeCentavosSingular(){
    printf("CENTAVO");
}

void imprimeCentavos(int centavos){
    int dezenasCentavos = centavos/10;;
    int unidadesCentavos  = centavos-(dezenasCentavos*10);

    if(centavos>9&&centavos<=19){
        imprimeDezenas(centavos);
        imprimeNomeCentavosPlural();
        return;
    }

    if(centavos>=20&&centavos<=99){
        imprimeCasaDezenas(dezenasCentavos*10);
        if(unidadesCentavos>0){
            imprimeUnidade(unidadesCentavos);
        }
        imprimeNomeCentavosPlural();
        return;
    }

    if(unidadesCentavos>=2){
        imprimeUnidade(unidadesCentavos);
        imprimeNomeCentavosPlural();
        return;
    }

    if(unidadesCentavos==1){
        imprimeUnidade(unidadesCentavos);
        imprimeNomeCentavosSingular();
        return;
    }
}

int main(){
    int parteInteira, parteDecimal;

    scanf("%d,%d",&parteInteira ,&parteDecimal); 
    imprimeInteiros(parteInteira);
    printf("\n");
    imprimeCentavos(parteDecimal);
    

    return 0; 
}