// matriz, entrada e saida fflush gets

#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char **argv){

    int LEN = argc-1;

    if(LEN < 2){
        printf("Quantidade invalida de parametros");
        return 1;
    }

    FILE* fp;
    fp = fopen("c_result.txt", "w+");

    int vector[LEN];

    fprintf(fp, "Entrada: ");
    for(int i = 0; i < LEN; i++){
        vector[i] = atoi(argv[i+1]);
        fprintf(fp, "%d ", vector[i]);
    }

    // fwrite(vector, sizeof(int), LEN,fp);

    for (int j = 1; j < LEN; ++j){ // 1 2 3 4 5 6 7 8 9 0
        for (int i = 0; i < LEN-j; ++i){
            if(vector[i] < vector[i+1]){
                int aux = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = aux;
            }
        }
    }

    fprintf(fp, "\nSaida: ");
    for(int i = 0; i < LEN; i++){
        printf("%d ", vector[i]);
        fprintf(fp, "%d ", vector[i]);
    }

    printf("\n");

    fclose(fp);

    return 0;
}
