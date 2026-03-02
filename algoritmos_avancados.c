// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Struct: Sala
Representa cada cômodo da mansão.
Cada sala possui:
- nome
- ponteiro para esquerda
- ponteiro para direita
*/
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

/*
Função: criarSala()
Cria dinamicamente uma nova sala com o nome informado.
Inicializa os ponteiros como NULL.
*/
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*) malloc(sizeof(Sala));

    if (novaSala == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

/*
Função: explorarSalas()
Permite que o jogador explore a mansão a partir da sala atual.
O jogador pode escolher:
e - ir para esquerda
d - ir para direita
s - sair do jogo

A exploração continua até:
- o jogador escolher sair
- chegar em uma sala sem filhos (nó-folha)
*/
void explorarSalas(Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Verifica se é um nó-folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este cômodo não possui mais caminhos.\n");
            printf("Fim da exploração!\n");
            break;
        }

        printf("Escolha um caminho:\n");
        printf("e - esquerda\n");
        printf("d - direita\n");
        printf("s - sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Não há caminho à esquerda!\n");
            }
        }
        else if (opcao == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Não há caminho à direita!\n");
            }
        }
        else if (opcao == 's') {
            printf("Exploração encerrada pelo jogador.\n");
            break;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

/*
Função: liberarMapa()
Libera toda a memória alocada para a árvore.
*/
void liberarMapa(Sala* raiz) {
    if (raiz != NULL) {
        liberarMapa(raiz->esquerda);
        liberarMapa(raiz->direita);
        free(raiz);
    }
}

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

/*
Função principal: main()

- Monta manualmente o mapa da mansão
- Inicia a exploração a partir do Hall de Entrada
*/
int main() {

    // Criação das salas
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* jardim = criarSala("Jardim");
    Sala* quarto = criarSala("Quarto Secreto");
    Sala* porao = criarSala("Porão Misterioso");

    // Montagem da árvore (mapa fixo)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;

    cozinha->esquerda = quarto;
    cozinha->direita = porao;

    printf("=== Detective Quest ===\n");
    printf("Explore a mansão e descubra seus mistérios!\n");

    // Inicia exploração
    explorarSalas(hall);

    // Libera memória
    liberarMapa(hall);

    return 0;
}

//========================================================================

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().
