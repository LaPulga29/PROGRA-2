#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char ID[5][10], nombre[5][30], aux[10]; 
    int stock[5], opcion1, opcion2, cont = 0, len = 0, cantidad = 0, aux2 = 0, val = 0; 
    float precio[5], total_ganacia = 0, venta; 
    do
    {
        printf("1. Registrar producto\n"); 
        printf("2. Ver productos\n"); 
        printf("3. Vender producto\n"); 
        printf("4. Reabastecer producto\n"); 
        printf("5. Ver ganancias totales\n"); 
        printf("6. Salir\n");
        printf("Selecciones una opcion:\n"); 
        scanf("%d", &opcion1);
        switch (opcion1)
        {
        case 1:
            printf("Ingrese el ID del producto %d: ", cont + 1);
            fflush(stdin);
            scanf("%s", &ID[cont]); 
            printf("Ingrese el nombre del producto %d: ", cont + 1); 
            fflush(stdin);
            fgets(nombre[cont],30,stdin);
            len = strlen(nombre[cont]) - 1;
            nombre[cont][len] = '\0';
            printf("Ingrese el stock del producto %d: ", cont + 1);
            scanf("%d", &stock[cont]); 
            printf("Ingrese el precio del producto %d: ", cont + 1); 
            scanf("%f", &precio[cont]); 
            cont = cont + 1; 
            val = 1; 
            break;
        
        case 2:
            if (val == 0)
            {
                printf("Se necesitan registrar un producto primero.\n");
                break;
            }
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n"); 
            for (int i = 0; i < cont; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%.2f\n", ID[i],nombre[i],stock[i],precio[i]);
            }
            break; 
            
        case 3:
            if (val == 0 )
            {
                printf("Se necesitan registrar un producto primero.\n");
                break;
            }
            int cantidad = 0; 
            printf("Ingrese el ID del producto a vender: ");
            scanf("%s", &aux);
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(ID[i],aux) == 0)
                {
                    printf("Producto encontrado\n");
                    printf("Ingrese el numero de elementos a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad <= stock[i])
                    {
                        venta = cantidad * precio[i];
                        printf("La venta es: %.2f\n", venta);
                        stock[i] = stock[i] - cantidad;
                        if (cantidad >= 20)
                        {
                            printf("10 porciento de descuento por 20 o mas unidades.\n"); 
                            venta = venta * 0.9; 
                            printf("El valor de la venta con descuento es: %.2f\n", venta);
                        }
                        total_ganacia = total_ganacia + venta;  
                    }else{
                        printf("No se puede realizar venta, no existe suficiente stock.\n"); 
                    }
                }
            }
            break;

        case 4:
            if (val == 0 )
            {
                printf("Se necesitan registrar un producto primero.\n");
                break;
            }
            printf("Seleccione el numero del producto a reabastecer. \n"); 
            
            printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n"); 
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",  i, ID[i], nombre[i], stock[i], precio[i]); 
            }
            printf(">> ");
            scanf("%d", &aux2); 
            printf("Ingrese la cantidad del producto %s a reabastecer\n", nombre[aux2]); 
            scanf("%d", &cantidad); 
            if (cantidad > 0)
            {
                stock[aux2] = stock[aux2] + cantidad; 
                printf("El nuevo stock del producto %s es: %d\n", nombre[aux2], stock[aux2]); 
            }
            break; 

        case 5:
            if (val == 0 )
            {
                printf("Se necesitan registrar un producto primero.\n");
                break;
            }
            printf("Las ganancias totales son: %.2f\n", total_ganacia);
            break; 

        default:
            break;
        }
    } while (opcion1 != 6);
    return 0;
}