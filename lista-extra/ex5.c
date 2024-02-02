#include <stdlib.h>
#include <stdio.h>
    
void percorrerCasasDecimais(int n, int digitoComparador, int score){
    if(n==0){
        printf("%d ", score);
        return ;
    }
    
    int digitoAtual = n % 10;
    if(digitoAtual == digitoComparador){
        score ++;
    }
    
    percorrerCasasDecimais(n/10, digitoComparador, score);
    
}
    
int main(){
    int k;
    int t;
    int i;
    int score;
    
    scanf("%d",&t);
    scanf("%d",&k);
    
    int casos[k];
    
    for(i=0;i<t;i++){
        scanf("%d",&casos[i]);
    }
    
    for(i=0;i<t;i++){
        percorrerCasasDecimais(casos[i],k,0);
    }
    
}