#include <stdio.h>

float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b); 
float division(float a, float b); 
float IngresarValor();

int main (int argc, char *argv[]) {

    float x, y, s; 
    int opc = 0;
    printf("Calculadora\n");
    printf("Seleccione la opcion:\n"); 
    printf("1. Suma\n"); 
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf(">> "); 
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        printf("Ingrese el num1: \n");
        x = IngresarValor(); 
        printf("Ingrese el num2: \n");
        y = IngresarValor(); 
        s = suma(x, y);
        printf("La suma es: %.2f\n", s);
        break;

    case 2:
        printf("Ingrese el num1: \n");
        x = IngresarValor(); 
        printf("Ingrese el num2: \n");
        y = IngresarValor(); 
        s = resta(x, y);
        printf("La resta es: %.2f\n", s);
        break;

    case 3:
        printf("Ingrese el num1: \n");
        x = IngresarValor(); 
        printf("Ingrese el num2: \n");
        y = IngresarValor(); 
        s = multiplicacion(x, y);
        printf("La multiplicacion es: %.2f\n", s);
        break;

    case 4:
        printf("Ingrese el num1: \n");
        x = IngresarValor(); 
        printf("Ingrese el num2: \n");
        y = IngresarValor(); 
        s = division(x, y);
        printf("La division es: %.2f\n", s);
        break;

    default:
        printf("No es una opcion valida"); 
        break;
    }
    return 0;
}

// FUNCIONES  -  EJEMPLOS
float IngresarValor(){
    float a = 0;
    int val = 0;
    do
    {
        fflush(stdin); 
        val = scanf("%f", &a);
        if (val != 1)
        {
            printf("El valor ingresado es incorrecto, Ingrese nuevamente.\n");
        }
    } while (val != 1);
    return a;
}

float suma(float a, float b) // SUMA
{
    float suma;
    suma = a + b;
    return suma;
}
float resta(float a, float b) // RESTA
{
    float res;
    res = a - b;
    return res;
}
float multiplicacion(float a, float b) // MULTIPLICACIÓN
{
    float res;
    res = a * b;
    return res;
}
float division(float a, float b) // DIVISIÓN
{
    float res;
    if (b != 0)
    {
        res = a / b;
    }else
    {
        printf("No se puede dividir para cero.\n");
        res = 0;
    }
    return res;
}
