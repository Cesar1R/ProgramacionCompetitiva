/*
Para este problema utilizamos el paradigma de programacion dinamica

En la tabla dp[i][j] guardamos la probabilidad de tener una racha de i juegos ganados
considerando que se han ganado j juegos. Utilizamos un arreglo auxiliar que nos permitira
saber la probabilidad de tener esa racha.

Tengamos en cuenta que la probabilidad de la interseccion de dos eventos
independientes esta dada por el producto de sus probabilidades, en este caso, todos
los juegos tienen la probabilidad p de ser ganados, en su defecto, ganar k juegos seguidos
o tener una racha de longitud k (i = k en la dp) tiene una probabilidad
de p^k.

Para llenar la dp, el caso base es dp[0][0] = 0. Por otro para llenar la tabla,
tenemos que dp[i][j] sera igual a la probabilidad de que en los mismos j juegos
se haya tenido una racha de i-1, aqui contemplamos el caso donde podemos *extender*
la racha.

Luego si i = j+1 quiere decir que la racha termina en el siguiente juego, es decir
estamos por terminar la racha. Asi que restamos la probabilidad de ganar j+1 juegos.

Por ultimo, si no vamos a perder el juego, ya que no hay empates, ganaremos, lo que nos
va a permitir extender la racha.

*/




#include<bits/stdc++.h>
using namespace std;

#define LIM 600


int main(){
  int n, i, j;
  double p, ans;

  double dp[LIM][LIM];
  double probas[LIM];

  while(cin >> n >> p && n != 0){
    probas[0]  = 1;
    dp[0][0] = 0; // racha de i juegos ganados de j jugados

    for (i = 0; i <= n; i++){
      dp[0][i] = 1;
      probas[i+1] = p*probas[i]; // Probabilidad acumulada de ganar i juegos
    }

    for(i =1; i <= n; i++){
      for(j = 0; j <= n; j++){
        dp[i][j] = dp[i-1][j];
        if( i == j + 1)  // si la racha es igual a j + 1 juegos
          dp[i][j]  -= probas[j+1];
        else if(i > j+1)
          dp[i][j] -= dp[i - j - 2][j] * (1-p)*probas[j+1];
      }
    }

    ans = 0;
  for(i = 1; i <= n;i++)
    ans += (dp[n][i] - dp[n][i-1]) * i;

    cout << fixed << setprecision(6) << ans << endl ;
  }

  return 0;
}
