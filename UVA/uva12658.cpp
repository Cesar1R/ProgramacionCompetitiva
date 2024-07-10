/*
En este problema tenemos como entrada 6 lineas, que de
las ultimas 5  debemos de identificar los numeros
1, 2 y 3. La primer linea nos dice cuantos numeros identificaremos

Para identificar estos numeros lo haremos por medio de la relacion entre
las columnas, el problema indica que entre cada columna, que representa a uno de los
caracteres a identificar existe una columna de puros '.', que llamaremos vacia.

Utilizamos el segundo ciclo para identificar el numero, dependiendo de su entrada
en la fila 2 y 4 ya que en la 2 se diferencia el 1 del 2 y 3, mientras que en la
4 se diferencian  el 2 y 3. 

Notemos que si en la segunda fila el caracter de enmedio de la columna
esta marcado con un '*' entonces podemos elegir el numero 1, pues en el 2 y 3,
 estas casillas estan marcadas con un '.'.

Por otro lado, la fila cuarta fila, podemos confirmar si el numero que identificamos es
un 2 o un 3, ya que si el '*' se encuentra en la primer entrada de la fila, entonces
es un 2, por otro lado, si el '*' se encuentra hasta el final de la fila, tenemos un 3.
*/


#include<iostream>
#include<string>



int main() {

  int n;
  scanf("%d \n", &n);

  std::string filas [5];

  for(int i = 0; i < 5; i++)
    std::getline(std::cin, filas[i]);


  for(int i = 0; i < n; i++){
    if(filas[1][i *4 + 1] == '*') // .*.
      printf("%d", 1);
    else if(filas[3][i * 4] == '*') // *..
      printf("%d", 2);
    else // ..*
      printf("%d", 3);
  }

  printf("\n");


  return 0;
}
