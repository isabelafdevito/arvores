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

int hash_aux2(int k, int m) 
{
	int h2;
	h2= 1 + k%(m-1);
	return h2;
}

// implementando a sondagem linear
int hash1 (int k, int i, int m) 
{
	return (hash_aux(k,m)+i*hash_aux2(k,m))%m;
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
	return -1;
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

int hash_delete(dado T[], int k, int m) {
	int j; 
	j=hash_search(T,k,m);
	if(j!=-1) {
		T[j].status=2; // status = 2 - removido
		T[j].k=-1;
		return 0;
	} else
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
	char l;
	cin >> l;
	while (l!='X') {
		if (l=='I') {
        cin >> k;
		hash_insert(T,m,k); }
		if (l=='P') {
			cin >> k;
			int res;
		res=hash_search(T,k,m);
			if(res!=-1)
		cout << res << endl;
			else 
		cout << "-1" << endl; }
		if (l=='R') {
			cin >> k;
		hash_delete(T,k,m);}
		if (l=='L') {
	// Mostrar a tabela
		for (i=0;i<m;i++){
			cout << T[i].k << " ";
	} 			cout << endl;}
		cin >> l;
	}
	
	return 0;	
}
