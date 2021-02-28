#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[]){
    //Declarando variável 'a1' e 'a2' para os arquivos de entrada e saida, onde 'a2' será a saida e 'a1' a entrada.
    FILE* a1;
    FILE* a2;
    a1 = fopen(argv[1],"r"); // Abrindo arquivo a1 (para leitura) e 'criando' a2(para escrita).
    a2 = fopen("saida.txt","w");
    int* vetor; //Criando um ponteiro do tipo inteiro para apontar
    int n,contador = 0,i,j;
    fscanf(a1, "%d", &n); //Obtendo entrada que está no arquivo e salvando na variavel n.
    vetor = (int*) malloc(sizeof(int)*n); //Alocando dinamicamente o vetor de entradas.
    for(i = 0;i < n;i++){
        fscanf(a1,"%d", &vetor[i]); //Pegando o restante das entradas e armazenando no vetor.
    }
    for(i = 0;i < n;i++){ //Percorrendo o vetor ate o numero de entradas contido no arquivo (n).
        for(j = i;j < n;j++){ //A cada valor de i percorrendo os valores do vetor restantes.
            if(i < j && vetor[i] > 2 * vetor[j]){ //Verificando se a condição do problema é satisfeita.
                contador++; //Contando toda vez que a condição for satisfeita.
            }
        }
    }
    fprintf(a2,"%d", contador); //Colocando o número de ocorrências da condição no arquivo.
    //Fechando arquivo 'a1' e 'a2'.
    fclose(a2);
    fclose(a1);
    return 0;
}
