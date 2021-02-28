#include <stdlib.h>

typedef struct celula{
   char *valor;
   struct celula *baixo;
}Celula;

typedef struct pilha{
   int tamanho;
   Celula *topo;
}Pilha;

int pilhaVazia(Pilha *p){
   if(p->topo == NULL){
      return 1;
   }else{
      return 0;
   }
}

Pilha *iniciaPilha(){
   Pilha *p = (Pilha *)malloc(sizeof(Pilha));
   p->topo = NULL;
   p->tamanho = 0;
   return p;
}

void empilhar(Pilha *p, char *valor){
   Celula *c = (Celula *)malloc(sizeof(Celula));
   c->valor = valor;

   if(pilhaVazia(p)){
      c->baixo = NULL;
      p->topo = c;
      p->tamanho++;
   }else{
      c->baixo = p->topo;
      p->topo = c;
      p->tamanho++;
   }
}

char* desempilha(Pilha *p){
   if(pilhaVazia(p)){
      return NULL;
   }else{
      char* valorTopo = p->topo->valor;
      Celula *tmp = p->topo;
      p->topo = p->topo->baixo;
      free(tmp);
      p->tamanho--;
      return valorTopo;
   }
}

void imprimirPilha(Pilha *p){
   while(!pilhaVazia(p)){
      printf("%s\n", p->topo->valor);
      p->topo = p->topo->baixo;
   }
}
