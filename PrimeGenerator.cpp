#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <math.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ b){
    ZZ r;
    r = a - b * (a / b);
    r = r + (r < 0) * b;
    return r;
    }

ZZ potenciacionbinariamodular(ZZ x, ZZ y, ZZ m) {
        ZZ respuesta; respuesta = 1;
        x = modulo(x, m);
        while (y > 0) {
            if (modulo(y,ZZ(2))==1) { respuesta = modulo(respuesta * x,m); }
            x = modulo(x * x,m);
            y = y>>1;
        }
        return respuesta;
}

bool witness(ZZ n, ZZ a)
{
   ZZ u, y, z, j, t;

   t = 1;
   u = n/2;
   while (u % 2 == 0) {
      t++;
      u /= 2;
   }

   z = potenciacionbinariamodular(a, u, n); // z = a^u % n
   if (z == 1) return 0;

   j = 0;
   do {
      y = z;
      z = (y*y) % n;
      j++;
   } while (j < t && z != 1);

   return z != 1 || y != n-1;
}

bool MillerRabin(ZZ n, ZZ s){
    ZZ a;

   for (int i = 0; i < s; i++) {
      a = RandomBnd(n);

      if (witness(n, a))
         return 0;
   }

   return 1;
}

ZZ PrimeCandidate(int bits){
    ZZ n, m;
    n = RandomBnd(bits);
    m = (pow(2, bits))+1;
    n = n | m;
    return n;
}

ZZ GeneratePrime(int bits){
    ZZ s, n;
    //cout<<"Elegir un valor para s: ";
    //cin>>s;
    s=ZZ(10);
    cout<<endl;
    n=PrimeCandidate(bits);
    while(MillerRabin(n,s)){
        n= n+2;
    }
    return n;
}

int main(){
    ZZ s = ZZ(4);
    cout << "Todos los primos de 3 cifras: \n";
    for (ZZ i = ZZ(100); i < 1000; i++)
       if (MillerRabin(i, s))
          cout << i << " ";

    cout<<endl;
    cout << "100 Primos diferentes: \n";
    for (int j = 1; j <= 100; j++)
        cout<<GeneratePrime(10)<< " ";
}

