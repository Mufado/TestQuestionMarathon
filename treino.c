#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int n;
    struct NO* prox;
    struct NO* ant;
}no;

no* entrada= NULL;
no* virar_po= NULL;
int tam= 0;

void add(){
    no *novo= (no*) malloc(sizeof(no));

    if(entrada== NULL){
        entrada= novo;
        virar_po= novo;
        novo->prox= novo;
        novo->ant= novo;
        novo->n= 1;
    }else if(entrada->prox== entrada){
        novo->prox= entrada;
        novo->ant= entrada;
        novo->n= 2;
        entrada->prox= novo;
        entrada->ant= novo;
        entrada= novo;
    }else{
        novo->prox=entrada;
        entrada->ant->prox= novo;
        novo->ant= entrada->ant;
        entrada->ant= novo;
        entrada= novo;
        novo->n= novo->prox->n+1;
    }
    tam++;
}

void del_ate_sobrar_1(int P){
    if(0 < P && P < 10000){
        while(tam> 1){
            int aux;
            for(aux= P; aux>= 1; aux--){
                virar_po= virar_po->ant;
            }

            no* lixo= virar_po;
            virar_po= virar_po->ant;

            if(lixo== entrada){
                entrada= lixo->prox;
            }

            virar_po->prox= lixo->prox;
            lixo->prox->ant=virar_po;
            free(lixo);
            tam--;
        }
    }
}

int main(){
    int N, P;
    scanf("%d", &N);
    scanf("%d", &P);

    while(N> 0){

        add();
        N--;
    }
    del_ate_sobrar_1(P);

    printf("%d\n", entrada->n);
return 0;
}
