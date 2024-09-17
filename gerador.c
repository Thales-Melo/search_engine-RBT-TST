#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função para gerar uma palavra aleatória de tamanho variável
void gerar_palavra_aleatoria(char *palavra, int tamanho_min, int tamanho_max) {
    int tamanho = rand() % (tamanho_max - tamanho_min + 1) + tamanho_min; // Gera tamanho aleatório entre tamanho_min e tamanho_max
    for (int i = 0; i < tamanho; i++) {
        palavra[i] = 'a' + rand() % 26; // Gera letras de 'a' a 'z'
    }
    palavra[tamanho] = '\0'; // Adiciona o caractere nulo para terminar a string
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com a hora atual

    // Abrir arquivo index.txt para leitura:
    FILE *arquivo_entrada = fopen("exemplo/index.txt", "r");
    
    // Verificar se houve erro na abertura do arquivo:
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir arquivo de leitura\n");
        return 1;
    }

    // Ler uma linha por vez até chegar ao final do arquivo:
    char linha[101]; // Buffer para armazenar a linha lida
    char caminho[151]; // Buffer para armazenar o caminho do arquivo
    while (fgets(linha, 101, arquivo_entrada) != NULL) {
        // Remover o caractere de quebra de linha do final da linha lida:
        linha[strcspn(linha, "\n")] = '\0';

        // Construir o caminho do arquivo a partir do nome lido:
        sprintf(caminho, "exemplo/pages/%s", linha);

        // Abrir arquivo lido para gerar palavras aleatórias:
        FILE *arquivo_escrita = fopen(caminho, "a");

        // Verificar se houve erro na abertura do arquivo:
        if (arquivo_escrita == NULL) {
            printf("Erro ao abrir arquivo de escrita\n");
            return 1;
        }

        // Gerar palavras aleatórias e escrever no arquivo:
        int num_palavras = 2000; // Número de palavras a serem geradas
        int tamanho_min = 3;  // Tamanho mínimo de cada palavra
        int tamanho_max = 10; // Tamanho máximo de cada palavra

        // Loop para gerar e imprimir palavras aleatórias
        for (int i = 0; i < num_palavras; i++) {
            char palavra[tamanho_max + 1]; // Buffer para armazenar a palavra gerada
            gerar_palavra_aleatoria(palavra, tamanho_min, tamanho_max);
            fprintf(arquivo_escrita, "%s ", palavra);
            if (i > 0 && i % 10 == 0) {
                fprintf(arquivo_escrita, "\n");
            }
        }

        fclose(arquivo_escrita); // Fechar arquivo
    }

    fclose(arquivo_entrada); // Fechar arquivo

    return 0;
}
