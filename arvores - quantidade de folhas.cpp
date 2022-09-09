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

int  Folhas(treenodeptr arvore)
{
    int f = 0;
    if (arvore != NULL)
    {
        if(arvore->dir == 0 && arvore->esq == 0)
            f++;

        f +=	Folhas(arvore->dir);
        //	cout << arvore->info << " ";
        f +=	Folhas(arvore->esq);
    }
    return f;
}




int main()
{
    int x = 0;
    int f;
    treenodeptr arvore = NULL;
    treenodeptr p = NULL;


    cin >> x;

    while(x != -1)
    {
        tInsere(arvore, x);
        cin >> x;

    }

    f = Folhas(arvore);
    cout << f << endl;
    tDestruir(arvore);

    return 0;
}
