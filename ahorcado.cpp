#include <iostream>
#include <string>
#include "ahorcado.h"
Ahorcado::Ahorcado(string palabra_ingresada,int cantidad)
{
	this->cantidad_desaciertos = 0;
	this->cantidad_letras = cantidad;
	this->catidad_intentos = 7;
	this->palabra = palabra_ingresada;
	this->vector_adivinar_palabra = new char[this->cantidad_letras];
	this->vector_letras_invalidas = new char[this->catidad_intentos];
	cout<<"Se construye el vector que esta en "<<this<<endl;
	cargarMatrizGrafica();
	cargarVectorPalabra();
	cargarVectorLetrasInvalidas();
	cout<<"Inicialmente se encuentra de esta forma: "<<endl;
	mostrarPalabra();
	cout<<"Inicialmente la horca se encuentra de esta forma: "<<endl;
	mostrarMatrizGrafica();
}
void  Ahorcado::arriesgar(char caracter_ingresado)
{
	if (letraAcertada(caracter_ingresado) == false)
	{
		this->catidad_intentos--;
		this->cantidad_desaciertos++;
		insertarParteDelCuerpo();
		insertarLetraEquivocada(this->cantidad_desaciertos - 1,caracter_ingresado);
	}
	cout<<"Actualmente la palabra tiene esta forma: "<<endl;
	mostrarPalabra();
	cout<<"Actualmente la horca tiene esta forma: "<<endl;
	mostrarMatrizGrafica();
	mostrarVectorLetrasInvalidas();
	cout<<"Te quedan "<<this->catidad_intentos<<" intentos."<<endl;
	if (this->catidad_intentos == 0)
		juegoFinalizado(false);
	if (totalLetrasAcertadas() == true)
		juegoFinalizado(true);
}
void Ahorcado::arriesgar(string palabra_ingresada)
{
	bool ganaste;
	if (this->palabra == palabra_ingresada)
	{
		insertarPalabraCompleta(palabra_ingresada);
		ganaste = true;
	}
	else
	{
		insertarCuerpoCompleto();
		ganaste = false;
	}
	mostrarPalabra();
	mostrarMatrizGrafica();
	juegoFinalizado(ganaste);
}
bool Ahorcado::partidaTerminada()
{
	bool terminado;
	terminado = false;
	if (this->catidad_intentos == 0)
		terminado = true;
	if (totalLetrasAcertadas() == true)
		terminado = true;
	if (muniecoCompleto() == true)
		terminado = true;
	return(terminado);
}
Ahorcado::~Ahorcado()
{
	cout<<"Se destruira el vector que esta en "<<this<<endl;
	if (this->cantidad_letras>0)
		delete[]this->vector_adivinar_palabra;
	delete[]this->vector_letras_invalidas;
}
void Ahorcado::cargarMatrizGrafica()
{
	for (int i = 0;i<5;i++)
	{
		for (int j = 0;j<5;j++)
			matriz_grafica[i][j] = ' ';
	}
	matriz_grafica[0][1] = '-';
	for (int i = 0;i<5;i++)
	{
		if (i == 0)
			matriz_grafica[i][0] = '*';
		else
		{
			if (i == 4)
				matriz_grafica[i][0] = '-';
			else
				matriz_grafica[i][0] = '|';
		}
	}
}
void Ahorcado::cargarVectorPalabra()
{
	for (int i = 0;i<this->cantidad_letras;i++)
		vector_adivinar_palabra[i] = '-';
}
void Ahorcado::cargarVectorLetrasInvalidas()
{
	for (int i = 0;i<7;i++)
		this->vector_letras_invalidas[i] = ' ';
}
void Ahorcado::mostrarMatrizGrafica()
{
	for (int i = 0;i<5;i++)
	{
		for (int j = 0;j<5;j++)
			cout<<this->matriz_grafica[i][j];
	    cout<<endl;
	}
}
void Ahorcado::mostrarPalabra()
{
	for (int i = 0;i<this->cantidad_letras;i++)
		cout<<this->vector_adivinar_palabra[i]<<" ";
	cout<<endl;
}
void Ahorcado::mostrarVectorLetrasInvalidas()
{
	cout<<"Las invalidas ingresadas son: "<<endl;
	for (int i = 0;i<7;i++)
		cout<<this->vector_letras_invalidas[i]<<" ";
	cout<<endl;
}
void Ahorcado::insertarLetraEquivocada(int pos,char caracter_ingresado)
{
	this->vector_letras_invalidas[pos] = caracter_ingresado;
}
void Ahorcado::insertarParteDelCuerpo()
{
	if (parteCentralDelCuerpoCompleta() == false)
		insertarParteDelCuerpoCentro();
	else
	{
		if (parteIzquierdaVacia() == true)
			insertarParteDelCuerpoLateral(1,1,'/');
		else
			insertarParteDelCuerpoLateral(1,3,'\134');

	}
}
void Ahorcado::insertarParteDelCuerpoLateral(int aux_fila,int aux_columna,char caracter)
{
	if (this->matriz_grafica[aux_fila][aux_columna] == ' ')
		this->matriz_grafica[aux_fila][aux_columna] = caracter;
	else
	{
		int aux;
		aux = aux_fila + 2;
		this->matriz_grafica[aux][aux_columna] = caracter;
	}
}
void Ahorcado::insertarParteDelCuerpoCentro()
{
	if (this->matriz_grafica[0][2] == ' ')
		this->matriz_grafica[0][2] = 'O';
	else
	{
		if (this->matriz_grafica[1][2] == ' ')
			this->matriz_grafica[1][2] = '|';
		else
			this->matriz_grafica[2][2] = '|';
	}
}
bool Ahorcado::parteCentralDelCuerpoCompleta()
{
	bool central_completo;
	if (this->matriz_grafica[2][2] == '|')
		central_completo = true;
	else
		central_completo = false;
	return(central_completo);
}
bool Ahorcado::parteIzquierdaVacia()
{
	bool izquierda_vacia;
	if (this->matriz_grafica[3][1] == ' ')
		izquierda_vacia = true;
	else
		izquierda_vacia = false;
	return(izquierda_vacia);
}
bool Ahorcado::letraAcertada(char caracter_ingresado)
{
	bool letra_valida;
	letra_valida = false;
	for (unsigned int i = 0;i<this->palabra.size();i++)
	{
		if (caracter_ingresado == this->palabra[i])
		{
			this->vector_adivinar_palabra[i] = this->palabra[i];
			letra_valida = true;
		}
	}
	return(letra_valida);
}
bool Ahorcado::totalLetrasAcertadas()
{
	bool palabra_acertada;
	palabra_acertada = true;
	for (int i = 0;i<this->cantidad_letras;i++)
	{
		if (this->vector_adivinar_palabra[i] == '-')
			palabra_acertada = false;
	}
	return(palabra_acertada);
}
bool Ahorcado::muniecoCompleto()
{
	bool completo;
	completo = false;
	if (matriz_grafica[3][3] == '\134')
		completo = true;
	return(completo);
}
void Ahorcado::insertarCuerpoCompleto()
{
	 this->matriz_grafica[0][2] = 'O';
	 this->matriz_grafica[1][2] = '|';
	 this->matriz_grafica[1][1] = '/';
	 this->matriz_grafica[1][3] = '\134';
	 this->matriz_grafica[2][2] = '|';
	 this->matriz_grafica[3][1] = '/';
	 this->matriz_grafica[3][3] = '\134';
}
void Ahorcado::insertarPalabraCompleta(string palabra_ingresada)
{
	for(unsigned int i = 0;i<palabra_ingresada.size();i++)
		this->vector_adivinar_palabra[i] = palabra_ingresada[i];
}
void Ahorcado::juegoFinalizado(bool victoria)
{
	if (victoria == true)
		cout<<"Fin del juego. Haz ganado!"<<endl;
	else
	{
		cout<<"Fin del juego. Perdiste!"<<endl;
		cout<<"La palabra correcta es: "<<this->palabra<<endl;
	}
}
