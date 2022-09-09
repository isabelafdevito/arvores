#include<iostream> 
#include<iomanip> 
#include<cmath> 
using namespace std; 

int calc_raizes(float a, float b, float c, float &x1, float &x2) {
	if (pow(b,2)-4*a*c > 0) {
    cout << fixed << setprecision(2);
	cout << "x1 = " << (b*-1 -1*pow(pow(b,2)-4*a*c,1.0/2.0))/(2.0*a) << endl; 
	cout << "x2 = " << (b*-1 +pow(pow(b,2)-4*a*c,1.0/2.0))/(2.0*a) << endl; 
	}
	else if (pow(b,2)-4*a*c == 0) {
	cout << "x = " << (-b +pow(pow(b,2)-4*a*c,1.0/2.0))/2.0*a << endl;	
	}
	else if (pow(b,2)-4*a*c < 0) {
     cout << "Nao ha raizes reais" << endl; 
	}
	return 0;
	}
	
int main () {
	
	float A, B, C; 
	float X1, X2; 
	cin >> A >> B >> C; 
    calc_raizes(A,B,C,X1,X2); 
	return 0; 
	
}
