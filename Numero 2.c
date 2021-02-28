#include <stdlib.h>
#include <stdio.h>
#include "Pilha.c"

int main(int argc, char **argv){
    FILE* a1;
    FILE* a2;
    a1 = fopen(argv[1],"r"); //Abrindo arquivos 'a1'(para leitura) e 'a2'(para escrita).
    a2 = fopen(argv[2],"w");
    Pilha *aux; //Declarando um ponteiro tipo Pilha.
    aux = iniciaPilha(); //Criando uma Pilha aux.
    Pilha *p; //Declarando um ponteiro tipo Pilha
    p = iniciaPilha(); //Criado uma pilha p.
    int aux_operando1,aux_operando2,aux_resultado;
    char* entrada;
    char* resultado;
    char* operando1;
    char* operando2;
    int operad;
    //Alocando dinamicamente as variáves tipo char com 10 espaços.
    operando1 = (char*) malloc(sizeof(char)*10);
    operando2 = (char*) malloc(sizeof(char)*10);
    resultado = (char*) malloc(sizeof(char)*10);
    while(!feof(a1)){ //Pegando entradas do arquivo 'a1'
        entrada = (char*) malloc(sizeof(char)*10); //Alocando a 'entrada' dinamicamente.
        fgets(entrada,10,a1); //Lendo a entrada do arquivo e armazenando em um tipo char.
        empilhar(aux,entrada); //Empilhando a entrada na pilha 'aux'.
    }
    while(!pilhaVazia(aux)){ //Inverte o armazenamento feito das entradas em uma pilha.
        //Desempilhando da 'aux' e empilhando na 'p'.
        entrada = desempilha(aux);
        empilhar(p,entrada);
    }
    while(!pilhaVazia(p)){ //Resolvendo a expressão.
        entrada = desempilha(p);
        if(!atoi(entrada)){ // So entra quando o que foi desempilhado de 'p' não for um número.
            operando1 = desempilha(aux);
            if(!pilhaVazia(aux)){ // So entra se a pilha não estiver vazia.
                operando2 = desempilha(aux);
                //Convertendo os dois valores retirados da pilha de char para int.
                aux_operando1 = atoi(operando1);
                aux_operando2 = atoi(operando2);
                //Verificando qual operador foi desempilhado da Pilha 'p' e realizando a devida operação.
                if(entrada[0] == '+'){
                    aux_resultado = aux_operando2 + aux_operando1;
                }
                else{
                    if(entrada[0] == '-'){
                        aux_resultado = aux_operando2 - aux_operando1;
                    }else{
                        if(entrada[0] == '*'){
                            aux_resultado = aux_operando2 * aux_operando1;
                        }else{
                            if(entrada[0] == '/'){
                                aux_resultado = aux_operando2 / aux_operando1;
                            }
                        }
                    }
                }
                resultado = malloc(sizeof(char)*10); //Criando um espaço na memória para o resultado da operão.
                sprintf(resultado,"d",aux_resultado); //Convertendo de int para char.
                empilhar(aux,resultado); //Empilhando o resultado na pilha 'aux'.
            }
            else{ //Caso ao desempilhar a pilha fique fazia, não podendo desempilhar outro valor para realizar a operação.
                empilhar(aux,entrada); //Empilha novamente o valor desempilhado.
            }
        }
        else{ //Caso o que foi desempilhado em 'p' seja um número.
            empilhar(aux,entrada); //Empilha na pilha 'aux'.
        }
    }
    fprintf(a2,"%s",resultado); //Colocando o resultado no arquivo de saída.
    //Fechando os arquivos abertos.
    fclose(a2);
    fclose(a1);
    return 0;
}
