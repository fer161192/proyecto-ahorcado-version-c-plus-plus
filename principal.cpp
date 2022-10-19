#include <iostream>
#include <string>
#include "ahorcado.h"
using namespace std;
int main()
{
	char caracter_ingresado;
	int opcion,cantidad_letras;
	string palabra_ingresada,respuesta;
	respuesta = "si";
	while (respuesta == "si")
	{
		cout<<"Ingrese la palabra a cargar: "<<endl;
		cin>>palabra_ingresada;
		cantidad_letras = palabra_ingresada.size();
		Ahorcado objeto_ahorcado(palabra_ingresada,cantidad_letras);
		while (objeto_ahorcado.partidaTerminada() == false)
		{
			cout<<"Ingrese una de las opciones: "<<endl;
			cout<<"1: Arriesgar una letra."<<endl;
			cout<<"2: Arriesgar la palabra entera. En esta opcion se decide si gana o pierde la partida. "<<endl;
			cin>>opcion;
			switch(opcion)
			{
				case 1:
					cout<<"Ingrese la letra a arriesgar: "<<endl;
					cin>>caracter_ingresado;
					objeto_ahorcado.arriesgar(caracter_ingresado);
					break;
				case 2:
					cout<<"Ingrese la palabra a arriesgar: "<<endl;
					cin>>palabra_ingresada;
					objeto_ahorcado.arriesgar(palabra_ingresada);
					break;
				default:
					cout<<"Opcion incorrecta!"<<endl;
					cout<<"Reingrese nuevamente."<<endl;
			}
		}
		cout<<"Desea volver a jugar? (si/no): "<<endl;
		cin>>respuesta;
	}
	cout<<"Fin del programa. Adios!"<<endl;
	return(0);
}
