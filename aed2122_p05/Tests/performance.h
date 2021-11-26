#ifndef PERFORMANCE_H_
#define PERFORMANCE_H_
#include <iostream>
#include <cstdlib>
#include "cycle.h"

using namespace std;

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a constant function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a variacao (+/-) aceitavel
 * @return true if corresponds to a constant function
 */
bool isConstant(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem verifica as diferencas entre cada elemento
	// bastando uma das diferencas ser superior ao intervalo
	// para nao considerar constante
	int primDif = 0; // para ser constante o valor de referencia da diferen�a entre elementos dever� ser zero
	//cout << "primDif = " << primDif << endl;
	int dif = 0;
	for (int i = 1; i < size; i++) {
		dif = (y_el[i] - y_el[i-1]);
		//cout << "dif = " << dif << endl;
		//cout << "primdif-var = " << primDif-var << "primdif+var = " << primDif+var << endl;
		if (dif<(primDif-var) || dif>primDif+var) return false;
	}
	return true;

/*
	// Esta abordagem usa o valor medio da leitura
	// e considera constante se estiver dentro do intervalo definido
	int primDif = 0; // para ser constante o valor de referencia da diferenca entre elementos devera ser zero
	cout << "primDif = " << primDif << endl;
	int soma = 0;
	int dif = 0;
	for (int i = 1; i < size; i++) {
		dif = (y_el[i] - y_el[i-1]);
		soma = soma + dif;
		cout << "dif = " << dif << endl;
		cout << "soma = " << soma << endl;
	}
	int media = soma/(size-1);
	cout << "media = " << soma/(size-1) << " primdif-var = " << primDif-var << " primdif+var = " << primDif+var << endl;
	return (media >= primDif-var && media <= primDif+var);
*/
}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a linear function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a variacao (+/-) aceitavel
 * @return true if corresponds to a linear function
 */
bool isLinear(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores medios

	// Para saber se ee linear, basta calcular as primeiras diferencas
	// entre elementos consecutivos, somar essas diferencas e dividir pelo numero
	// de elementos -1.
	// O resultado tera de estar dentro do intervalo pretendido

	// Primeiro, verificar se ee ou nao constante
	if (isConstant(y_el, size, var)) return false;
	// Agora que sabemos que nao ee constante
	int soma = 0;
	int primDif = y_el[1]-y_el[0];
	//cout << "primDif = " << primDif << endl;
	for (int i = 1; i < size; i++) {
		soma = soma + (y_el[i] - y_el[i-1]);
		//cout << "soma = " << soma << endl;
	}

	//
	int media = soma/(size-1);
	//cout << "media = " << soma/(size-1) << " primdif-var = " << primDif-var << " primdif+var = " << primDif+var << endl;
	return (media >= primDif-var && media <= primDif+var);
}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a quadratic function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a variacao (+/-) aceitavel
 * @return true if corresponds to a quadratic function
 */
bool isQuadratic(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores medios

	// Para saber se ee quadratica, primeiro garantir que nao ee constante nem linear.
	// Depois, Calcular as segundas diferencas entre elementos consecutivos, somar essas diferencas e dividir pelo numero
	// de elementos -2.
	// O resultado tera de ser igual a diferenca da primeira segunda-diferenca
	//
	//
	// Primeiro, verificar se ee ou nao constante (de notar que nao ee suficiente comparar com Linear, pois nao ser linear
	// pode significar que ee constante)
	if (isConstant(y_el, size, var)) return false;
	// Segundo, verificar se ee ou nao linear
	if (isLinear(y_el, size, var)) return false;
	// Criar um array para guardar os valores das primeiras diferencas
	int y_el_prim_dif[size-1];
	// Calcular as primeiras diferencas e guarda-las no array
	for (int i = 1; i < size; i++ ) {
		y_el_prim_dif[i-1] = (y_el[i] - y_el[i-1]);
	}
	// Agora calcular as segundas-diferencas
	int soma = 0;
	int primDif = y_el_prim_dif[1]-y_el_prim_dif[0];

	for (int i = 1; i < size-1; i++) {
		soma = soma + (y_el_prim_dif[i] - y_el_prim_dif[i-1]);
	}
	//
	int media = soma/(size-2);
	return (media >= primDif-var && media <= primDif+var);

}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to a cubic function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a variacao (+/-) aceitavel
 * @return true if corresponds to a cubic function
 */
bool isCubic(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores medios

	// Para saber se ee cubica, primeiro garantir que nao ee constante nem linear nem quadratica.
	// Depois, Calcular as terceiras diferencas entre elementos consecutivos, somar essas diferencas e dividir pelo numero
	// de elementos -3.
	// O resultado tera de ser igual a diferenca da primeira segunda-diferenca
	//
	//
	// Primeiro, verificar se e ou nao constante (de notar que nao ee suficiente comparar com Linear, pois nao ser linear
	// pode significar que ee constante)
	if (isConstant(y_el, size, var)) return false;
	// Segundo, verificar se ee ou nao linear
	if (isLinear(y_el, size, var)) return false;
	// Terceiro, verificar se ee ou nao quadratica
	if (isQuadratic(y_el, size, var)) return false;
	// Criar um array para guardar os valores das primeiras diferencas
	int y_el_prim_dif[size-1];
	// Calcular as primeiras diferencas e guarda-las no array
	for (int i = 1; i < size; i++ ) {
		y_el_prim_dif[i-1] = (y_el[i] - y_el[i-1]);
	}
	// Criar um array para guardar os valores das segundas diferencas
	int y_el_sec_dif[size-2];
	// Calcular as segundas diferencas e guarda-las no array
	for (int y = 1; y < size-1; y++ ) {
		y_el_sec_dif[y-1] = (y_el_prim_dif[y] - y_el_prim_dif[y-1]);
	}
	// Agora calcular as terceiras-diferencas
	int soma = 0;
	int primDif = y_el_sec_dif[1]-y_el_sec_dif[0];

	for (int z = 1; z < size-2; z++) {
		soma = soma + (y_el_sec_dif[z] - y_el_sec_dif[z-1]);
	}
	//
	int media = soma/(size-3);
	return (media >= primDif-var && media <= primDif+var);

}

/**
 * Function that returns true if a sequence of numbers
 * corresponds to an exponential function
 * @param y_el[] the array of ints to be considered
 * @param size the number of elements in the array
 * @param var a variacao (+/-) aceitavel
 * @return true if corresponds to an exponential function
 */
bool isExponential(const unsigned int y_el[], const int size, const int var) {

	// Esta abordagem usa os valores medios

	// Para saber se ee exponencial, basta calcular as primeiras divisoes
	// entre elementos consecutivos, somar essas diferencas e dividir pelo numero
	// de elementos -1.
	// O resultado tera de ser igual ao valor da primeira divisao

	int soma = 0;
	int primDiv = y_el[1]/y_el[0];
	for (int i = 1; i < size; i++) {
		soma = soma + (y_el[i] / y_el[i-1]);
	}
	//
	int media = soma/(size-1);
	return (media >= primDiv-var && media <= primDiv+var);
}

/**
 * Funcao para devolver a diferenca entre dois ticks
 * @param te  tick de fim
 * @param ts  tick de inicio
 * @return a diferenca
 */
unsigned int getElapsed(ticks te, ticks ts) {
	return ( (int)te - (int)ts )/1000;
}


#endif /* PERFORMANCE_H_ */
