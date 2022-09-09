#include <iostream>
 
using namespace std;
int binaria(int vetor[], int tamanho, int x)
{
    bool achou; 
    int baixo, meio, alto; 
    baixo=0; 
    alto=tamanho-1; 
    achou=false; 
    while ((baixo <= alto) && (achou==false)) {
        meio = (baixo+alto)/2; 
        if (x< vetor[meio]) 
            alto=meio-1;
        else if (x> vetor[meio])
            baixo=meio+1;
        else 
            achou=true;
    }
    if (achou)
        return meio; 
    else 
        return -1;
}
int main () {
    int vet[100]; 
    int tam; 
    int y; 
    int a=0; 
    cin >> vet[a];
    while (vet[a]!=-1) {
        a++;
        cin >> vet[a];
    }
    tam=a-1; 
    cin >> y; 
    int res;
    res=binaria(vet,tam,y);
    if (res==-1) 
        cout << "Nao possui acesso" << endl; 
    else 
        cout << "Possui acesso" << endl;
    
    return 0;
    
}
