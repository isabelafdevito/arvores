#include<iostream>
using namespace std;

struct dado 
{
	int k; // chave
	int status; // 0=livre / 1=ocupado
};

// função que implementa a posição que a chave k vai ficar
int hash_aux(int k, int m) 
{
	
	int h; // posição
	h=k%m;
	if (h<0) {
		h=h+m; 
		}
	return h;
}

// implementando a sondagem linear
int hash1 (int k, int i, int m) 
{
	return (hash_aux(k,m)+i)%m;
}

// insere a chave k em uma tabela de tamanho m
int hash_insert(dado T[], int m, int k) 
{
	int i=0;
	int j; // posição da chave
	do {
		j=hash1(k,i,m);
		if (T[j].status!=1) 
		{
			T[j].k=k;
			T[j].status=1;
			return j;
		} else
		{
			i++;
		}
	} while (i!=m);
	return -1; // tabela cheia
} 

int hash_search(dado T[],int k, int m) {
 int i=0;
 int j; // posição da chave
	do 
	{
		j=hash1(k,i,m);
		if (T[j].k==k) 
			return j;
		else 
			i++;
	} while (T[j].status!=0 || i < m);
	return -1;
}

int main () {
	int i;
	dado T[20]; // tabela hash
	// ler o tamaho da tabela 
	int m;
	cin >> m;
	
	// inicializar a tabela
	for (i=0; i<m; i++) {
		T[i].k=-1;
		T[i].status=0;
	}
	
	// ler as chaves e inserir na tabela
	int k;
	cin >> k;
	while (k!=0) {
		hash_insert(T,m,k);
		cin >> k;
	}
	int s;
	cin >> s;
	int res;
	res=hash_search(T,s,m);
	if(res!=-1)
		cout << "Chave " << s << " encontrada na posicao " << res << endl;
	else 
		cout << "Chave " << s << " nao encontrada" << endl;
	
	return 0;
	
} 
