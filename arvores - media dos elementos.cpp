#include <iostream>
#include <iomanip>

using namespace std;


struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;

};


typedef treenode *treenodeptr;

float soma = 0;
int n = 0;

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




void Medias (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        Medias(arvore->dir);
        soma += arvore->info;
        n++;
        Medias(arvore->esq);

    }
}


int main()
{
    int x = 0;
    treenodeptr arvore = NULL;
    treenodeptr p = NULL;


    cin >> x;

    while(x != -1)
    {
        tInsere(arvore, x);
        cin >> x;

    }

    Medias(arvore);
    cout << "Media: " << fixed << setprecision(2) <<(soma/n)*1.0 << endl;


    return 0;
}
