#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double factorial(int n) {
double fact = 1.0;
for (int i = 1; i <= n; i++) {
fact *= i;
}
return fact;
}
double maclaurin_exp_con_tabla(double x, double error_limite) {
double suma = 1.0;        // Primer término: x^0 / 0! = 1
double termino = 1.0;
double suma_anterior;
double error_aproximado = 100.0;
int n = 1;