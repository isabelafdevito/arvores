#include <iostream>
#include <list>

using namespace std;


struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;

};


typedef treenode *treenodeptr;


void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info) // insere na subarvore esquerda
        tInsere(p->esq, x);
    else // insere na subarvore direita
        tInsere(p->dir, x);
}



void tDestruir (treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }
    arvore = NULL;
}

int maior(treenodeptr arvore) {

    int maior_arv; 
    maior_arv=arvore->info;
    while(arvore->dir != NULL) {
        if(maior_arv < arvore->dir->info) {
            maior_arv = arvore->dir->info;
        }
        arvore->dir = arvore->dir->dir;

    }

    return maior_arv;

}

int menor(treenodeptr arvore) {


    int menor_arv; 
    menor_arv=arvore->info; 
    while(arvore->esq != NULL) {
        if(menor_arv > arvore->esq->info) {
            menor_arv = arvore->esq->info;
        }
        arvore->esq = arvore->esq->esq;

    }
    return menor_arv;

}



int main()
{
    int x;
    treenodeptr arvore = NULL;


    cin >> x;

    while(x != -1)
    {
        tInsere(arvore, x);
        cin >> x;

    }


    cout  <<  menor(arvore) << " e "  << maior(arvore) << endl;
    tDestruir(arvore);


    return 0;
}
