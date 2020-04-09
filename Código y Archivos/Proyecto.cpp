#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
class Tienda{
	private:
	public:
		void crear();
		void leer();
		void annadir();
		void catalogo();	
};


using namespace std;

int main(){
	Tienda tienda1;
	int numero;
	do{
		cout << "******************* BLOC DE NOTAS *********************" << endl;
		cout << " 1.- Crear una nueva lista" << endl;
		cout << " 2.- Annadir cliente a una lista" << endl;
		cout << " 3.- Leer una lista" << endl;
		cout << " 4.- Mostrar catalogo" << endl;
		cout << " 5.- Salir." << endl;
		cout << "Selecciona una opcion: ";
		cout << "******************************************************" << endl;
		cin >> numero;
		cin.ignore(256,'\n');
		
		switch(numero){
			
			case 1: tienda1.crear();
			 	break;
			case 2: tienda1.annadir();
				break;
			case 3: tienda1.leer();
				break;
			case 4: tienda1.catalogo();
				break;
			case 5: cout << "Vuelva pronto!" << endl;
				break;
			default:cout << "\n Esa opcion no esta en el menu! \n";
				break;
		}
	} while (numero!=5);
	system ("pause");
	return 0;
}	
void Tienda::crear(){
	ofstream archivo;
	string nombreArchivo;
	string linea;
	
	cout<<"Nombre de la lista que quieres crear: ";
	getline(cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::out);
	if(archivo.fail()){
		cout<<"No puede abrir la lista";
		exit(1);
	}
	archivo.close();
	}
	void Tienda::leer(){
		ifstream archivo;
		string nombreArchivo;
		string linea;
		
		cout<<"Nombre de la lista que quieres leer: ";
		getline(cin, nombreArchivo);
		archivo.open(nombreArchivo.c_str(), ios::in);
		
		if(archivo.fail()){
			cout<<"No pude abrir la lista";
			exit(1);
		}
		while(!archivo.eof()){
			getline(archivo, linea);
			cout<<linea<<endl;
		}
		archivo.close();
	}
	void Tienda::catalogo(){
		ifstream archivo("catalogo");
		string linea;
		
		if(archivo.fail()){
			cout<<"No pude abrir la lista";
			exit(1);
		}
		while(!archivo.eof()){
			getline(archivo, linea);
			cout<<linea<<endl;
		}
		archivo.close();
	}
	
	void Tienda::annadir(){
		
		ofstream archivo;
		string nombreArchivo;
		string linea;
		
		cout << "Nombre de la lista a modificar: ";
		getline(cin,nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);
		
		if(archivo.fail()){
			cout << "No pude abrir la lista";
			exit(1);
		}
		archivo << "- - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;
		cout <<  "Nombre del cliente: ";
		getline(cin,linea);
		archivo<< "[" << linea<< "]" << endl;
		cout << "Descripción de la compra: ";
		getline(cin,linea);
		archivo<<linea<<endl;
		cout << "Precio total: ";
		getline(cin,linea);
		archivo<<linea<<endl;
		archivo << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		archivo.close();
		
	}


