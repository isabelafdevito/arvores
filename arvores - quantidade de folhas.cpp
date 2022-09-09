#include<iostream>
#include<list>
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

int contaFolhas(treenodeptr t)
{
    list<treenodeptr> q; // fila auxiliar
    treenodeptr n = t; // ponteiro para varrer a árvore
    int nFolhas = 0;
    
    if (t != NULL)
    {
        q.push_front(n);
        while (!q.empty())
        {
            n = q.front();
            q.pop_front();
            if (n->esq != NULL)
                q.push_back(n->esq);
            if (n->dir != NULL)
                q.push_back(n->dir);
            if(n->esq==NULL && n->dir==NULL)
                nFolhas++;
        }
    }
    return nFolhas;
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

int main()
{
    treenodeptr arvore=NULL; // ponteiro para a arvore
    int x; // var aux para leitura dos dados
    
    // Lendo dados e armazenando na arvore
    cin >> x;
    while(x!=-1)
    {
        tInsere(arvore,x);
        cin >> x;
    }
    
    // Mostrando o número de folhas
    cout << contaFolhas(arvore) << endl;
    
    // Liberando a memoria usada pela arvore
    tDestruir(arvore);
    
    
    return 0;
}
