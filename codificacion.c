#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void inicializarTablero(char codificacion[5][5]);
int parametroValido(char caracter);
void rellenarCodificacion(char codificacion[5][5], char caracteresValidos[], int capacidad);
void mostrarCodificacion(char codificacion[5][5]);
void generarEncriptado(char caracteresValidos[], int capacidad);

int main(){

    int x, y, presente, indice = 0;
    char codificacion[5][5];
    char fraseInicial[40];
    printf("Ingresa la frase inicial: ");
    fgets(fraseInicial, 40, stdin);
    char caracterUnico[strlen(fraseInicial)];

    // Presente se usa como boolean, 0 = true, 1 = false;
    for(x = 0; x < strlen(fraseInicial) - 1; x ++){
        presente = 1;
        for(y = 0; y < strlen(caracterUnico); y ++)
            if(fraseInicial[x] == caracterUnico[y] || parametroValido(fraseInicial[x]) == 1)
                presente = 0;
        if(presente == 1){
            caracterUnico[indice] = fraseInicial[x];
            indice ++;
        }
    }

    inicializarTablero(codificacion);
    rellenarCodificacion(codificacion, caracterUnico, strlen(caracterUnico));
    mostrarCodificacion(codificacion);
    generarEncriptado(caracterUnico, strlen(caracterUnico));

}

int parametroValido(char caracter){
    if((caracter > 64 && caracter < 91) || (caracter > 96 && caracter < 123))
        return 0;
    return 1;
}

void inicializarTablero(char codificacion[5][5]){
    int x, y;

    for(x = 0; x < 5; x ++)
        for(y = 0; y < 5; y ++)
            codificacion[x][y] = 32;
}

void rellenarCodificacion(char codificacion[5][5], char caracteresValidos[], int capacidad){
    int x, y, z = 0;

    srand(time(NULL));

    for(x = 0; x < 5; x ++)
        for(y = 0; y < 5; y ++, z ++){
                if(z < capacidad)
                    codificacion[x][y] = toupper(caracteresValidos[z]);
                else
                    codificacion[x][y] = rand()%26+65;
        }
}

void mostrarCodificacion(char codificacion[5][5]){
    int x, y;

    for(x = 0; x < 5; x ++){
        for(y = 0; y < 5; y ++)
            printf("[%c] ", codificacion[x][y]);
        printf("\n");
    }
}

void generarEncriptado(char caracteresValidos[], int capacidad){

    char palabra[25];
    int x, y, presente;
    fgets(palabra, 25, stdin);

    for(x = 0; palabra[x] != '\n'; x ++){
        presente = 0;
        for(y = 0; y < strlen(caracteresValidos) && presente == 0; y ++)
            if(caracteresValidos[strlen(caracteresValidos) - 1] == palabra[x])
                y = strlen(caracteresValidos);
            else if(palabra[x] == caracteresValidos[y]){
                printf("%c", caracteresValidos[y+1]);
                presente = 1;
            }
        if(presente == 0)
            printf("%c", palabra[x]);
        presente = 0;
    }
}