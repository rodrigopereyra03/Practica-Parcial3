#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *crearV(int t);
void cargarArchivo(int *v);
void mostrarV(int *v, int t);
void ordenarV(int *v, int t);
void guardarDatos(int *v, int t);
void liberarMem(int *v);

int main()
{
    int *vec = crearV(15);

    cargarArchivo(vec);
    mostrarV(vec,15);
    ordenarV(vec,15);
    guardarDatos(vec,15);

    liberarMem(vec);

    return 0;
}

int * crearV(int t){

    int * vPtr = (int *) malloc(t*sizeof(int));
    return vPtr;
};

void cargarArchivo(int *v){

    FILE * archivo = fopen("numeros.txt", "r");

    if(archivo == NULL){

        printf("no se pudo abrir el archivo");
        exit(1);
    }

    int pos = 0;

    while(!feof(archivo)){
        fscanf(archivo,"%d\n", &v[pos]);
        pos++;
    }
    fclose(archivo);
};

void mostrarV(int *v, int t){

    printf("[");
    for(int i=0; i<t; i++){
        printf(" %d ", v[i]);
    }
    printf("]");
};

void ordenarV(int *v, int t){

    int *aux;

    for(int i=0; i<t; i++){

        for(int j=0; j<t-1; j++){

            if(v[j] > v[j+1]){

                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
};

void guardarDatos(int *v, int t){

    FILE * archivo = fopen("ordenados.txt", "w");

    for(int i=0; i<t; i++){

        fprintf(archivo,"%d\n", v[i]);
    }
};

void liberarMem(int *v){

    free(v);
};
