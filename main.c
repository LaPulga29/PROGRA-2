#include <stdio.h>
#include <string.h>
int main()
{
    int estudiantes, materias = 3, aprobados = 0, reprobados = 0, len = 0, val0, val1, opc;
    int aux1 = 0, aux2 = 0, aux3 = 0;
    float calificaciones[30][3], suma = 0;
    char ests_nombres[30][30], mats_nombres[3][30];
    do
    {
        printf("\n\t-> MENU PARA CALIFICACIONES <-\t\n");
        printf("1. Ingresar las materias.\n");
        printf("2. Ingresar numero y nombres de estudiantes.\n");
        printf("3. Ingresar calificacion por estudiante.\n");
        printf("4. Promedio de calificaciones por estudiante.\n");
        printf("5. Promedio de calificaciones por materia.\n");
        printf("6. Calificacion mas alta y baja por estudiante.\n");
        printf("7. Calificacion mas alta y baja por materia.\n");
        printf("8. Estudiantes aprobados y reprobados por materia.\n");
        printf("9. Salir :3\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            for (int cont2 = 0; cont2 < 3; cont2++)
            {
                printf("Nombre de la materia %d: ", cont2 + 1);
                fflush(stdin);
                fgets(mats_nombres[cont2], 30, stdin);
                len = strlen(mats_nombres[cont2]) - 1;
                mats_nombres[cont2][len] = '\0';
            }
            aux1 = 1; 
            break;
        case 2:
            if (aux1 == 0)
            {
                printf("Se necesitan los nombres de las materias primero.\n");
                break;
            }
            printf("Ingrese el numero de estudiantes: ");
            scanf("%d", &estudiantes);
            for (int cont1 = 0; cont1 < estudiantes; cont1++)
            {
                printf("Nombre del estudiante %d: ", cont1 + 1);
                fflush(stdin);
                fgets(ests_nombres[cont1], 30, stdin);
                len = strlen(ests_nombres[cont1]) - 1;
                ests_nombres[cont1][len] = '\0';
            }
            aux2 = 1; 
            break;
        case 3:
        if (aux1 == 0 || aux2 == 0)
            {
                printf("Se necesitan los nombres de materias y estudiantes primero.\n");
                break;
            }
            for (int cont1 = 0; cont1 < estudiantes; cont1++)
            {
                for (int cont2 = 0; cont2 < materias; cont2++)
                {
                    do
                    {
                        printf("Calificacion de %s en %s (0-10): ", ests_nombres[cont1], mats_nombres[cont2]);
                        fflush(stdin);
                        val1 = scanf("%f", &calificaciones[cont1][cont2]);
                        if (val1 != 1)
                        {
                            printf("No se permite ese valor.\n");
                        }
                        else if (calificaciones[cont1][cont2] < 0 || calificaciones[cont1][cont2] > 10)
                        {
                            printf("No se permite ese valor.\n");
                        }
                    } while (calificaciones[cont1][cont2] < 0 || calificaciones[cont1][cont2] > 10 || val1 != 1);
                }
            }
            aux3 = 1; 
            break;
        case 4:
            if (aux1 == 0 || aux2 ==  0 || aux3 == 0)
            {
                printf("Se necesitan todos los datos (materias, estudiantes y calificaciones).\n");
                break;
            }
            printf("\n\t  -> PROMEDIOS POR ESTUDIANTES <-");
            printf("\nESTUDIANTE\t\t\t\tPROMEDIO\t\n");
            for (int cont1 = 0; cont1 < estudiantes; cont1++)
            {
                for (int cont2 = 0; cont2 < materias; cont2++)
                    suma = suma + calificaciones[cont1][cont2];
                printf("%s \t\t\t\t  %.2f\t\t\t\n", ests_nombres[cont1], suma / 3);
                suma = 0;
            }
            break;
        case 5:
            if (aux1 == 0 || aux2 ==  0 || aux3 == 0)
            {
                printf("Se necesitan todos los datos (materias, estudiantes y calificaciones).\n");
                break;
            }
            printf("\n\t   -> PROMEDIOS POR MATERIA <-");
            printf("\nMATERIA\t\t\t\t\tPROMEDIO\t\n");
            for (int cont2 = 0; cont2 < materias; cont2++)
            {
                for (int cont1 = 0; cont1 < estudiantes; cont1++)
                    suma = suma + calificaciones[cont1][cont2];
                printf("%s \t\t\t\t\t  %.2f\t\t\t\n", mats_nombres[cont2], suma / estudiantes);
                suma = 0;
            }
            break;
        case 6:
            if (aux1 == 0 || aux2 ==  0 || aux3 == 0)
            {
                printf("Se necesitan todos los datos (materias, estudiantes y calificaciones).\n");
                break;
            }
            printf("\n\t -> NOTA MAS BAJA Y MAS ALTA POR ESTUDIANTE <- \t\n");
            printf("ESTUDIANTE\t\t\tMAYOR\t\t\tMENOR\n");
            for (int cont1 = 0; cont1 < estudiantes; cont1++)
            {
                float max = calificaciones[cont1][0], min = calificaciones[cont1][0];
                for (int cont2 = 1; cont2 < materias; cont2++)
                {
                    if (calificaciones[cont1][cont2] > max)
                        max = calificaciones[cont1][cont2];
                    if (calificaciones[cont1][cont2] < min)
                        min = calificaciones[cont1][cont2];
                }
                printf("%s\t\t\t%.2f\t\t\t%.2f\n", ests_nombres[cont1], max, min);
            }
            break;
        case 7:
            if (aux1 == 0 || aux2 ==  0 || aux3 == 0)
            {
                printf("Se necesitan todos los datos (materias, estudiantes y calificaciones).\n");
                break;
            }
            printf("\n\t -> NOTA MAS BAJA Y MAS ALTA POR MATERIA <- \t\n");
            printf("MATERIA\t\t\t\tMAYOR\t\t\tMENOR\n");
            for (int cont2 = 0; cont2 < materias; cont2++)
            {
                float max = calificaciones[0][cont2], min = calificaciones[0][cont2];
                for (int cont1 = 1; cont1 < estudiantes; cont1++)
                {
                    if (calificaciones[cont1][cont2] > max)
                        max = calificaciones[cont1][cont2];
                    if (calificaciones[cont1][cont2] < min)
                        min = calificaciones[cont1][cont2];
                }
                printf("%s\t\t\t\t%.2f\t\t\t%.2f\n", mats_nombres[cont2], max, min);
            }
            break;
        case 8:
            if (aux1 == 0 || aux2 ==  0 || aux3 == 0)
            {
                printf("Se necesitan todos los datos (materias, estudiantes y calificaciones).\n");
                break;
            }
            printf("\n\t\t  -> APROBADOS POR MATERIA <-\t");
            printf("\nMATERIA\t\t\t\t\tAPROBADOS\t\tREPROBADOS\n");
            for (int cont2 = 0; cont2 < materias; cont2++)
            {
                aprobados = 0;
                reprobados = 0; 
                for (int cont1 = 0; cont1 < estudiantes; cont1++)
                {
                    if (calificaciones[cont1][cont2] >= 6)
                        aprobados = aprobados + 1;
                    else
                        reprobados = reprobados + 1; 
                }
                printf("%s\t\t\t\t\t   %d\t\t\t%d\n", mats_nombres[cont2], aprobados, reprobados);
            }
            break;
        case 9:
            printf("Saliendo del programa :3\n");
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
    } while (opc != 9);    
    return 0;
}