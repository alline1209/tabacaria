/* 
    Arquivo: cadastro.c
    Autor: Alline e Mateus
    Contém as funções utilizadas nas rotinas de cadastro da tabacaria
 */

#include "cadastro.h"

/* variaveis globais que controlam o tamanho dos vetores alocados */
int TAM_MAX_PRODUTOS = 0, TAM_ATUAL_PRODUTOS = 0;
int TAM_MAX_FORNECEDORES = 0, TAM_ATUAL_FORNECEDORES = 0;


/*  lê produtos da entrada padrão e cadastra-os no estoque */
produto * cad_produto (produto * estoque)
{
    int i, quantidade;

    printf("Digite a quantidade de produtos a serem cadastrados");
    scanf("%d", &quantidade);

    // se o estoque ainda nao tiver sido alocado
    if (TAM_MAX_PRODUTOS == 0)
    {
        estoque =  malloc (quantidade * sizeof(produto));
        TAM_MAX_PRODUTOS = quantidade;
        TAM_ATUAL_PRODUTOS = quantidade;   
        i = 0;
    }

    // Se ja existir um estoque na memoria
    else
    {
        // caso haja espaço no vetor, insira no final
        if(TAM_MAX_PRODUTOS - TAM_ATUAL_PRODUTOS > quantidade)
        {
            i = TAM_ATUAL_PRODUTOS;
            TAM_ATUAL_PRODUTOS += quantidade;
        }
        // caso não haja, realoque
        else
        {
            i = TAM_ATUAL_PRODUTOS;
            TAM_ATUAL_PRODUTOS += quantidade;
            TAM_MAX_PRODUTOS = TAM_ATUAL_PRODUTOS;
            estoque = realloc (estoque, (TAM_ATUAL_PRODUTOS + quantidade) * sizeof(produto));
        }
    }
    
	while(i < TAM_ATUAL_PRODUTOS)
    {
        printf("\nDigite o código, preço de compra, preço de venda, armazenamento, nome do produto, o tipo, o fornecedor do produto:\n");
	    scanf ("%li %f %f %d ", &estoque[i].codigo, &estoque[i].preco_compra, &estoque[i].preco_venda , &estoque[i].armazenamento);
        fgets (estoque[i].nome, lim, stdin);
	    fgets (estoque[i].tipo, lim, stdin);
        fgets (estoque[i].fornecedor, lim, stdin);
        printf("\n %li %f %d\n", estoque[i].codigo, estoque[i].preco_compra, estoque[i].armazenamento);
        i++;
    }       
    printf("Total de Cadastros no estoque: %d.\n Voltando ao menu.\n",tamanho_estoque());
 
 return(estoque);
}

/* le fornecedores e insere-os no cadastro de fornecedores
    retorna o endereco do cadastro */
fornecedores * cad_fornecedor(fornecedores * cadastro)
{
	int i = 0, quantidade;
    
    printf("Digite a quantidade de fornecedores a serem cadastrados");
    scanf("%d", &quantidade);
    printf("%d", quantidade);

// Se ja existir um estoque na memoria
    if (tamanho_fornecedores() == 0)
    {   
        free(cadastro);
        cadastro =  malloc(quantidade * sizeof(fornecedores));    
        TAM_MAX_FORNECEDORES = quantidade;
        TAM_ATUAL_FORNECEDORES = quantidade;
        i = 0;
    }
    // se o cadastro de fornecedores ja estiver alocado
    else
    {
        // caso haja espaço no vetor, insira no final
        if (TAM_MAX_FORNECEDORES - TAM_ATUAL_FORNECEDORES > quantidade)
        {
            i = TAM_ATUAL_FORNECEDORES;
            TAM_ATUAL_FORNECEDORES += quantidade;
        }
        // caso não haja, realoque
        else
        {
            i = TAM_ATUAL_FORNECEDORES;
            TAM_ATUAL_FORNECEDORES += quantidade;
            TAM_MAX_FORNECEDORES = TAM_ATUAL_FORNECEDORES;
            cadastro = realloc (cadastro, (TAM_ATUAL_FORNECEDORES + quantidade) * sizeof(fornecedores));
        }
    }
    // preenche os fornecedores
	while(i < tamanho_fornecedores())
    {
        printf("\nDigite o codigo do fornecedor, o nome e a especialidade: \n");

        scanf("%li ", &cadastro[i].codigo); 
        fgets (cadastro[i].nome,lim, stdin );
        fgets (cadastro[i].especialidade,lim, stdin );
        i++;
        
    }
    printf("Cadastrou %d fornecedor(es)!",i);
    return cadastro;
}

// remove um produto a partir de seu codigo e retorna-o
// se prod.codigo == 0 no retorno, nao removeu ninguem.
produto removeProduto(produto * estoque, long int codigo)
{
    produto chave = {.codigo = 0};
    for(int i = 0; i < TAM_ATUAL_PRODUTOS; ++i)
    {
        // achou o produto
        if(codigo == estoque[i].codigo)
        {
            chave = estoque[i];
            TAM_ATUAL_PRODUTOS--;
            // reposiciona o resto do vetor
            for (int k = i; k < TAM_ATUAL_PRODUTOS; ++k)
                estoque[k] = estoque[k+1];           
        }
    }
    return chave;
}

void imprime_estoque(produto * estoque)
{
    for (int i = 0; i < TAM_ATUAL_PRODUTOS; i++)
        printf("%s \n",estoque[i].nome);
}

int tamanho_estoque(){
    return TAM_ATUAL_PRODUTOS;
}

int tamanho_fornecedores(){
    return TAM_ATUAL_FORNECEDORES;
}
