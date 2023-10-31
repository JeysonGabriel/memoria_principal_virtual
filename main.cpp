#include <stdio.h>
#include <stdlib.h>

// Tamanho da página em bytes
#define TAMANHO_PAGINA 256 

// Função para calcular o número da página e o deslocamento
void traduzirEndereco(unsigned int enderecoVirtual, unsigned int tamanhoPagina) {
    unsigned int numeroPagina = enderecoVirtual / tamanhoPagina;
    unsigned int deslocamento = enderecoVirtual % tamanhoPagina;

    printf("\nO endereco %u contem:\n", enderecoVirtual);
    printf("Numero da pagina = %u\n", numeroPagina);
    printf("Deslocamento = %u\n", deslocamento);

    // Abertura do arquivo "data_memory.txt" para leitura
    FILE *arquivoMemoriaDados = fopen("C:/Users/jeyso/OneDrive/Área de Trabalho/Trabalho viel/data_memory.txt", "r");
    if (arquivoMemoriaDados == NULL) {
        perror("Erro ao abrir data_memory.txt");
        exit(1);
    }

    // Deslocamento do ponteiro de arquivo para a posição correta
    fseek(arquivoMemoriaDados, numeroPagina * tamanhoPagina, SEEK_SET);

    // Leitura do valor da posição correta
    unsigned int valor;
    fscanf(arquivoMemoriaDados, "%u", &valor);

    printf("Valor lido = %u\n", valor);

    // Fechamento do arquivo "data_memory.txt"
    fclose(arquivoMemoriaDados);
}

int main() {
    
    // Abertura do arquivo "addresses_16b.txt" para leitura
    FILE *arquivoEnderecos = fopen("C:/Users/jeyso/OneDrive/Área de Trabalho/Trabalho viel/addresses_16b.txt", "r");
    if (arquivoEnderecos == NULL) {
        perror("Erro ao abrir addresses_16b.txt");
        return 1;
    }

    unsigned int enderecoVirtual;

    while (fscanf(arquivoEnderecos, "%u", &enderecoVirtual) != EOF) {
        traduzirEndereco(enderecoVirtual, TAMANHO_PAGINA);
    }

    // Fechamento do arquivo "addresses_16b.txt"
    fclose(arquivoEnderecos);

    return 0;
}
