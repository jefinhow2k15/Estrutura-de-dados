#include <stdio.h>
int busca(float *v, int n, float proc);
void ordena(float *v, int n);
int main()
{
    int i, n, achou;
    float *v;
    float proc; 
    
    printf("\nInforme o tamanho do vetor: \n"); scanf("%d", &n);  
    v=(float*)malloc(n*sizeof(float));
    if(v==NULL)
    {
     printf("Memoria insuficiente.\n");
     return 1;
    } 
    
    /*leitura dos valores*/    
    printf("--------------------Entre com os valores--------------------\n");
    for(i=0;i<n;i++)
    {
     printf("\nInforme um numero: \n"); scanf("%f", &v[i]);
    }
     printf("\nEntre com o valor que deseja procurar: ");
     scanf("%f", &proc);
    ordena(v,n);
    for(i=0;i<n;i++)
    {
     printf("%1.f\t",v[i]);
    }
    printf("\n");
    achou=busca(v,n,proc);
    
    if(achou==-1)
    {
     printf("\n O numero digitado nao existe no vetor\n\n\n");
     printf("\n ---------------------------------------\n\n\n");
    }
    else
    {
     printf("\nO numero esta na posicao %d\n\n\n", achou);
     printf("\n ---------------------------------------\n\n\n");
    }
    
    free(v);
    
    
    system("pause");    
    return 0;
}

 void ordena(float *v, int n)
 {
     int f=n-1, i, troca=1;
     float aux;
     
     while (troca==1)
     {
           f=f-1;
           troca=0;
           for(i=0;i<=f;i++)
           {
            if(v[i]>v[i+1])
            {
             aux=v[i];
             v[i]=v[i+1];
             v[i+1]=aux;
             troca=1;
            }
           }
     }        
 }
      
 int busca(float *v, int n, float proc)
 {
       int i;       
       for(i=0;i<n;i++)
       {
        if(v[i]==proc)
        {
         return i;                                      
        }
       }
       return -1;       
 }
