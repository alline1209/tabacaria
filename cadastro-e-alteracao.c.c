#include "biblio.h"

#define lim 100
#define prod 500

// variaveis globais que controlam o tamanho dos vetores alocados
int max_produtos= 0, atual_produtos = 0;
int max_fornecedores = 0, atual_fornecedores = 0;

produto produtos[prod], *pd;
fornecedores fornecedor[lim], *fn;

//funcoes:
fornecedores * cad_fornecedor(fornecedores * fn);
produto *  cad_produto(produto * pd);
int infoArmazenamento();
void menu();

fornecedores * cad_fornecedor(fornecedores * fn)
{
	int i , qtd;

    printf("\nDigite quantos fornecedores serão cadastrados:\n");
	scanf("%d", &qtd);
	getchar();

	//se ainda nao existir o estoque
	if(max_fornecedores == 0)
    {
        free(fn);
        fn = malloc ( qtd * sizeof(fornecedor));
        max_fornecedores = qtd;
        atual_fornecedores= qtd;
        i = 0;
    }
    //se ja existir estoque na memoria
    else {
        if ( (max_fornecedores - atual_fornecedores) > qtd) { //se ja existir um estoque, adicionar +
            i = atual_fornecedores;
            atual_fornecedores += qtd;
        }

        else {
            i = atual_fornecedores;
            atual_fornecedores += qtd;
            max_fornecedores = atual_fornecedores;
            fn = realloc( fn, (atual_fornecedores + qtd) * sizeof(fornecedor) ); //vai realocar esse estoque se ele nao existir
        }
    }

    while (i < atual_fornecedores) {
        printf("\nDigite o código do(s) fornecedor(es), nome e a especialidade: \n");

        printf("\nCodigo:\n");
        scanf("%li", &fn[i].codigo);
        getchar();

        printf("\nNome:\n");
        fgets(fn->nome, lim, stdin);

        printf("\nEspecialidade:\n");
        fgets(fn->especialidade, lim, stdin);

        i++;

	}
	printf("\nCadastros feitos!\nVoltando ao menu.\n");
    return (fn);

}

produto *  cad_produto(produto * pd)
{
	int j = 0, qtd;

	printf("\nDigite quantos produtos serão cadastrados:\n");
	scanf("%d", &qtd);
    getchar();

	//se ainda nao existir o estoque
	if(max_produtos == 0)
    {
        pd = malloc ( qtd * sizeof(produto));
        max_produtos = qtd;
        atual_produtos = qtd;
    }
    //se ja existir estoque na memoria
    else {
        if(max_produtos - atual_produtos > qtd) { //se ja existir um estoque, adicionar +
            j = atual_produtos;
            atual_produtos += qtd;
        }

        else {
            j = atual_produtos;
            atual_produtos += qtd;
            max_produtos = atual_produtos;
            pd = realloc( pd, (atual_produtos + qtd)* sizeof(produto) ); //vai realocar esse estoque se ele nao existir
        }
    }

    while (j < atual_produtos) {
        printf("\n\nDigite o código do produto, o preço, armazenamento, nome, o tipo e fornecedor: \n");


        printf("\nCodigo:\n");
        scanf("%li", &pd->codigo);


        printf("\nPreco:\n");
        scanf("%.2f", &pd->preco);

        printf("\nArmazenamento:");
        scanf("%d\n", &pd->armazenamento);
        while(getchar() != '\n');

        printf("\nNome:\n");
        fgets(&pd->nome, lim, stdin);

        printf("\nTipo:\n");
        fgets(&pd->tipo, lim, stdin);

        printf("\nFornecedor:\n");
        fgets(&pd->fornecedor, lim, stdin);

        j++;

	}
	printf("\nCadastros feitos!\nVoltando ao menu.\n");
    return (pd);

}

int alt_fornecedor(fornecedores *fn)
{
	long int x;
	char op;

	while(1){

        printf("\nDigite o código do fornecedor que alterará: \n");
        printf("\n( Para concluir as alterações e voltar ao menu, digite '0' )\n\n");

        scanf("%li", &x);
        getchar();

        if (x == 0) {
            printf("\nVoltando ao menu\n\n");
            main();
        }
        else{

            for ( int i = 0; i < atual_fornecedores; i++)
            { //verifica se o codigo que é buscado é igual ao que já exite no programa

            if( fn[i].codigo == x)
                {
                    printf("Digite os novos dados do fornecedor %li. (codigo, nome, especialidade)\n", x);
                    printf("Para apagar um fornecedor, aperte enter\n");

                    scanf("%li ", &fn[i].codigo);
                    getchar();

                    fgets( fn->nome,lim, stdin );
                    fgets( fn->especialidade,lim, stdin );

                    printf("\nAlteração realizada");

                    return;

                }
            }
                printf("\nFornecedor não encontrado!\n");

        }
    }
}

int alt_produto(produto *pd)
{
	long int x;
	char op;


	while(1){

        printf("\nDigite o código do produto que alterará: \n");
        printf("\n( Para concluir as alterações e voltar ao menu, digite \"0\" )\n");

        scanf("%li", &x);

        if (x == '\0') {
            printf("\nVoltando ao menu\n\n");
            main();
        }
        else{
            for ( int j = 0; j < atual_produtos; j++)
            { //verifica se o codigo que é buscado é igual ao que já exite no programa

            if( pd[j].codigo == x)
                {
                    printf("Digite os novos dados do produto %li. (codigo, nome, especialidade)\n", x);
                    printf("Para apagar um produto, aperte enter\n");

                    scanf("%li", pd->codigo);
                    getchar();

                    fgets( pd->nome,lim, stdin );
                    fgets( pd->tipo,lim, stdin );
                    fgets( pd->fornecedor,lim, stdin );

                    scanf("%d ", pd->armazenamento);
                    getchar();
                    scanf("%.2f ", pd->preco);
                    getchar();

                    printf("\nAlteração realizada");

                    return;

                }
            }
                printf("\nProduto não encontrado!\n");

        }
    }
}

int infoArmazenamento()
{
    printf("\nSelecione: \n");
    printf("1. Refrigerado\n");
    printf("2. Temperatura ambiente\n");
    printf("3. Longe de luz solar\n");
    return 0;
}



int tamanho_estoque(){
    return atual_produtos;
}

int tamanho_fornecedores(){
    return atual_fornecedores;
}

