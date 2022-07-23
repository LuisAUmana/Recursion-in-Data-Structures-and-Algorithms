/*Luis Umana*/
#include <iostream>


using namespace std;

int numDigits(int num);
int pow10(int n);



int karatsuba(int x, int y) {
   int xLength = numDigits(x);
   int yLength = numDigits(y);

   // the bigger of the two lengths
   int L = xLength>yLength?xLength:yLength;

  
   if (L < 10)
       return x * y;

   //max length divided and rounded
   L = (L/2) + (L%2);

   int multi = pow10(L);

   int b = x/multi;
   int a = x - (b * multi);
   int d = y / multi;
   int c = y - (L);

   int u0 = karatsuba(a,c);
   int u1 = karatsuba(a + b, c + d);
   int u2 = karatsuba(b, d);


return u0 + ((u1 - u0 - u2) * multi) + (u2 * (int)(pow10( 2*L)));
    
}


int numDigits(int num) {
    int counter = 0;
   while (num != 0) {
       counter++;
       num /= 10;
   }
   return counter;
    
}


int pow10(int n) {
       int i=1;
   int value=1;
   while(i<=n){
       value = value*10;
   }
   return value;

}





