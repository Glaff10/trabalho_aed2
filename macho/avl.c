#include "avl.h"

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int altura(avl* atu){
    if(atu) return atu->altura;
    return -1;
}

avl* criaAvl(){
    return NULL;
}

avl* criaNo(int num){
    avl *a = (avl*)malloc(sizeof(avl));
    a->dir = a->esq = NULL;
    a->altura = 0;
    a->num = num;
    return a;
}

avl* Rrot(avl* k2){
    avl* k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;

    k2->altura = max(altura(k2->esq), altura(k2->dir)) + 1;
    k1->altura = max(altura(k1->esq), altura(k2)) + 1;
    return k1; /* new root */
}

avl* Lrot(avl* k1){
    avl* k2 = k1->dir;
    k1->dir = k2->esq;
    k2->esq = k1;

    k1->altura = max(altura(k1->esq), altura(k1->dir)) + 1;
    k2->altura = max(altura(k2->dir), altura(k1)) + 1;

    return k2;  /* New root */
}

avl* LRrot(avl* k3){
    k3->esq = Lrot(k3->esq);
    return Rrot(k3);
}

avl* RLrot(avl* k1){
    k1->dir = Rrot(k1->dir);
    return Lrot(k1);
}
avl* inserirAvl(avl* atu, int num){
    if(atu == NULL) atu = criaNo(num);
    else if(num < atu->num){
        atu->esq = inserirAvl(atu->esq, num);
        if(altura(atu->esq) - altura(atu->dir) == 2){
            if(num < atu->esq->num) atu = Rrot(atu);
            else atu = LRrot(atu);
        }
    }
    else if(num > atu->num){
        atu->dir = inserirAvl(atu->dir, num);
        if(altura(atu->dir) - altura(atu->esq) == 2){
            if(num > atu->dir->num) atu = Lrot(atu);
            else atu = RLrot(atu);
        }
    }
    atu->altura = max(altura(atu->esq), altura(atu->dir)) + 1;
    return atu;
}


avl* buscaAvl(avl *a, int num) {
    avl *ret = NULL;
    if(a == NULL) {
        ret = NULL;
    }
    else if(num > a->num) {
        ret = buscaAvl(a->dir,num);
    }
    else if(num < a->num) {
        ret = buscaAvl(a->esq,num);
    }
    else {
        ret = a;
    }
    return ret;
}

void imprimeAvl(avl *a, int val) {
    if(a!=NULL) {
        if(val==0) printf("%d\n",a->num);
        imprimeAvl(a->esq,val);
        if(val==1) printf("%d\n",a->num);
        imprimeAvl(a->dir,val);
        if(val==2) printf("%d\n",a->num);
    }
}

avl* liberaAvl(avl *a) {
    if(a != NULL) {
        liberaAvl(a->esq);
        liberaAvl(a->dir);
        free(a);
    }
    return NULL;
}

int taEmOrdem(avl *atu){
    int res = 1;
    if(atu->esq) res &= (taEmOrdem(atu->esq) && atu->esq->num <= atu->num);
    if(atu->dir) res &= (taEmOrdem(atu->dir) && atu->dir->num >= atu->num);
    return res;
}
int numElementos(avl *atu){
    int res = 0;
    if(atu) res = 1 + numElementos(atu->esq) + numElementos(atu->dir);
    return res;
}
int altura2(avl *atu){
    if(!atu) return 0;
    int res = 0;
    if(atu->esq) res += 1 + altura2(atu->esq);
    if(atu->dir) res=max(res, 1 + altura2(atu->dir));
    return res;
}

int taBalanceada(avl *atu){
    if(!atu) return 1;
    int bf = altura2(atu->dir) - altura2(atu->esq);
    if(bf>1 || bf<-1) return 0;
    return taBalanceada(atu->esq) && taBalanceada(atu->dir);
}


int taCerto(avl *atu, int n){
    return (taEmOrdem(atu) && numElementos(atu) == n && taBalanceada(atu));
}