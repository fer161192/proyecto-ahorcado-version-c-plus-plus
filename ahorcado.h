#ifndef AHORCADO_H_
#define AHORCADO_H_
#include <string>
using namespace std;
using std::string;
class Ahorcado
{
private:
	int cantidad_desaciertos;
	int cantidad_letras;
	int catidad_intentos;
	string palabra;
	char* vector_adivinar_palabra;
	char* vector_letras_invalidas;
	char matriz_grafica[5][5];
public:
	/*Pre: Se ingresa una palabra y su cantidad de letras.
	 *Post: Inicializa todos los atributos, carga los vectores y las matrices.
	 */
	Ahorcado(string palabra_ingresada,int cantidad);
	/*Pre: El ahorcado debe existir. Caracter ingresado para adivinar.
	 *Post:  Si no se inserta un caracter correcto se modifican los enteros cantidad_desaciertos
	 *y catidad_intentos,inserta un caracter en la matriz matriz_grafica,se inserta un caracter en el
	 *vector vector_letras_invalidas por cada jugada Se imprime la matriz matriz grafica,
	 *se imprime por pantalla los elementos del vector vector_adivinar_palabra e imprime por pantalla
	 *los elementos del vector vector_letras_invalidas. Finalmente se imprimira en pantalla.
	 */
	void  arriesgar(char caracter_ingresado);
	/*Pre: El ahorcado debe existir. Palabra a adivinar ingresada.
	 * Post: imprime por pantalla los elementos del vector vector_adivinar_palabra,
	 * se imprime por pantalla la matriz matriz_grafica y se llama al metodo juegoFinalizado
	 * que informa si el jugador gano o perdio y la palabra correcta en caso de perder.
	 */
	void arriesgar(string palabra_ingresada);
	/*Pre: El ahorcado debe existir.
	 * Post: devuelve un booleano.
	 */
	bool partidaTerminada();
	//pre: El ahorcado debe existir.
	//post: se destruyen los vectores vector_adivinar_palabra y
	//vector_letras_invalidas.
	~Ahorcado();
private:
	/*Pre: El ahorcado debe existir.
	 * Post: Inicialmente carga la matriz grafica.
	 */
	void cargarMatrizGrafica();
	/*Pre: El ahorcado debe existir.
	 * Post: carga el vector vector_adivinar_palabra.
	 */
	void cargarVectorPalabra();
	/*Pre: El ahorcado debe existir.
	 * Post: Carga el vector vector_letras_invalidas.
	 */
	void cargarVectorLetrasInvalidas();
	/*Pre: El ahorcado debe existir.
	 *Post: Muestra por pantalla el estado actual de la matriz matriz_grafica.
	 */
	void mostrarMatrizGrafica();
	/*Pre: El ahorcado debe existir.
	 *Post: Imprime por pantalla los elementos del vector vector_adivinar_palabra.
	 */
	void mostrarPalabra();
	/*Pre: El ahorcado debe existir.
	 *Post: Imprime por pantalla los elementos del vector vector_letras_invalidas.
	 */
	void mostrarVectorLetrasInvalidas();
	/*Pre: El ahorcado debe existir.
	 *Post: se inserta un caracter en el vector vector_letras_invalidas.
	 */
	void insertarLetraEquivocada(int pos,char caracter_ingresado);
	/*Pre: El ahorcado debe existir.
	 *Post: Inserta un caracter en la matriz matriz_grafica.
	 */
	void insertarParteDelCuerpo();
	/*Pre: El ahorcado debe existir. Recibe dos integer y un char.
	 *Post: inserta un caracter en la matriz matriz_grafica.
	 */
	void insertarParteDelCuerpoLateral(int aux_fila,int aux_columna,char caracter);
	/*Pre: El ahorcado debe existir.
	 *Post: inserta un caracter en la matriz matriz_grafica.
	 */
	void insertarParteDelCuerpoCentro();
	/*Pre: El ahorcado debe existir.
	 *Post: Devuelve un booleano que depende de que caracteres haya en la matriz matriz grafica.
	 */
	bool parteCentralDelCuerpoCompleta();
	/*Pre: El ahorcado debe existir.
	 *Post: devuelve un booleano que depende de que caracteres haya
	 *en la matriz matriz_grafica.
	 */
	bool parteIzquierdaVacia();
	/*Pre: El ahorcado debe existir. Recibe un caracter.
	 *Post: devuelve un booleano que depende de que caracteres haya
	 *en el vector vector_adivinar_palabra.
	 */
	bool letraAcertada(char caracter_ingresado);
	/*Pre: El ahorcado debe existir.
	 * Post: devuelve un booleano que depende de que caracteres
	 *haya en el vector vector_adivinar_palabra.
	 */
	bool totalLetrasAcertadas();
	/*Pre: El ahorcado debe existir.
	 * Post: Devuelve un booleano que depende
	 * de que caracteres haya en la matriz matriz_grafica.
	 */
	bool muniecoCompleto();
	 /*Pre: El ahorcado debe existir.
	  *Post: inserta elementos en la matriz matriz_grafica.
	  */
	void insertarCuerpoCompleto();
	/*Pre: El ahorcado debe existir y se ingresa un String.
	 *Post: Inserta la palabra completa en el vector vector_adivinar_palabra.
	 */
	void insertarPalabraCompleta(string palabra_ingresada);
	/*Pre: El ahorcado debe existir y se ingresa un booleano.
	 *Post: Se devuelve un booleano que informa si el jugador gano o perdio y
	 *la palabra correcta en caso de perder.
	 */
	void juegoFinalizado(bool victoria);
};
#endif /* AHORACADO_H_ */
