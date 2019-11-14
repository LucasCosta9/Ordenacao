
#include <stdio.h>

//MAIN

void main()
{
	
	//Abrindo arquivo
      FILE *arquivo;
      arquivo = fopen("dij10.txt", "r");
                int tam; //Tamanho do arquivo

                if(!arquivo){return;}                   //Verifica abertura do arquivo
                fscanf(arquivo, " %d", &tam);

                int numeros[tam][tam];
                int num_temp;
                int i,j;
                for (i = 0; i<tam; i++){
                		for (j = i; j<tam;j++){
                			
                			if (i == j){
                				numeros[i][j] = 0;
                			}else{
                				fscanf(arquivo," %d",&num_temp);

	                			numeros[i][j] = num_temp;
	                			numeros[j][i] = num_temp;
	                			//numeros[j][i] = 999; //Só pra esse caso
                			}
                		}

               }
    fclose(arquivo); //Fecha o arquivo

    //Vetor dos que ja foram relaxados
    int p[tam];    
	int ip;
	for (ip = 0;ip<tam; ip++){
	p[ip] = -1;
	}
	//Vetor dos predecessores 2
    int p2[tam];    
	for (ip = 0;ip<tam; ip++){
	p2[ip] = -1;
	}
    
    //Vetor d[], somatorio dos caminhos mais curtos para determinado local
    int d[tam]; //Vetor que guarda os menores caminhos 
    for (i =0; i<tam; i++){
    	d[i] = 999999999;
    }
    d[0] = 0;

    //Printando matriz    
    int teste,i4,j4; 
    for (i4 = 0; i4<tam; i4++){
    	for (j4 = 0; j4<tam;j4++){
    		teste = numeros[i4][j4];
    		printf("%d ",teste );
    	}
    	printf("\n");
    }

	int menor_caminho = 0; //O caminho que vai ser relaxado
	int caminho_anterior = 0; //O caminho anterior, que vai ser salvo na lista de precedentes
    int prec_cheia = 0; //Vai virar 1 quando a lista de precedencia ficar cheia 
    int i2, cust;
    while (prec_cheia == 0){
    p[menor_caminho] = caminho_anterior;
    //Atualizando os caminhos caso sejam menores do que ja se tem em d[]
    for(i2 = 0;i2<tam; i2++){

    	cust = numeros[menor_caminho][i2]+d[menor_caminho];
    	if (cust < d[i2]){
    		d[i2] = cust;
    		p2[i2] = menor_caminho;
    	}
    }
     //Mostrando o p2[];
  printf("Precedencia: \n");
  for (i = 0; i<tam; i++){
  	printf("%d\n",p2[i]);
  }

    //Escolhendo o menor caminho
    caminho_anterior = menor_caminho;
    menor_caminho = menor_d(p,d,tam);
    //*******Prints*******
    printf("Menor caminho eh %d \n",menor_caminho);
    //Printar d[]
    for (i = 0; i<tam; i++){
    	printf("\n%d",d[i] );
    }
      printf("\n");

  	//Checando se todo mundo ja foi relaxado
    prec_cheia = precedencia_cheia(p,tam);
 
  }

  //Mostrando o p[];
  printf("Ordem do relaxamento: \n");
  for (i = 0; i<tam; i++){
  	printf("%d\n",p[i]);
  }
  /*
  //Mostrando o p2[];
  printf("Precedencia: \n");
  for (i = 0; i<tam; i++){
  	printf("%d\n",p2[i]);
  }
  */
  mostrar_precedencia(p2,tam);
} 
 
void mostrar_precedencia(int p3[], int tam){
      int i,k;
      for (i = 0; i<tam; i++){
         printf("Menor caminho para %d\n",i);
         k = p3[i];
         printf("%d\n",i);
         printf("^\n" );
         while (k >-1){
            printf("%d\n",k );
            k = p3[k];
            printf("^\n" );
         }
         printf("\n");
      } //Chegar no ultimo indice
      
} 


int precedencia_cheia(int p2[], int tam){
	int i ;
	for (i = 0; i<tam; i++){
		if (p2[i] == -1){
			return 0;
		}
	}
	return 1;
}




//Menor_d, vai identificar qual dos d[]s é o menor, desconsiderando os
//que possuem sua lista de precedencia
int menor_d(int p2[],int d2[], int tam){
	int i;
	int menor_val = 999999999;
	int menor_ind = 0;
	for (i = 0; i<tam; i++){

		if (p2[i]==-1 && d2[i] < menor_val){ 
			//Atualizar o menor
			menor_val = d2[i];  //Valor
			menor_ind = i; //Indice 
		}
	}
	return (menor_ind);
}











