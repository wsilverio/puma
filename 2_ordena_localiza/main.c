#include <stdio.h> // printf
#include <stdlib.h> // atoi
#include <string.h> // strlen
#include <ctype.h>

int localiza(int num, int vec[], int tam){
    int pos = -1;
    int ponto1 = 0;
    int ponto2 = tam-1;

    while(ponto1 <= ponto2){
        int meio = (ponto1+ponto2)/2;

        if(num == vec[meio]){
            pos = meio;
            ponto2 = -1;
        }else if(num > vec[meio]){
            ponto2 = meio-1;
        }else{
            ponto1= meio+1;
        }
    }

    return pos;
}

int main(const int argc, const char **argv){
    if(argc <= 2){
        printf("Quantidade invalida de parametros.");
        return 1;
    }

    // -------------------------------------
    // ORDENA
    // -------------------------------------

    int TAM = argc-1;
    int vetor[TAM];

    // atribui a entrado ao vetor
    printf("Numeros de entrada: ");
    for(int i = 0; i < TAM; i++){
        vetor[i] = atoi(argv[i+1]);
        printf("%d ", vetor[i]);
    }

    printf("\n");

    // ordena o vetor do maior para o menor
    for(int j = 0; j < TAM-1; j++){
        for(int i = 0; i < TAM-j-1; i++){
            if(vetor[i] < vetor[i+1]){
                int aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
            }
        }
    }

    // exibe o vetor
    printf("Vetor ordenado: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }

    // -------------------------------------
    // LOCALIZA
    // -------------------------------------
    printf("\nValor a buscar: ");

    int val;
    char input[16];
    // le o valor digitado pelo usuario
    fgets(input,16,stdin);

    int strTam = strlen(input)-1;
    for(int i = 0; i < strTam; i++){
        if(!isdigit(input[i]) && input[i] != '-' && input[i] != '+'){
            printf("Caracter invalido.\n");
            return 1;
        }
    }

    val = atoi(input);

    int pos = localiza(val, vetor, TAM);
    if(pos < 0){
        printf("Valor nao encontrado.\n");
    }else{
        printf("Valor encontrado primeiramente na posicao: [%d] = %d\n", pos, vetor[pos]);
    }

    return 0;
    
}
