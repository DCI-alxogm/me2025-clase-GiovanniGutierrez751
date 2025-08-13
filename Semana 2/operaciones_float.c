#include <stdio.h>
#include <math.h>
int main(){
float a;
float b;
float c;
float d;
a=3;
b=4;
c=5;
d=7;
float e;
printf("e=%f",(a+b)*c/d);
printf("e=%f",((a+b)*c)/d);
printf("e=%f",a+b*c/d);
printf("e=%f",(a+(b*c)/d));
}