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

void Maimer(treenodeptr arvore, int &maior, int &menor)
{
    if (arvore != NULL)
    {
        if(arvore->info > maior)
            maior = arvore->info;
        if(arvore->info < menor)
            menor = arvore->info;
        Maimer(arvore->dir, maior, menor);
        //	cout << arvore->info << " ";
        Maimer(arvore->esq, maior, menor);
    }
}


int main()
{
    int x = 0;
    int maior = -50000;
    int menor = 1000000;
    treenodeptr arvore = NULL;
    treenodeptr p = NULL;


    cin >> x;

    while(x != -1)
    {
        tInsere(arvore, x);
        cin >> x;

    }

    Maimer(arvore, maior, menor);

    cout << "Menor: " <<  menor << " e " <<  "Maior: " << maior << endl;
    tDestruir(arvore);


    return 0;
}
