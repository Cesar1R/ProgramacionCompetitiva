/*--------Vecino racional-------------
Tengamos en cuenta que a/b < c/d <=> ad < cb, asi que vamos a modificar c y d cumplan
las condiciones de interes.

En este caso definimos c/d como la fraccion que nos interesa ajustar, por como definimos
c y d, en este caso, podemos garantizar que la distancia enter a/b y c/d es menor igual
que n. Esto nos asegura la condicion (ii).

Por otro lado, repetiremos el ciclo while hasta que se garantice la condicion (i).

Por ultimo la condicion (iii) de que d sea lo mas pequeño posible se garatiza por la
incializacion y actualizacion de c y d. En la declaracion de estas variables se hace
para obtener un numero que cumpla la condicion de de la distancia. Mientras que la actualizacion
hace que no utilicemos d inecesariamente grandes.  
*/


#include<bits/stdc++.h>

int main(){

	int a,b,c, d;

	long double n;

	std::cin >> a >> b >> n;

	d = ceil(1/(b*n));
	c = floor((a*d + b*d*n)/b);

	while (c*b <= a*d)
	{
		d++;
		c = floor((a*d + b*d*n)/b);
	}

	std::cout << c << " " <<  d << std::endl;
	return 0;
}
