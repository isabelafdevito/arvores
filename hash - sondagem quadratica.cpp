#include<iostream> 
using namespace std; 

void hash1(int k, int i, int m, int c1, int c2) {
    while (i<m) {
 	  if ((((k%m)+i)%m) >= 0) {
      cout << ((k%m) + c1*i + c2*i*i)%m << " ";
        i++; 
	   }
	   else if ((((k%m)+i)%m)<= 0) {
	   	cout << (((k%m) +m) + c1*i + c2*i*i)%m << " ";
	   i++; }
    }
 
} int main () {
	int k1; 
	int m1; 
	int i1; 
	int C1; 
	int C2;
	cin >> k1; 
    cin >> m1;
    cin >> C1; 
    cin >> C2;
    i1=0;
	hash1(k1,i1,m1, C1, C2);
	return 0;
}
