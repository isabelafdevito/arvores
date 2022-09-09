#include <iostream>
using namespace std;

// sequencia fatorial:
int fatorial (int n) {

    if(n==0)
        return 1;
    else
        return n*fatorial(n-1);

}

// metodo para calcular a sequencia de fibonacci:
int fib (int n) {

    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if (n>1)
        return fib(n-1)+fib(n-2);

}
int main() {

    int y;
    cout << "Insira o numero fatorial que deseja calcular: " << endl;
    cin >> y;
    cout << fatorial(y) << endl;

    int x;
    cout << "Insira o n-esimo termo da sequencia de fibonacci que deseja calcular: " << endl;
    cin >> x;
    cout << fib(x);

    return 0;
}
