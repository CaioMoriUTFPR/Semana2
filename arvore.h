#ifndef _ARVORE_H_
#define _ARVORE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct no NoArv;

NoArv* inserir_v1 (NoArv *raiz, int num);

void inserir_v2 (NoArv **raiz, int num);

void inserir_v3 (NoArv **raiz, int num);

NoArv* buscar_v1 (NoArv *raiz, int num);

NoArv* buscar_v2 (NoArv *raiz, int num);

void imprimir_v1 (NoArv *raiz);

void imprimir_v2 (NoArv *raiz);

void imprimir_busca (NoArv *busca);

NoArv* remover (NoArv *raiz, int chave);

#endif
