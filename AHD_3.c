#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void guardarTexto(char *texto, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    fprintf(archivo, "%s", texto);
    fclose(archivo);
    printf("El texto se guardó en %s con éxito.\n", nombreArchivo);
}

void guardarBinario(char *texto, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }
    fwrite(texto, sizeof(char), strlen(texto), archivo);
    fclose(archivo);
    printf("Texto guardado en formato binario en %s con éxito.\n", nombreArchivo);
}

int main() {
    char texto[100];
    char nombreArchivo[100];
    int opcion = 0;

    while (1) {
        printf("1. Ingresar el texto\n");
        printf("2. Guardar el texto en archivo .bin\n");
        printf("3. Guardar el texto en archivo .txt\n");
        printf("4. Salir\n");
        printf("Seleccione la opción que deseas: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                printf("Ingresa una cadena:\n");
                scanf("%[^\n]", texto);
                break;
            case 2:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombreArchivo);
                strcat(nombreArchivo, ".bin");
                guardarBinario(texto, nombreArchivo);
                break;
            case 3:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombreArchivo);
                strcat(nombreArchivo, ".txt");
                guardarTexto(texto, nombreArchivo);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }
}