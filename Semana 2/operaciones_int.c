#include <stdio.h>
#include <math.h>
int main(){
int a;
int b;
int c;
int d;
a=3;
b=4;
c=5;
d=7;
int e;
printf("e=%d",(a+b)*c/d);
printf("e=%d",((a+b)*c)/d);
printf("e=%d",a+b*c/d);
printf("e=%d",(a+(b*c)/d));
}