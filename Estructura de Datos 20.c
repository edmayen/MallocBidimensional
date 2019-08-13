#include<stdio.h>
#include<stdlib.h>
void CreaC(int***,int);
void CreaF(int***,int,int*,int*,int[]);
void Carga(int**,int,int[]);
void Borra(int**,int);

int main()
{
    int a,b,centi,**matriz;
    printf("\n\t\tMemoria Dinamica Bidimensional.\n\n");
    printf("Ingresa el Numero de Columnas: ");
    scanf("%d",&a);
    int tam[a];
    CreaC(&matriz,a);
    CreaF(&matriz,a,&b,&centi,tam);
    Carga(matriz,a,tam);
}

void CreaC(int ***matriz, int a)
{
    *matriz=(int**)malloc(a*sizeof(int));
    if(*matriz==NULL)
    {
        printf("\n\nError. Memoria Insuficiente.\n\n");
        getchar();
        exit(1);
    }
}

void CreaF(int ***matriz, int a, int *b, int *centi, int tam[])
{
    int i,x=1;
    for(i=0;i<a;++i)
    {
        printf("\nIngresa el Numero de Filas de la Columna %d: ",x);
        scanf("%d",b);
        tam[i]=*b;
        **(matriz+i)=(int*)malloc(sizeof(int)* *(b));
        if(**(matriz+i)==NULL)
        {
            printf("\n\nError. Memoria Insuficiente.\n\n");
            *centi=i;
            exit(1);
        }
        ++x;
    }
}

void Carga(int **matriz, int a, int tam[])
{
    int i,j,x=1;
    int siz=sizeof(matriz);
    printf("\n\nTAMANO: %d\n\n",siz);
    for(i=0;i<a;++i)
    {
        printf("\nIngresa los Elementos de la Columna %d.\n",x);
        for(j=0;j<tam[i];++i)
        {
            scanf("%d",*(matriz+i)+j);
        }
        ++x;
    }
}

void Borra(int **matriz, int cent)
{
    int i;
    for(i=0;i<cent;++i)
    {
        free(*(matriz+i));
    }
    free(matriz);
}
