
#include <stdio.h>
#include <math.h>


double f(double x) {
    return sin(10*x) - cos(3*x);
}

int main() {
    
    double a_initial = 3.0;
    double b_initial = 5.0;
    double error_deseado = 0.001;
    double subinterval_width = 0.1;
    

    double a, b, c, c_previo, error_relativo;
    int iteraciones;
    
    printf("Buscando raíces de f(x) = sin(10x) - cos(3x) en [3, 5]\n");
    printf("Con error relativo máximo: %.4f\n\n", error_deseado);
    
  
    int num_subintervalos = (int)((b_initial - a_initial) / subinterval_width);
    
    printf("Raíces encontradas:\n");
    printf("-------------------\n");
    

    for(int i = 0; i < num_subintervalos; i++) {
        a = a_initial + i * subinterval_width;
        b = a + subinterval_width;
        
       
        if(f(a) * f(b) < 0) {
            
            iteraciones = 0;
            error_relativo = 1.0;
            c_previo = a;
            
           
            while(error_relativo > error_deseado) {
                c = (a + b) / 2.0;
                
                
                if(f(a) * f(c) < 0) {
                    b = c;
                } else {
                    a = c;
                }
                
                
                if(iteraciones > 0) {
                    if(c != 0.0) {
                        error_relativo = fabs(c - c_previo) / fabs(c);
                    } else {
                        error_relativo = fabs(c - c_previo);
                    }
                }
                
                c_previo = c;
                iteraciones++;
            }
            
            printf("x = %.4f (en [%.1f, %.1f], %d iteraciones)\n", 
                  c, a_initial + i * subinterval_width, a_initial + (i+1) * subinterval_width, iteraciones);
        }
    }
    
    return 0;
}