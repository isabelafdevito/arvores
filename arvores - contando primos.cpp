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

int contaPrimos(treenodeptr arvore)
{
    int div = 0;
    int primo = 0;

    if (arvore != NULL)
    {
        for(int i = 1; i<=arvore->info; i++)
        {
            if(arvore->info % i == 0)
                div++;
        }
        if(div == 2)
            primo++;

        primo += contaPrimos(arvore->dir);
        primo += contaPrimos(arvore->esq);

    }
    return primo;
}



int main()
{
    int x = 0;
    int primos = 0;
    treenodeptr arvore = NULL;


    cin >> x;

    while(x != -1)
    {
        tInsere(arvore, x);
        cin >> x;

    }

    primos = contaPrimos(arvore);
    cout << primos << " numeros primos" <<endl;

    tDestruir(arvore);


    return 0;
}
