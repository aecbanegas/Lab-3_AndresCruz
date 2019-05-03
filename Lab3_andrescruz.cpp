#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int mcd(int,int);
void ejercicio1();
void ejercicio2();
bool prim(int);
int* calculadoraPrimos();
void elimApunt(int*);

int main(){
	int opcm=0;
	while(opcm!=4){
		cout<<"Menu"<<endl
			<<"1. MCD"<<endl
			<<"2. Factorización"<<endl
			<<"3. Guerras"<<endl
			<<"4. Salir"<<endl
			<<"Ingrese una opcion: "<<endl;
		cin>>opcm;
		if(opcm==1){
			ejercicio1();
		}
		if(opcm==2){
			ejercicio2();	
		}
		if(opcm==3){
		
		}
	}
	return 0;
}

int mcd(int a,int b){
	if(a%b==0){
		return b;
	}else{
		mcd(b,a%b);
	}//fin if
}

void ejercicio1(){
	int a,b;
	cout<<"Ingrese el primer numero: "<<endl;
	cin>>a;
	while(a<=1){
		cout<<"Ingrese el primer numero tiene que ser positivo y mayor a 1: "<<endl;
        	cin>>a;
	}//fin while
	cout<<"Ingrese el segundo numero: "<<endl;
        cin>>b;
	while(b<=0||b>a){
	        cout<<"Ingrese el segundo numero tiene que ser positivo y menor al primer numero: "<<endl;
        	cin>>a;
        }//fin while
	cout<<"El maximo comun multiplo es: "<<mcd(a,b)<<endl;
}

void ejercicio2(){
	int* numprimos=calculadoraPrimos();
	int numero;
	stringstream fact;
	cout<<"Ingrese un numero positivo para encontrar sus factores: "<<endl;
	cin>>numero;
	while(numero<=1){
		cout<<"Ingrese un numero positivo para encontrar sus factores y que sea mayor a 1: "<<endl;
	        cin>>numero;
	}
	int cont=0,exponente=0;;
	fact<<numero<<" = ";
	while(cont!=24){		
		if(numero%numprimos[cont]==0){
			numero=numero/numprimos[cont];
			exponente++;
		}else if(exponente!=0){
			fact<<"("<<numprimos[cont]<<"^"<<exponente<<")";
			cont++;
			exponente=0;
		}else{
			cont++;
		}
		if(numero==0){
			break;
		}
	}
	cout<<"Los factores del numero son: "<<endl<<fact.str()<<endl;
	elimApunt(numprimos);
}

int* calculadoraPrimos(){
	int* primos=new int[25];
	int nump=2,cont=0;
	bool esprim=false;
	while(cont!=24){
		if(prim(nump)){
			primos[cont]=nump;
			cont++;
			nump++;	
		}else{
			nump++;
		}	
	}
	return primos;
}

void elimApunt(int* arreglo){
	delete[] arreglo;
}

bool prim(int a){
	int cont=0;
	for(int i=1;i<=a;i++){
		if(a%i==0){
			cont++;
		}
	}
	if(cont==2){
		return true;
	}else{	
		return false;
	}
}
