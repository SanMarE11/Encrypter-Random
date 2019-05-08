#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
char frase[100];
string original;
int opc,longi,valor,encontrado;
struct origen{
	string original;
	string encriptado;
}originalito;
int encriptar(){
	system("cls");
	cout<<"\n\t Ingresa la frase a cifrar\n>";
	cin.ignore();
	cin.getline(frase,100);	
	longi=strlen(frase);
	fstream archivo;
	string file="Base.csv";
	archivo.open("Base.csv",ios::in);
	if(archivo.is_open()){
		while(!archivo.eof()){
			getline(archivo,originalito.original,',');
			getline(archivo,originalito.encriptado,'\n');
			if(originalito.original==frase){
				cout<<originalito.encriptado<<endl;
				encontrado=1;
			}
		}
		archivo.close();
	}
	if(encontrado==0){
		archivo.open("Base.csv",ios::app);
		if(!(archivo.is_open())){
			archivo.open(file.c_str(),ios::out);
			archivo.close();
			archivo.open("Base.csv",ios::app);
		}
		fflush(stdin);
		archivo<<frase<<",";
		for(int i=0;i<24;i+=2){
			valor=65+rand() % 25;
			frase[i]=valor;
			frase[i+1]=48+rand()%9;
			archivo<<frase[i]<<frase[i+1];
			cout<<frase[i]<<frase[i+1];
		}
		archivo<<"\n";
		archivo.close();
	}
	system("pause > null");
}
int desencriptar(){
	encontrado=0;
	system("cls");
	cout<<"\n\t Ingresa la frase a descifrar\n>";
	cin.ignore();
	cin.getline(frase,100);
	fstream archivo;
	archivo.open("Base.csv",ios::in);
	if(!(archivo.is_open())){
		system("cls");
		cout<<"\n\tNO EXISTE UNA BASE DE DATOS";
	}else{
		while(!archivo.eof()){
			getline(archivo,originalito.original,',');
			getline(archivo,originalito.encriptado,'\n');
			if(originalito.encriptado==frase){
				cout<<"La frase es: "<<originalito.original<<endl;
				system("pause > null");
				encontrado=1;
				break;
			}
		}
		if(encontrado==0){
			cout<<"No se encontro el texto";
		}
	}
	system("pause > null");
	archivo.close();
}
int main(){
	srand(time(0));
	system("cls");
	cout<<"\n\tBienvenido al crypter SanMarE"<<endl;
	cout<<"1.-Encriptar.\n2.-Desencriptar.\n3.-Salir. \n> ";
	if(!(cin>>opc)){
		cin.clear();
		cin.ignore();
		cout<<"Error";
		system("pause > null");
	}
	switch(opc){
		case 1:encriptar();break;
		case 2:desencriptar();break;
		case 3:return 0;break;
	}
	main();
}
