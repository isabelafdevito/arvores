#include<iostream> 
#include<iomanip> 
#include<cmath> 
using namespace std; 
// fun para conversão da temperatura

void converte (float F, float &C, float &K) {

	cout << fixed << setprecision(2);
	cout << "Celsius: " << (F-32)/1.8 << endl; 
	cout << "Kelvin: " << ((F-32)/1.8)+273 << endl; 
	
}

int main () {
	
	float f;// var para inserir a temperatura a ser convertida
	float c; 
	float k; 
	cin >> f; 
	converte(f,c,k); 
	return 0; 
	
}
