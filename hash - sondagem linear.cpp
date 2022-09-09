#include<iostream>
#include<cmath>
using namespace std;
 
void hash1(int k, int i, int m) {
    while (i<m) {
 	  if ((((k%m)+i)%m) >= 0) {
      cout << ((k%m)+i)%m << " ";
        i++; 
	   }
	   else if ((((k%m)+i)%m)<= 0) {
	   	cout << (((k%m)+i)%m) +m << " ";
	   i++; }
    }
 
} int main () {
	int k1; 
	int m1; 
	int i1; 
	cin >>k1; 
    cin >> m1;
    i1=0;
	hash1(k1,i1,m1);
	return 0;
}
