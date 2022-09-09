#include<iostream> 
using namespace std;
int hash_aux(int k, int m) {
	if (k>=0) {
		return k%m; 
	} else 
	return (k%m)+m; 
} int main () {
	int x; 
	int y;
	int res;
	cin >> x; 
	cin >> y; 
	while (x!=0 || y!=0)  {
	res=hash_aux(x,y); 
	cout << res << endl; 
	cin >> x; 
	cin >> y; 
	}
	return 0;
}
