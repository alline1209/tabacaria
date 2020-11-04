#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	setlocale(LC_ALL, "Portuguese");
    int x,x1,x2;
	char s;

    //inicializa os endereços que conterao os produtos e fornecedores
    // contem o endereco pra primeira pos do vetor respectivo

    produto * pd = NULL, produtos[prod];
    fornecedores * fn = NULL, fornecedor[lim];
    produto * vendidos = NULL;

    while(1)
    {
        printf("\t\tMENU\n\n");
        printf("Escolha uma das opções:\n");
        printf("1. Cadastro \n2. Visualização\n3. Vendas\n4. Alteração \n5. Sair\n");

        scanf("%d", &x);

        // seleção dos modulos
        switch (x)
        {
            case 1:
                    printf("Digite o que deseja cadastrar: \n");
                    printf("1.Fornecedor \n2.Produto\n");

                    scanf("%d", &x1);

                    if (x1 == 1)
                    {
                        fn = cad_fornecedor(fn);
                        printf("\n");
                    }

                    else if (x1 == 2)
                    {
                        pd = cad_produto(pd);
                        printf("\n");
                    }
            break;
           case 2:
                // inserir os relatorios
                printf("\n *** Produtos vendidos:\n");
                relatoriodeVendas(vendidos);
            break;
            case 3:
                vendidos = venda (pd, vendidos);
            break;

            case 4:
                printf("\nSelecione o que deseja alterar:\n");
                printf("1.Fornecedor \n2.Produto\n");
                scanf("%d", &x2);

                    if (x2 == 1)
                    {
                        fn = alt_fornecedor(fn);
                        printf("\n");
                    }

                    else if (x2 == 2)
                    {
                        pd = alt_produto(pd);
                        printf("\n");
                    }
            break;

            case 5:
                printf("Deseja mesmo sair? S/N\n");
                scanf("%c", &s);

                if (s == 'S')
                    return 0;
            break;

            default:
                printf("Opção inválida.\n");
            break;
        }

    }
    // desaloca os vetores em memória da aplicação
    free(pd);
    free(fn);
    free(vendidos);
    return 0;
}
