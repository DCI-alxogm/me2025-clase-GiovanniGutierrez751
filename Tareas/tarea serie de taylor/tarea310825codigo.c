#include <stdio.h>
#include <math.h>


double factorial(int n) {
    if (n <= 1) return 1.0;
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


double potencia(double base, int exponente) {
    if (exponente == 0) return 1.0;
    double resultado = 1.0;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}


double taylor_exp(double x, int n_terminos) {
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
        
        double derivada_n = 1.0; 
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

//Aproximación de sen(x) usando serie de Taylor
double taylor_sin(double x, int n_terminos) {
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
        
        double derivada_n;
        switch (n % 4) {
            case 0: derivada_n = 0.0; break;    
            case 2: derivada_n = 0.0; break;    
            case 3: derivada_n = -1.0; break;   
            case 1: derivada_n = 1.0; break;    
        }
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

//Aproximación de cos(x) usando serie de Taylor
double taylor_cos(double x, int n_terminos) {
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
       
        double derivada_n;
        switch (n % 4) {
            case 0: derivada_n = 1.0; break;    
            case 1: derivada_n = 0.0; break;   
            case 2: derivada_n = -1.0; break;  
            case 3: derivada_n = 0.0; break;   
        }
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

// Aproximación de ln(1+x) usando serie de Taylor
double taylor_ln(double x, int n_terminos) {
    if (x <= -1.0 || x > 1.0) {
        printf("Error: x debe estar en (-1, 1] para ln(1+x)\n");
        return 0.0;
    }
    
    double suma = 0.0;
    for (int n = 1; n <= n_terminos; n++) {
        
        double signo = (n % 2 == 0) ? -1.0 : 1.0;
        double derivada_n = signo * factorial(n - 1);
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

// Aproximación de arctan(x) usando serie de Taylor
double taylor_arctan(double x, int n_terminos) {
    if (x < -1.0 || x > 1.0) {
        printf("Error: x debe estar en [-1, 1] para arctan(x)\n");
        return 0.0;
    }
    
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
        
        if (n % 2 == 1) { 
            int k = (n - 1) / 2;
            double signo = (k % 2 == 0) ? 1.0 : -1.0;
            double derivada_n = signo * factorial(2 * k);
            double termino = (derivada_n * potencia(x, n)) / factorial(n);
            suma += termino;
        }
    }
    return suma;
}

int main() {
    double x;
    int n_terminos;
    
    printf("=== APROXIMACION POR SERIE DE TAYLOR ===\n");
    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);
    printf("Ingrese el numero de terminos: ");
    scanf("%d", &n_terminos);
    
    printf("\n--- Resultados ---\n");
    
    // e^x
    double aprox_exp = taylor_exp(x, n_terminos);
    double real_exp = exp(x);
    printf("e^(%.2f):\n", x);
    printf("  Aproximado: %.8f\n", aprox_exp);
    printf("  Real:       %.8f\n", real_exp);
    printf("  Error:      %.8f\n", fabs(aprox_exp - real_exp));
    
    // sin(x)
    double aprox_sin = taylor_sin(x, n_terminos);
    double real_sin = sin(x);
    printf("\nsin(%.2f):\n", x);
    printf("  Aproximado: %.8f\n", aprox_sin);
    printf("  Real:       %.8f\n", real_sin);
    printf("  Error:      %.8f\n", fabs(aprox_sin - real_sin));
    
    // cos(x)
    double aprox_cos = taylor_cos(x, n_terminos);
    double real_cos = cos(x);
    printf("\ncos(%.2f):\n", x);
    printf("  Aproximado: %.8f\n", aprox_cos);
    printf("  Real:       %.8f\n", real_cos);
    printf("  Error:      %.8f\n", fabs(aprox_cos - real_cos));
    
    // ln(1+x)
    if (x > -1.0 && x <= 1.0) {
        double aprox_ln = taylor_ln(x, n_terminos);
        double real_ln = log(1 + x);
        printf("\nln(1+%.2f):\n", x);
        printf("  Aproximado: %.8f\n", aprox_ln);
        printf("  Real:       %.8f\n", real_ln);
        printf("  Error:      %.8f\n", fabs(aprox_ln - real_ln));
    }
    
    // arctan(x)
    if (x >= -1.0 && x <= 1.0) {
        double aprox_arctan = taylor_arctan(x, n_terminos);
        double real_arctan = atan(x);
        printf("\narctan(%.2f):\n", x);
        printf("  Aproximado: %.8f\n", aprox_arctan);
        printf("  Real:       %.8f\n", real_arctan);
        printf("  Error:      %.8f\n", fabs(aprox_arctan - real_arctan));
    }
    
    return 0;
}
