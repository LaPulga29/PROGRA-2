#include <stdio.h>

int main() {
    int stock, opcion, i, producto;
    float precio, cantidad, total_ganancias = 0, venta = 0, descuento = 0 ;
    char nombre[30], id[30];
    
    // REGISTRO DEL PRODUCTO //

    printf("Ingrese el ID del producto: "); // ID
    scanf("%s", &id);

    printf("Ingrese el nombre del producto: "); // NOMBRE
    scanf("%s", nombre);
    
    do {
        printf("Ingrese la cantidad inicial en stock: ");
        scanf("%d", & stock); 
        if (stock < 1) {
            printf("Solo se permiten numeros positivos.\n");
        }
    } while (stock < 1);

    printf("Ingrese el precio unitario del producto: ");
    scanf("%f", &precio);
    do
    {
        if (precio <= 0)
        {
            printf("No pueden ser valores negativos, intenta de nuevo.\n");
            printf("Ingrese el precio unitario del producto: ");
            scanf("%f", &precio);
        }
    } while (precio <= 0);

    do { // MENÚ DE OPCIONES 
        printf("\n\tMENU DE OPCIONES\t");
        printf("\n1. Ingresar producto \n"); 
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: // INGRESAR PRODUCTO
            printf("Ingrese el ID del producto: ");
            scanf("%s", &id);

            printf("Ingrese el nombre del producto: "); // NOMBRE
            scanf("%s", nombre);
            
            printf("Ingrese la cantidad inicial en stock: ");
                scanf("%d", &stock);
                do{
                    if (stock < 0)
                    {
                        printf("No pueden ser valores negativos, intenta de nuevo.\n");
                        printf("Ingrese la cantidad inicial en stock: ");
                        scanf("%d", &stock);
                    }
                }while(stock < 0);
        
            printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
                do
                {
                    if (precio <= 0)
                    {
                        printf("No pueden ser valores negativos, intenta de nuevo.\n");
                        printf("Ingrese el precio unitario del producto: ");
                        scanf("%f", &precio);
                    }
                } while (precio <= 0);
            break;

        case 2: // VENDER PRODUCTO
            do
            {
                printf("\nIngrese la cantidad a vender: ");
                scanf("%f", &cantidad);

                if (cantidad < 1)
                {
                    printf("No se puede ingresar cantidades negativas, ingrese nuevamente.\n");
                }
                if (cantidad > stock)
                {
                    printf("No se puede realizar la venta, no existe suficiente stock.\n");
                }
            } while (cantidad < 1 || cantidad > stock);

            venta = cantidad * precio; // CALCULAR PRECIO X VENTA
            printf ("El precio de esta venta es: $%.2f \n", venta);

            if (cantidad >= 100)
            {
                printf("Por la compra de mas de 100 unidades se otorga un descuento del 10%% en su compra.\n");
                venta = venta - (venta * 0.1); 
            }
            printf("El nuevo precio de esta venta es: $%.2f\n", venta);

            total_ganancias = total_ganancias  + venta; 
            stock = stock - cantidad;
            printf("El nuevo stock es: %d unidades.\n", stock);

            if (stock == 0) // NO VENDER MÁS DE LO POSIBLE
            {
                printf("El stock del producto se terminó, reabastezca el producto\n");
            }
            break;

        case 3: // REABASTECER PRODUCTO
            cantidad = producto;
            printf("Ingrese la cantidad a agregar al stock: ");
            scanf("%d", &producto);
            stock = stock + producto; 
            printf("El nuevo stock del producto es: %d unidades. \n", stock);
            break;

        case 4: // INFO DEL PRODUCTO
            printf("\n\tInformacion del producto\t\n");
            printf("ID: %s\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock disponible: %d unidades\n", stock);
            printf("Precio unitario: $%.2f\n", precio);
            break;

        case 5: // GANANCIAS POR VENTAS
            printf("Total de ganancias: $%.2f\n", total_ganancias);
            break;

        case 6: // SALIR 
            printf("\tSaliendo del programa :333\t\n");
            break;

        default: // NULL
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6); // 6 OPCIONES
    return 0;
}