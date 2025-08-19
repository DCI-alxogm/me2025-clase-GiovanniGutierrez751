#include <stdio.h>

int main() {
    int numero;
    char opcion;

    do {
        printf("Ingrese un número: ");
        scanf("%d", &numero);
        if (numero % 2 == 0) {
            printf("El número %d es PAR.\n", numero);
        } else {
            printf("El número %d es IMPAR.\n", numero);
        }

        printf("¿Desea ingresar otro número? (s/n): ");
        scanf(" %c", &opcion);

    } while (opcion == 's' || opcion == 'S');

    printf("Bye bye.\n");
    return 0;
}
