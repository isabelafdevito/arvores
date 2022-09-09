#include<iostream>
using namespace std;
 
int sequencial(int vet[], int tam, int x) {
    bool achou = false; 
    int i=0; 
    while (achou==false && i < tam) 
        achou=vet[i++]==x; 
    if (achou) 
    	cout << x << " encontrado na posicao " << i-1 << endl;
    else 
        cout << x << " nao encontrado" << endl;
    return 0;
}

int main () {
    int vetor[100];
    int tamanho; 
    int y; 
    int a=0;
    cin >> vetor[a];
    while (vetor[a]!=-1) {
        a++;
        cin >> vetor[a];
    }
    tamanho=a;
    cin >> y;
    sequencial(vetor,tamanho,y);
    return 0;
}
