#include<iostream>
#include<iomanip>
using namespace std;


struct treenode {
	int info; // raiz 
	treenode *esq; // sub-arvore esquerda
	treenode *dir; //sub - arvore direita
}; 

typedef treenode *treenodeptr; // definindo uma variavel tipo treenode

void tInsere(treenodeptr &p, int x) {
	if(p==NULL) { // insere na raiz pq vai estar vazio
	p = new treenode; 
	p->info = x;
	p->esq = NULL; 
	p->dir = NULL;
}
	else 
		if(x <p->info) // insere a esquerda
			tInsere(p->esq,x);
		else // insere a direita
			tInsere(p->dir,x); 
}
// ordenação DECRESCENTE (dir maior que esq)

void emOrdem (treenodeptr p,int &y) {
	int maior = -9999;
	if(p!= NULL) {
		emOrdem(p->esq,y);
		if(p->info>maior && p->info%2==0) {
			maior=p->info;
			y=p->info;
		}
		emOrdem(p->dir,y);
	}
	
}
int main() {
	treenodeptr arvore = NULL; // começa com NULL
	int x=0; // elemento a ser inserido
	while(x!=-1) {
		cin >> x; 
		if(x!=-1)
		tInsere(arvore,x);
	}	
	int y=0;
	emOrdem(arvore,y);
	
	cout << y << endl;
		
		
		return 0;
}