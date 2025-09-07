/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
   float f1,r1,f2,r2,f3,r3;
  
    printf("introduzca un f(xi)\n");
scanf("%f",&f1);
  printf("introduzca el valor de f(%f)\n",f1);
scanf("%f",&r1);

     printf("introduzca un f(xi-1)\n");
scanf("%f",&f2);
  printf("introduzca el valor de f(%f)\n",f2);
scanf("%f",&r2);
   
    printf("introduzca un f(xi+1)\n");
scanf("%f",&f3);
  printf("introduzca el valor de f(%f)\n",f3);
scanf("%f",&r3);

float dc,da,dd;

dc=(r3-r2)/(f3-f2);
da=(r1-r2)/(f1-f2);
dd=(r3-r1)/(f3-f1);
 printf("la primera derivada central de f(%f) es %f\n",f1,dc);
 printf("la primera derivada hacia adelante de f(%f) es %f\n",f1,dd);
  printf("la primera derivada hacia atras de f(%f) es %f\n",f1,da);


    return 0;
}
