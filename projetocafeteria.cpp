#include <stdio.h>
#include <stdlib.h>


void limparTela() {
    system("cls"); 
}

int main() {

    int opcao;
    char nome[5][50], nomeItem[5][50];
    float preco[5];
    int dia[5], mes[5], quantidade[5], i, totalPedidos = 0;
    char barra[5];

    printf("\n=============== PADARIA MOICANO DELICIAS=============== \n");
    printf("\nSEJA MUITO BEM VINDO(A)!!!\n");
    printf("SEGUE NOSSO MENU ABAIXO:\n");

    do {
    
        printf("\n1 - Para cardapio\n");
        printf("2 - Para gerar pedidos\n");
        printf("3 - Para mostrar pedidos anteriores\n");
        printf("4 - Para atualizar a quantidade do item\n");
        printf("5 - Para salvar pedidos em arquivo\n");
        printf("6 - Para encerrar o sistema\n");
        printf("\nEscolha uma opcao acima: ");

        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {

        case 1:
            printf("CARDAPIO:\n");
            printf("\n============================================ ");
            printf("\n - Bolo de fuba ...............R$ 20,00.");
            printf("\n - Pao de queijo ..............R$ 4,50.");
            printf("\n - Coxinha - ..................R$ 7,00.");
            printf("\n - Cafe - .....................R$ 5,50.");
            printf("\n - Suco de laranja - ..........R$ 5,50.\n");
            printf("============================================ \n");
            break;

        case 2:
            if (totalPedidos < 5) {
                printf("FACA SEU PEDIDO\n");
                
                printf("\nDigite seu nome: ");
                scanf(" %[^\n]", nome[totalPedidos]); 

                printf("\nDigite a data do pedido(ex: 09/07): ");
                scanf("%d%c%d", &dia[totalPedidos], &barra[totalPedidos], &mes[totalPedidos]);

                printf("\nDigite o nome do item: ");
                scanf(" %[^\n]", nomeItem[totalPedidos]);

                printf("\nDigite a quantidade: ");
                scanf("%d", &quantidade[totalPedidos]);

                printf("\nDigite o valor do item: ");
                scanf("%f", &preco[totalPedidos]);

                totalPedidos++;
                printf("\nPedido registrado com sucesso!!!\n");

            } else {
                printf("Limite de pedidos atingido (max. 5).\n");
            }
            break;

        case 3:
            printf("=== PEDIDOS ANTERIORES ===\n");
            if (totalPedidos == 0) {
                printf("Nenhum pedido registrado ainda.\n");
            } else {
                for (i = 0; i < totalPedidos; i++) {
                    printf("\nPedido %d:\n", i + 1);
                    printf("Cliente: %s\n", nome[i]);
                    printf("Data: %02d/%02d\n", dia[i], mes[i]); 
                    printf("Item: %s\n", nomeItem[i]);
                    printf("Quantidade: %d\n", quantidade[i]);
                    printf("Preco: R$ %.2f\n", preco[i]);
                    printf("Total: R$ %.2f\n", preco[i] * quantidade[i]);
                    printf("--------------------------\n");
                }
            }
            break;

        case 4:
            if (totalPedidos == 0) {
                printf("Nenhum pedido registrado. Nao e possivel atualizar a quantidade.\n");
            } else {
                printf("Escolha o pedido que deseja alterar (1 a %d):\n", totalPedidos);
                for (i = 0; i < totalPedidos; i++) {
                    printf("%d - %s: %s | Quantidade: %d | Preco: R$ %.2f\n",
                           i + 1, nome[i], nomeItem[i], quantidade[i], preco[i]);
                }

                int pedidoEscolhido;
                printf("\nDigite o numero do pedido que deseja alterar: ");
                scanf("%d", &pedidoEscolhido);

                if (pedidoEscolhido < 1 || pedidoEscolhido > totalPedidos) {
                    printf("Pedido invalido!\n");
                } else {
                    pedidoEscolhido--; 

                    printf("\nDigite a nova quantidade para o item '%s': ", nomeItem[pedidoEscolhido]);
                    scanf("%d", &quantidade[pedidoEscolhido]);

                    printf("Quantidade atualizada com sucesso!\n");
                    printf("Novo total do pedido: R$ %.2f\n", preco[pedidoEscolhido] * quantidade[pedidoEscolhido]);
                }
            }
            break;

        case 5:
            if (totalPedidos == 0) {
                printf("Nenhum pedido para salvar.\n");
            } else {
                FILE *arquivo;
                arquivo = fopen("pedidos.txt", "w");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo!\n");
                } else {
                    fprintf(arquivo, "=== LISTA DE PEDIDOS SALVOS ===\n\n");
                    for (i = 0; i < totalPedidos; i++) {
                        fprintf(arquivo, "Pedido %d:\n", i + 1);
                        fprintf(arquivo, "Cliente: %s\n", nome[i]);
                        fprintf(arquivo, "Data: %02d/%02d\n", dia[i], mes[i]);
                        fprintf(arquivo, "Item: %s\n", nomeItem[i]);
                        fprintf(arquivo, "Quantidade: %d\n", quantidade[i]);
                        fprintf(arquivo, "Preco: R$ %.2f\n", preco[i]);
                        fprintf(arquivo, "Total: R$ %.2f\n", preco[i] * quantidade[i]);
                        fprintf(arquivo, "------------------------------------------\n");
                    }
                    fclose(arquivo);
                    printf("Pedidos salvos com sucesso no arquivo 'pedidos.txt'.\n");
                }
            }
            break; 

        case 6:
            printf("Saindo do programa...\n");
            printf("Agradecemos a sua visita! Ate logo!\n\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}