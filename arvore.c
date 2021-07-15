#include "arvore.h"

struct no
{
    int valor;
    struct no *esquerda, *direita;
};

NoArv* inserir_v1 (NoArv *raiz, int num)
{
    if (!raiz)
    {
        NoArv *aux = (NoArv*) malloc (sizeof (NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else
    {
        if (num < raiz->valor)
            raiz->esquerda = inserir_v1 (raiz->esquerda, num);
        else
            raiz->direita = inserir_v1 (raiz->direita, num);
        return raiz;
    };   
};

void inserir_v2 (NoArv **raiz, int num)
{
    if(!(*raiz))
    {
        *raiz = (NoArv *) malloc (sizeof (NoArv));

        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else
    {
        if(num < (*raiz)->valor)
            inserir_v2(&((*raiz)->esquerda), num);
        else
            inserir_v2(&((*raiz)->direita), num);
    }
};

void inserir_v3 (NoArv **raiz, int num)
{
    NoArv *aux = *raiz;

    while (aux)
    {
        if (num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;

        aux = *raiz;
    }

    aux = (NoArv*) malloc (sizeof (NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;

    *raiz = aux;
};

NoArv* buscar_v1 (NoArv *raiz, int num)
{
    if (raiz)
    {
        if (num == raiz->valor)
            return raiz;
        else if (num < raiz->valor)
            return buscar_v1 (raiz->esquerda, num);
        else
            return buscar_v1 (raiz->direita, num);
    }

    return NULL;
};

NoArv* buscar_v2 (NoArv *raiz, int num)
{
    while (raiz)
    {
        if (num < raiz->valor)
            raiz = raiz->esquerda;
        else if (num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }

    return NULL;
};

void imprimir_v1 (NoArv *raiz)
{
    if (raiz)
    {
        printf ("%d ", raiz->valor);
        imprimir_v1 (raiz->esquerda);
        imprimir_v1 (raiz->direita);
    };
};

void imprimir_v2 (NoArv *raiz)
{
    if (raiz)
    {
        imprimir_v2 (raiz->esquerda);
        printf ("%d ", raiz->valor);
        imprimir_v2 (raiz->direita);
    }
};

void imprimir_busca (NoArv *busca)
{
    printf("\n\tValor encontrado: %d\n", busca->valor);
};

NoArv* remover (NoArv *raiz, int chave)
{
    if (!raiz)
    {
        printf ("Valor nao encontrado!\n");
        return NULL;
    }
    else
    {
        if (raiz->valor == chave)
        {
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                printf("\n\tElemento folha removido: %d!\n", chave);
                free(raiz);
                return NULL;
            }
            else
            {
                if (raiz->esquerda && raiz->direita)
                {
                    NoArv *aux;
                    while (aux->direita)
                        aux = aux->direita;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    raiz->esquerda = remover (raiz->esquerda, chave);
                    return raiz;
                }
                else
                {
                    NoArv *aux;
                    if (raiz->esquerda)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    printf ("\n\tElemento removido: %d!\n", chave);
                    free (raiz);
                    return aux;
                }
            }
        }
        else
        {
            if (chave < raiz->valor)
                raiz->esquerda = remover (raiz->esquerda, chave);
            else
                raiz->direita = remover (raiz->direita, chave);
            return raiz;
        }
        
    }
};


