/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

//PROTOTIPOS
void maxHeapfy(int[], int, int);
void printarVetor(int[], int);
void build_max_heap(int[], int);
void heapsort(int[], int);

//MAIN
void main()
{
    //Vetores Teste
    int vet1[5] = {3,8,8,8};
    int vet2[5] = {14,52,4,24,33};
    int vet3[10] = {52,4,24,33,2,41,25,125,231,61};
    int vet4[7] = {1,2,42,25,21,123,43};
    int vet5[6] = {1,2,3,4,5,6};
    
    int tamanho1 = sizeof(vet1)/sizeof(vet1[0]); //Tamanho do vetor 1
    int tamanho2 = sizeof(vet1)/sizeof(vet1[0]); //Tamanho do vetor 2
    int tamanho3 = sizeof(vet1)/sizeof(vet1[0]); //Tamanho do vetor 3
    int tamanho4 = sizeof(vet1)/sizeof(vet1[0]); //Tamanho do vetor 4
    int tamanho5 = sizeof(vet1)/sizeof(vet1[0]); //Tamanho do vetor 5


    //Printando valores iniciais
    printf("\nVetor 1 =");
    printarVetor(vet1,tamanho1);
    printf("\nVetor 2 =");
    printarVetor(vet2,tamanho2);
    printf("\nVetor 3 =");
    printarVetor(vet3,tamanho3);
    printf("\nVetor 4 =");
    printarVetor(vet4,tamanho4);
    printf("\nVetor 5 =");
    printarVetor(vet5,tamanho5);
    printf("\n");

    //build_max_heapify
    build_max_heap(vet1,tamanho1);
    build_max_heap(vet2,tamanho2);
    build_max_heap(vet3,tamanho3);
    build_max_heap(vet4,tamanho4);
    build_max_heap(vet5,tamanho5);

    //Printando valores do max_heapify feito
    printf("\nBuild Max  1 = ");
    printarVetor(vet1,tamanho1);
    printf("\nBuild Max  2 = ");
    printarVetor(vet2,tamanho2);
    printf("\nBuild Max  3 = ");
    printarVetor(vet3,tamanho3);
    printf("\nBuild Max  4 = ");
    printarVetor(vet4,tamanho4);
    printf("\nBuild Max  5 = ");
    printarVetor(vet5,tamanho5);
    printf("\n");

    //heap_sort
    heapsort(vet1,tamanho1);
    heapsort(vet2,tamanho2);
    heapsort(vet3,tamanho3);
    heapsort(vet4,tamanho4);
    heapsort(vet5,tamanho5);

    //Printando valores dos heap_sort feito
    printf("\nHeap Sort  1 = ");
    printarVetor(vet1,tamanho1);
    printf("\nHeap Sort  2 = ");
    printarVetor(vet2,tamanho2);
    printf("\nHeap Sort  3 = ");
    printarVetor(vet3,tamanho3);
    printf("\nHeap Sort  4 = ");
    printarVetor(vet4,tamanho4);
    printf("\nHeap Sort  5 = ");
    printarVetor(vet5,tamanho5);
    printf("\n");

    //Pegar vetor do arquivo
      FILE *arquivo;
      arquivo = fopen("couting.txt", "r");
                int tam, i, e;

                if(!arquivo){return;}                   //Verifica abertura do arquivo
                fscanf(arquivo, " %d", &tam);

                int vetArq[tam];

                for(i = 0; i < tam; i++){               //Coloca os numeros do arquivo no vetor
                    fscanf(arquivo, " %d", &e);
                    vetArq[i] = e;
                }

    fclose(arquivo); //Fecha o arquivo
    printf("\n");

    //Printar vetor do arquivo 
    printf("Vetor do arquivo\n");
    printf("\n");
    printarVetor(vetArq,tam);
    printf("\n");
    //Fazer o max_heap do vetor do arquivo
    build_max_heap(vetArq,tam);
    printf("\nMax Heap\n");
    printf("\n");
    printarVetor(vetArq,tam);
    printf("\n");printf("\n");
    //Heapsort
    printf("Heapsort\n");
    printf("\n");
    heapsort(vetArq,tam);
    printarVetor(vetArq,tam);
    printf("\n");
}

//PRINTAR VETOR
void printarVetor(int vet[],int tamanho){
    int i = 0;
    
    while (i < tamanho){
        printf("%d,",vet[i]);
        i++;
    }
}

//MAX HEAPIFY
void max_heapify(int vet[],int ind, int tamanho){
        int esq = -5;
        if (ind*2+1 <tamanho) //Tamanho =5 , Indice só vai até 4 por exemplo
        esq = vet[ind*2+1];
        
        int dir = -5;
        if (ind*2+2 <tamanho){ 
        dir = vet[ind*2+2];
        }
        
        //Ver o da direita
        if (vet[ind]< dir){
            vet[ind*2+2] = vet[ind]; //Mudar o valor da direita
            vet[ind] = dir; //Mudar o valor do atual
            max_heapify(vet,ind, tamanho); //Recursividade em si mesmo
            max_heapify(vet,ind*2+1, tamanho); //Recursividade pro da esquerda
            max_heapify(vet,ind*2+2, tamanho); //Recursividade pro da direita
       
        }else if (vet[ind] < esq){ //Trocar com o da esquerda
            vet[ind*2+1] = vet[ind]; //Mudar o valor da esquerda
            vet[ind] = esq; //Mudar o valor do atual
            max_heapify(vet,ind, tamanho); //Recursividade em si mesmo
            max_heapify(vet,ind*2+1, tamanho); //Recursividade pro da esquerda
            max_heapify(vet,ind*2+2, tamanho); //Recursividade pro da direita
        }
        
}

//HEAP SORT
heapsort(int vet[], int tamanho2){
        int i = 0;
        int intTemp = 0;
        build_max_heap(vet,tamanho2);

        for (i = tamanho2-1; i>0;--i){
            intTemp = vet[0];
            vet[0] = vet[i];
            vet[i] = intTemp;
            tamanho2--;
        max_heapify(vet,0,tamanho2);
        }
}


//BUILD MAX HEAP
build_max_heap(int vet[],int indice_atual){
int tamanho_original = indice_atual;    
    while (indice_atual>=0){
        max_heapify(vet,indice_atual,tamanho_original);
        indice_atual--;
    }
}












