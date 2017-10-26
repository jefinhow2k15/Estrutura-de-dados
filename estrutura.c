#include<stdio.h>
#include<stdlib.h>

struct lista{
  float info;
  struct lista* prox;
};typedef struct lista Lista;

struct pilha{
  Lista* prim;
};typedef struct pilha Pilha;

// cria aloca a estrutura da pilha
// inicializa a lista como sendo vazia
Pilha* pilha_cria(void){
       Pilha* p = (Pilha*)malloc(sizeof(Pilha));
       p->prim = NULL;
       return p;
}

int vazia(Pilha* p){
     return p->prim == NULL;
}



//insere elemento no inicio da lista
void pilha_push(Pilha*p, float v)
{
   Lista* n = (Lista*)malloc(sizeof(Lista));
   n->info = v;
   n->prox = p->prim;
   p->prim = n;
}

//retira o elemento do inicio da lista
float pilha_pop(Pilha* p)
{
   Lista* t;
   float v;
   if(vazia(p))
    {
      printf("pilha vazia.\n");
      exit(1);
    }
   t = p->prim;
   v = t->info;
   p->prim = t->prox;
   free(t);

   return v;
}

void pilha_libera(Pilha* p){
     Lista* q = p->prim;
     while (q != NULL){
           Lista* t = q->prox;
           free(p);
           q = t;
     }
     free(p);
}

void pilha_imprime(Pilha* p){
     Lista* q;
     for(q = p->prim; q != NULL; q = q->prox)
           printf("%f\n", q->info);

}

void imprime(Pilha* p){
     Pilha* aux = pilha_cria();
     while(!vazia(p)){
         pilha_push(aux,pilha_pop(p));
     }
     while(!vazia(aux)){
         float v = pilha_pop(aux);
         printf("%f\n", v);
         pilha_push(p,v);
     }
     pilha_libera(aux);
}


int main()
{
   /* Implementação de pilha com lista encadeada */

   Pilha *p;

   p = pilha_cria();
   pilha_push(p,10);
   pilha_push(p,15);
   pilha_push(p,20);
   pilha_push(p,25);

   float v = pilha_pop(p);

   printf("%f\n", v);
   printf("\n");

   /* Vai imprimir do topo para a base, percorrendo a lista encadeada*/

   pilha_imprime(p);
   printf("\n");

   /* Vai imprimir da base para o topo usando as funções ja definidas e uma pilha auxiliar*/

   imprime(p);
   pilha_libera(p);

   system("pause");
   return 0;
}
