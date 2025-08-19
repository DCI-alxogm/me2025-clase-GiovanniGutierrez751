#include <stdio.h>
#include <math.h>
int main (){

float a;
float b;
float c;
float x1;
float x2;
double discr;
printf("introduzca valores para a,b y c");
scanf("%f %f %f\n",&a,&b,&c);
if (a==0){
if (b==0){
printf("solución trivial");
}
}
else{
discr=(b*b)-4*(a*c);
}
if (discr>0){
x1=(b+sqrt(discr))/2*a;
x1=(b-sqrt(discr))/2*a;
}
else{
printf("Las raices son complejas");
}
printf("%f %f",x1,x2);
return 0;
}