
/*
Para este problema se implemento la funcion que nos permite conoces el precio
al tiempo k, para k entero, luego calculamos los valores de para todo
k <= n, entero, en cada iteracion comparamos entre la diferencia que
teniamos guardada y la diferencia que nos daba el tiempo actual, de ser mayor, la guardabamos
en caso contrario, ademas, verificamos si el precio en el tiempo era un maximo.

*/


#include<bits/stdc++.h>

inline double price (int p, int a, int k, int b, int c, int d)
{
  return p * (sin( (double)(a * k + b)) + cos((double) (c * k + d)) + 2);
}

int main() {

  std::string s;
  while (getline(std::cin,s)){
    std::istringstream iss (s);
    int p, a, b, c, d, n;
    iss >> p >> a >> b >> c >> d >>  n;

    double max = price(p, a, 1, b, c, d),
          ans = 0,
          tmp;

    for(int i = 2; i <= n; i++){
        tmp = price(p, a, i, b, c, d);
        if (max > tmp)
          if(ans < max - tmp)
            ans = max - tmp;
        max = (max > tmp) ? max :tmp;
      }
    std::cout << std::fixed << std::setprecision(8) << ans << '\n';
  }



  return 0;
}
