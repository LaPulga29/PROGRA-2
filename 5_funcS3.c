#include <stdio.h>
#include <string.h>

int menu (); 
void ingresarNombre(char nombre[30], int i); 
void ingresarMaterias(char materia[30], int i); 
float ingresarNotasMateria(char nombre[30], char materia[30]);

int main (int argc, char *argv[]) {
    char nombres[5][30];
    char materias[3][30]; 
    float NM1[5], NM2[5], NM3[5]; 
    int opc, cont1 = 0, cont2 = 0, aux = 0;
    do
    {
        opc = menu(); // LLAMAR A F. MENÚ

        switch (opc)
        {
        case 1:
            ingresarNombre(nombres[cont1], cont1 + 1);
            cont1 = cont1 + 1;
            break;

        case 2:
            ingresarMaterias(materias[cont2], cont2);
            cont2 = cont2 + 1;
            break;

        case 3:
            printf("Seleccione el alumno del cual desea ingresar las notas: \n");
            printf("#\tNombre\n");
            for (int i = 0; i < cont1; i++)
            {
                printf("%d\t<%s\n", i, nombres[i]);
            }
            printf(">> ");
            scanf("%d", &aux);
            NM1[aux] = ingresarNotasMateria(materias[0], nombres[aux]);
            NM2[aux] = ingresarNotasMateria(materias[1], nombres[aux]);
            NM3[aux] = ingresarNotasMateria(materias[2], nombres[aux]);
            break;

        default:
            break;
        }

    } while (opc != 8);
    return 0;
}

int menu (){ // EL MENÚ
    int opc; 
    printf("Seleccione una opcion: \n");
    printf("1. Ingrese el nombre del alumno:\n"); 
    printf("2. Ingrese materias:\n"); 
    printf("3. Ingrese calificaciones:\n");
    printf("4. Ver promedio por alumno:\n");  
    printf("5. Ver promedio por materia:\n");  
    printf("6. Ver notas altas y bajas por alumno:\n"); 
    printf("7. Ver notas altas y bajas por materia:\n");  
    printf("8. Salir\n");
    printf(">> "); 
    scanf("%d", &opc); 
    return opc; 
}
void ingresarNombre(char nombre[30], int i){ // F. PARA INGRESAR NOMBRES
    int len; 
    printf("Ingrese el nombre del alumno %d: ", i); 
    fflush(stdin);
    fgets(nombre,30,stdin); 
    len = strlen(nombre) - 1; 
    nombre[len] = '\0'; 
}
void ingresarMaterias(char materia[30], int i){ // F. PARA INGRESAR MATERIAS
    int len; 
    printf("Ingrese el nombre de la materia %d: ", i + 1); 
    fflush(stdin);
    fgets(materia,30,stdin); 
    len = strlen(materia) - 1; 
    materia[len] = '\0'; 
}
float ingresarNotasMateria(char nombre[30], char materia[30]){ // F. PARA INGRESAR NOTAS
    float m;
    int val;
    do
    {
        printf("Ingrese la nota de la materia  %s del alumno %s: ", materia, nombre);
        val = scanf("%f", &m);
        if (val != 1)
        {
            printf("El valor ingresado no es correcto.\n");
        }
        if (m < 0 || m > 10)
        {
            printf("El valor ingresado debe estar entre 0 y 10.\n");
        }
    } while (m < 0 || m > 10 || val != 1);
    return m; 
}
