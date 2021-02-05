#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<char> letrasUnicas(string cadena) {
	vector<char> vector;
	//rellenamos nuestro vector
	for(int i=0; i < cadena.length(); i++) {
		vector.push_back(cadena[i]);
	}
	//iniciamos ambos for de manera inversa en modo a que no borre el primer caracter
	for(int i=vector.size()-1; i >=0; i--) {
		int auxiliar=0;
		for(int j=vector.size()-1; j>=0; j--) {
			if(vector.at(j)==cadena[i]) {
				auxiliar++;
			}
		}
		if(auxiliar != 1 ) {
			vector.erase(vector.begin()+i);
		}
	}
	return vector;
}
//funcion 2
int* CantidadLetras(vector <char> vector, string cadena) {
	int tamano = vector.size();
	//le asigno el tamaño del vector al arreglo del puntero
	int* CantidadCaracteres = new int[tamano];
	for(int i=0; i < vector.size(); i++) {
		int auxiliar=0;
		for(int j=0; j< cadena.length(); j++) {
			if(vector.at(i)==cadena[j]) {
				auxiliar++;
			}
		}
		CantidadCaracteres[i]=auxiliar;
	}
	return CantidadCaracteres;
	delete CantidadCaracteres;
}
//funcion3
int* Ordenamiento(int*numeros,int cantidad) {
	int* posiciones= new int[100];
	int posicion;
	int auxiliar2=0;
	int auxiliar3=0;
	for(int i=0; i < cantidad; i++) {
		int auxiliar=numeros[auxiliar3];
		for(int j=0; j < cantidad; j++) {
			auxiliar2=0;
			if(numeros[auxiliar2] <  auxiliar) {
				posicion++;
			}
			auxiliar2++;
		}
		auxiliar3++;
		posiciones[i]=posicion;
		posicion=0;
	}
	return posiciones;
}

int main() {
	int opcion=1;
	while(opcion != 5) {
		cout << "Menu" << endl
		     << "1. Letras Unicas  " << endl
		     << "2. Cantidad de letras en palabra " << endl
		     << "3. Ordenamiento "<< endl
		     << "4. Frecuencia de Letras "<<endl
		     << "5. Salir " << endl;
		cout << "Ingrese una opcion: " << endl;
		cin>>opcion;
		switch(opcion) {
			case 1: {
				string cadena;
				cout << "Ingrese la palabra: "<< endl;
				cin>>cadena;
				//creamos un vector y le asignamos el vector ya sin repetidos
				vector<char>VectorResultante=letrasUnicas(cadena);
				cout << "Palabra Resultante: ";
				//impresion del vector con el formato indicado
				cout<<"[";
				for(int i= 0; i < VectorResultante.size(); i++) {
					cout << VectorResultante.at(i);
				}
				cout<<"]"<<endl;
				break;
			}
			case 2: {
				string cadena = "";
				cout<<"Ingrese una cadena: ";
				cin>> cadena;
				cout<<endl;
				vector<char>VectorResultante=letrasUnicas(cadena);
				int*cantidad=CantidadLetras(VectorResultante,cadena);
				cout<<"Cantidad de letras: "<<endl;
				for(int i= 0; i < VectorResultante.size(); i++) {
					cout << cantidad[i]<<"";
				}
				cout<<endl;
				break;
			}
			case 3: {
				int numeros=0;
				int numeroi;
				cout<< "Ingrese la cantidad de numeros: "<<endl;
				cin>>numeros;
				int* _numeros;
				int* _numeros2;
				for(int i=0; i < numeros; i++){
					cout<<"Ingrese un numero: "<<endl;
					cin >> numeroi;
					_numeros[i]=numeroi;
				}
				_numeros2=Ordenamiento(_numeros,numeros);
				for(int i=0; i < numeros; i++){
					cout << "[" << _numeros2[i] << "]";
				}
				break;
			}
			case 4: {

				break;
			}
			case 5: {
				cout << "Gracias por usar el programa :)" << endl;
				break;
			}
			return 0;
		}
	}

}

