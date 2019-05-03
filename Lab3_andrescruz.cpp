#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int mcd(int,int);
void ejercicio1();
void ejercicio2();
bool prim(int);
int* calculadoraPrimos();
void elimApunt(int*);
void ejercicio3();
void imprimirBonito(string);

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
			ejercicio3();		
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

void ejercicio3(){
	vector<string> guerras;
	vector<string> codigos;
	vector<string> continentes;
	int opcm=0;
	while(opcm!=5){
		cout<<"Menu Guerras"<<endl
			<<"1. Insertar Guerra"<<endl
			<<"2. Buscar Guerra"<<endl
			<<"3. Eliminar Guerra"<<endl
			<<"4. Listar Guerras"<<endl
			<<"5. Regresar al menu principal. "<<endl
			<<"Ingrese una opcion: "<<endl;
		cin>>opcm;
		if(opcm==1){
			stringstream datos;
			string cod,nom,inicio,fin,paises,continente;
			cout<<"Ingrese el codigo de guerra: "<<endl;
			cin>>cod;
			cout<<"Ingrese el nombre de la guerra: "<<endl;
			getline(cin,nom);
			getline(cin,nom);
			cout<<"Ingrese el año de inicio: "<<endl;
			cin>>inicio;
			cout<<"Ingrese el año en que finalizo: "<<endl;
			cin>>fin;
			cout<<"Ingrese los paises que participaron en la guerra"<<endl
				<<"separados unicamente por comas: "<<endl;
			getline(cin,paises);
			getline(cin,paises);
			cout<<"Ingrese el nombre del continente en el que ocurrio la guerra: "<<endl;
			cin>> continente;
			datos<<cod<<";"<<nom<<";"<<inicio<<";"<<fin<<";"<<paises<<";"<<continente;
			string guerra=datos.str();
			guerras.push_back(guerra);
			codigos.push_back(cod);
			continentes.push_back(continente);
			cout<<"Se agrego de manera exitosa la informacion de la guerra!"<<endl;
		}
		if(opcm==2){
			string cod;
			cout<<"Ingrese el codigo de la guerra que desea buscar: "<<endl;
			cin>> cod;
			int pos=-1;
			for(int i=0;i<codigos.size();i++){
				if(cod==codigos.at(i)){
					pos=i;	
				}
			}
			if(pos<0){
				cout<<"No existe una guerra con este codigo. "<<endl;				
			}else{
				imprimirBonito(guerras.at(pos));
			}
		}
		if(opcm==3){
			string cod;
			cout<<"Ingrese el codigo de la guerra que desea eliminar: "<<endl;
                        cin>> cod;
                        int pos=-1;
                        for(int i=0;i<codigos.size();i++){
                                if(cod==codigos.at(i)){
                                        pos=i;
                                }
                        }
                        if(pos<0){
                                cout<<"No existe una guerra con este codigo. "<<endl;
                        }else{
                                guerras.erase(guerras.begin()+pos);
				codigos.erase(codigos.begin()+pos);
				continentes.erase(continentes.begin()+pos);
				cout<<"Se elimino la guerra con exito. "<<endl;
                        }

		}
		if(opcm==4){
			int opclist=0;
			cout<<"Opciones Lista"<<endl
				<<"1. Listar todo"<<endl
				<<"2. Listar por continente"<<endl
				<<"Ingrese una opcion: "<<endl;
			cin>>opclist;
/*			while(opclist!=1||opclist!=2){
				cout<<"Opciones Lista"<<endl
                                <<"1. Listar todo"<<endl
                                <<"2. Listar por continente"<<endl
                                <<"Ingrese una opcion en el rango: "<<endl;
	                        cin>>opclist;
			}*/
			if(opclist==1){
				for(int i=0;i<guerras.size();i++){
                	                cout<<"Posicion #"<<i<<" : ";
        	                        imprimirBonito(guerras.at(i));
	                        }
				if(guerras.empty()){
					cout<<"No existen guerras. "<<endl;
				}
			}
			if(opclist==2){
				vector<int>posiciones;
				string continente;
				cout<<"Ingrese el continente para hacer la lista: "<<endl;
				cin>> continente;
				for(int i=0;i<continentes.size();i++){
					if(continente==continentes.at(i)){
						posiciones.push_back(i);
					}
				}
				if(posiciones.empty()){
					cout<<"NO hay guerras en el continente. "<<endl;
				}else{
					for(int i=0;i<posiciones.size();i++){
						cout<<"Posicion #"<<i<<" : ";
						imprimirBonito(guerras.at(posiciones.at(i)));
					}
				}
			}
		}
	}
}

void imprimirBonito(string guerra){
	stringstream palabra;
	vector<string> palabras;
	for(int i=0;i<guerra.length();i++){
			if(guerra[i]==';'||guerra[i]==','){
				palabras.push_back(palabra.str());
				palabra.str("");
			}else{
				palabra<<guerra[i];
			}
			if(i==guerra.length()-1){
				palabras.push_back(palabra.str());
                                palabra.str("");
			}
			
	}
	cout<<palabras.at(1)<<" llevada a cabo entre "<<palabras.at(2)<<" y "<<palabras.at(3)<<" donde participaron ";
	for(int i=4;i<palabras.size()-1;i++){
		if(i==palabras.size()-2){
			cout<<" y "<<palabras.at(i);
		}else{
			cout<<palabras.at(i);
		}
		if(i!=palabras.size()-3){
			cout<<" , ";
		}
	}
	cout<<" en el continente de "<<palabras.at(palabras.size()-1)<<endl;
}
