#include <stdio.h>
#include <math.h>

// Función factorial
double factorial(int n) {
    if (n <= 1) return 1.0;
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Función potencia
double potencia(double base, int exponente) {
    if (exponente == 0) return 1.0;
    double resultado = 1.0;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

// 1. Aproximación de e^x usando serie de Taylor
double taylor_exp(double x, int n_terminos) {
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
        // f^(n)(a) = e^a, donde a = 0
        double derivada_n = 1.0; // e^0 = 1
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

// 2. Aproximación de sen(x) usando serie de Taylor
double taylor_sin(double x, int n_terminos) {
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
        // f^(n)(0) = sin(0 + n*π/2)
        double derivada_n;
        switch (n % 4) {
            case 0: derivada_n = 0.0; break;    // sin(0)
            case 1: derivada_n = 1.0; break;    // cos(0)
            case 2: derivada_n = 0.0; break;    // -sin(0)
            case 3: derivada_n = -1.0; break;   // -cos(0)
        }
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

// 3. Aproximación de cos(x) usando serie de Taylor
double taylor_cos(double x, int n_terminos) {
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
        // f^(n)(0) = cos(0 + n*π/2)
        double derivada_n;
        switch (n % 4) {
            case 0: derivada_n = 1.0; break;    // cos(0)
            case 1: derivada_n = 0.0; break;    // -sin(0)
            case 2: derivada_n = -1.0; break;   // -cos(0)
            case 3: derivada_n = 0.0; break;    // sin(0)
        }
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

// 4. Aproximación de ln(1+x) usando serie de Taylor
double taylor_ln(double x, int n_terminos) {
    if (x <= -1.0 || x > 1.0) {
        printf("Error: x debe estar en (-1, 1] para ln(1+x)\n");
        return 0.0;
    }
    
    double suma = 0.0;
    for (int n = 1; n <= n_terminos; n++) {
        // f^(n)(0) = (-1)^(n+1) * (n-1)!
        double signo = (n % 2 == 0) ? -1.0 : 1.0;
        double derivada_n = signo * factorial(n - 1);
        double termino = (derivada_n * potencia(x, n)) / factorial(n);
        suma += termino;
    }
    return suma;
}

// 5. Aproximación de arctan(x) usando serie de Taylor
double taylor_arctan(double x, int n_terminos) {
    if (x < -1.0 || x > 1.0) {
        printf("Error: x debe estar en [-1, 1] para arctan(x)\n");
        return 0.0;
    }
    
    double suma = 0.0;
    for (int n = 0; n < n_terminos; n++) {
        // f^(n)(0) = 0 para n par, (-1)^(k) * (2k)! para n = 2k+1
        if (n % 2 == 1) { // Solo términos impares
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