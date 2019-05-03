#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int mcd(int,int);
void ejercicio1();

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
