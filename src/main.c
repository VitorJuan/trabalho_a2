#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define ARRAY_SIZE 1000

void bubbleSortCrescente(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];                
                
                array[j] = array[j + 1]; 
                array[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDecrescente(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//InsertionSort Crescente
void insertionSortCrescente(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

//InsertionSort Decrescente
void insertionSortDecrescente(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        // Inverte a lógica: agora troca se o elemento atual for menor
        while (j >= 0 && vetor[j] < chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

//Fazer com que o meu sistema de bubbleSort utiliza de Threads, assim permite que ele o faço mais rapido, divindo a array em 3, e a ordenanda, posteriromente jumta todas as 3 e aplica mais uma vez o algoritmo de ordenaçao, permetindo o paralelismo, mas aplicar o paralelismo somente quando a arrat foir maior que 80, caso nao for, o algortimo perfoma bem abaixo destas condiçoes, e verificar a possibilidade de compatibilidade com threads Windows, Linux (POSIX) e Apple (ios?)
void myBubbleSort(int array[], int arraySize) {
    for(int x = 0; x < arraySize; x++) {
        for(int i = 0; i < arraySize; i++) {
            if (array[x] < array[i]) {
                int temp = array[x];
                array[x] = array[i];
                array[i] = temp;
            }
        }        
    }
}

//Copia o conteúdo do primeiro array e cola no segundo
void copyArray(int array[], int newArray[], int arraySize) {
    for (int x = 0; x < arraySize; x++) {
        newArray[x] = array[x];
    }
}

//Coleta uma array e a enche com números aleatórios
void fillArray(int array[], int arraySize) {
    srand(time(NULL));
    for(int x = 0; x < arraySize; x++) {
        array[x] = rand() % 10000; //Limite para gerar números aleatórios entre 0 e 9999
    }
}

void printArray(int array[], int arraySize) {
    for (int x = 0; x < arraySize; x++) {
        printf("%d, ", array[x]);
    }
    printf("\n");
}

void printFirstElements(int array[], int arraySize) {
    if (arraySize <= 20) {
        printArray(array, arraySize);
    }
    else {
        for (int x = 0; x < 20; x++) {
            printf("%d, ", array[x]);
        }
        printf("\n");
    }
}

void printLastElements(int array[], int arraySize) {
    if (arraySize <= 20) {
        printArray(array, arraySize);
    }
    else {
        for (int x = arraySize - 20; x <= arraySize-1; x++) {
            printf("%d, ", array[x]);
        }
        printf("\n");
    }
}

int main() {
    int array[1000] = {0};
    int arraySize = sizeof(array) / sizeof(array[0]);

    int insertionArrayDec[ARRAY_SIZE] = {0};
    int insertionArrayCre[ARRAY_SIZE] = {0};
    
    int bubbleSortArrayDec[ARRAY_SIZE] = {0};
    int bubbleSortArrayCre[ARRAY_SIZE] = {0};


    printf("Gerando o vetor com 1000 elementos de forma aleatória...\n");
    fillArray(array, arraySize);

    printf("20 primeiros elementos: ");
    printFirstElements(array, arraySize);
    printf("20 ultimos elementos: ");
    printLastElements(array, arraySize);
    printf("\n");

    printf("Criando copias do vetor para aplicar os algortimos de ordenação...\n");
    copyArray(array, insertionArrayCre, ARRAY_SIZE);
    copyArray(array, insertionArrayDec, ARRAY_SIZE);
    copyArray(array, bubbleSortArrayCre, ARRAY_SIZE);
    copyArray(array, bubbleSortArrayDec, ARRAY_SIZE);

    //Bubble Sort Crescente
    printf("Aplicando bubble sort crescente:\n");
    bubbleSortCrescente(bubbleSortArrayCre, ARRAY_SIZE);
    printf("20 primeiros: ");
    printFirstElements(bubbleSortArrayCre, ARRAY_SIZE);
    printf("20 ultimos: ");
    printLastElements(bubbleSortArrayCre, ARRAY_SIZE);

    //BUbble Sort Decrescente
    printf("\nAplicando bubble sort decrescente:\n");
    bubbleSortDecrescente(bubbleSortArrayDec, ARRAY_SIZE);
    printf("20 primeiros: ");
    printFirstElements(bubbleSortArrayDec, ARRAY_SIZE);
    printf("20 ultimos: ");
    printLastElements(bubbleSortArrayDec, ARRAY_SIZE);

    //Insertion Sort Crescente
    printf("\nAplicando insertion sort crescente:\n");
    insertionSortCrescente(insertionArrayCre, ARRAY_SIZE);
    printf("20 primeiros: ");
    printFirstElements(insertionArrayCre, ARRAY_SIZE);
    printf("20 ultimos: ");
    printLastElements(insertionArrayCre, ARRAY_SIZE);

    //Insertion Sort Decrescente
    printf("\nAplicando insertion sort decrescente:\n");
    insertionSortDecrescente(insertionArrayDec, ARRAY_SIZE);
    printf("20 primeiros: ");
    printFirstElements(insertionArrayDec, ARRAY_SIZE);
    printf("20 ultimos: ");
    printLastElements(insertionArrayDec, ARRAY_SIZE);
    

    

    return 0;
}