#include <iostream>
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

void emOrdemNF (treenodeptr arvore, int &n)
{
    if (arvore != NULL)
    {
        emOrdemNF(arvore->esq,n);
        if(arvore->esq==NULL && arvore->dir==NULL)
            n++;
        emOrdemNF(arvore->dir,n);
    }
}

int naoFolhas(treenodeptr arvore)
{
    int n = 0; // quantidade de nao folhas

    emOrdemNF(arvore,n);

    return n;
}

int main()
{
    treenodeptr arvore = NULL; // ponteiro para a arvore
    int x; // var aux para leitura dos dados

    // Lendo elementos e armazenando na arvore
    cin >> x;
    while(x != -1)
    {
        tInsere(arvore,x);
        cin >> x;
    }

    // Contando e mostrando quantidade de nao folhas
    cout << naoFolhas(arvore) << endl;

    return 0;
}
