#include <stdio.h>


int main(){

    FILE *fp;
    // TROCAR PELO NOME DO ARQUIVO DESEJADO
    fp = fopen("num.1000.1.in", "r");

    if (fp == NULL){
        printf("N ABRIU");
    }

    // Variaveis para colocar numeros do txt no vetor

    int a;
    int controle;
    int changer;

    // Passagem do txt para o vetor
    fscanf(fp, " %d", &changer);

    int testes[changer];

    for (a = 0; a < changer; a++){
        fscanf(fp, " %d", &controle);
        testes[a] = controle;
    }



    // Pegando o tamanho do array
    int n = sizeof(testes) / sizeof(testes[1]);

    int i;
    for (i = n; i >= 0; i--){
        min_heapfy(testes, n, i);
    }

    int j;

    //extract_min(testes, &n);
    //insert(testes, &n, valor);
    //change_key(testes, key, valor);

    printf("\n\nHeapfyed\n\n");
    for (j = 0; j < n; j++){
        printf("%d ", testes[j]);
    }

}

void min_heapfy(int A[], int n, int i){


    int maior = i;
    int esquerdo = 2*i + 1; // o da direita
    int direito = 2*i + 2; // o da esquerda

    // Se o filho esquerdo for maior que o pai
    if (esquerdo < n && A[esquerdo] < A[i]){
        maior = esquerdo;
    }

    // Se o filho for o maior
    if (direito < n && A[direito] < A[maior]){
        maior = direito;
    }

    // Se o maior ao for pai
    if (maior != i){
        int xtroca = A[i];
        A[i] = A[maior];
        A[maior] = xtroca;

        // Recursao
        min_heapfy(A, n, maior);
    }

}

// retorna o menor valor
int find_min(int A[]){
    return A[0];
}

// troca o valor de uma chave
void change_key(int A[], int key, int c){

    A[key] = c;

}

// insere item na heap
void insert(int A[], int *n, int c){

    A[*n] = c;
    *n += 1;

}

// tira o menor valor da heap
void extract_min(int A[], int *n){

    int escambo = A[0];
    A[0] = A[*n - 1];
    A[*n - 1] = escambo;
    *n -= 1;
}


