#include "arvore.h"
#include <stdio.h>
#include <conio.h>

int main (int argc, char const *argv[])
{
    int opcao, valor;
    NoArv *busca, *raiz = NULL;

    do
    {
        printf ("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Remover\n");
        scanf ("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf ("\n\t Digite um valor: ");
            scanf ("%d", &valor);
            //raiz = inserir_v1 (raiz, valor);
            //inserir_v2 (&raiz, valor);
            inserir_v3 (&raiz, valor);
            break;

        case 2:
            printf ("\n\tPrimeira Impressao:\n");
            imprimir_v1 (raiz);
            printf ("\n");
            
            printf ("\n\tSegunda Impressao:\n");
            imprimir_v2 (raiz);
            printf ("\n");
            break;
        
        case 3:
            printf ("\n\tDigite o valor a ser procurado: ");
            scanf ("%d", &valor);

            //busca = buscar_v1(raiz, valor);
            busca = buscar_v2 (raiz, valor);

            if (busca)
                imprimir_busca (busca);
            else
                printf ("\n\tValor nao encontrado!\n");
            break;

            case 4:
                printf ("\t");
                imprimir_v2 (raiz);
                printf ("\n\tDigite o valor a ser removido: ");
                scanf ("%d", &valor);
                raiz = remover (raiz, valor);
                break;

        default:
            if (opcao != 0)
                printf ("\nOpcao invalida!\n");
            break;
        };
    } while (opcao != 0);

    printf ("\n\tPressione qualquer tecla para sair...\n");
    getch ();

    return 0;
};
