#include<iostream> 
#include<iomanip> 
using namespace std; 

// fun para fazer a media das notas dos alunos
float media (int notas[], int nAlunos) {
	
	float media=0; // var para calcular a media dos alunos
	int i; // contador para a passagem das notas
	for (i=0;i<nAlunos;i++) {
		media=media+notas[i]; 
	}
	return 1.0*media/nAlunos; 

}

// fun para ver quantos alunos acima da media
int nAcima(int notas[], int nAlunos, float media) {
	
	int i;// contador para o for
	int acima=0; // contador de quantos alunos acima da media
	for (i=0;i<nAlunos;i++) {
		if(notas[i]>media) {
			acima++;
		}
	}
	return acima; 
	
}

// fun para ver quantos alunos abaixo da media
int nAbaixo(int notas[], int nAlunos, float media) {
	
	int i;// contador para o for
	int abaixo=0; // contador de quantos alunos acima da media
	for (i=0;i<nAlunos;i++) {
		if(notas[i]<media) {
			abaixo++;
		}
	}
	return abaixo; 
	
}

int main () {
	
	int nota[100]; // vetor para receber as notas dos alunos
	int total; // quantidade total de alunos
	cin >> total; 
	int i; // contador para inserir nota dos alunos
	for (i=0; i<total; i++) {
		cin >> nota[i]; 
	}
	float res=media(nota,total); 
	cout << fixed << setprecision(2); 
	cout << "Media da turma = " << res << endl; 
	cout << "Alunos com nota abaixo da media: " << nAbaixo(nota,total,res) << endl; 
	cout << "Alunos com nota acima da media: " << nAcima(nota,total,res) << endl;
	return 0; 
}
