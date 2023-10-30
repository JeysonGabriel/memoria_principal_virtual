#include <stdio.h>
#include <stdlib.h>

// Tamanho da página em bytes
#define PAGE_SIZE 256 // 256 bytes

// Função para calcular o número da página e o deslocamento
void translateAddress(unsigned int virtualAddress, unsigned int pageSize) {
    unsigned int pageNumber = virtualAddress / pageSize;
    unsigned int offset = virtualAddress % pageSize;

    printf("/nO endereco %u contem:\n", virtualAddress);
    printf("Numero da pagina = %u\n", pageNumber);
    printf("Deslocamento = %u\n", offset);

    // Abra o arquivo "data_memory.txt" para leitura
    FILE *dataMemoryFile = fopen("C:/Users/jeyso/OneDrive/Área de Trabalho/Trabalho viel/data_memory.txt", "r");
    if (dataMemoryFile == NULL) {
        perror("Erro ao abrir data_memory.txt");
        exit(1);
    }

    // Desloque o ponteiro de arquivo para a posição correta
    fseek(dataMemoryFile, pageNumber * pageSize, SEEK_SET);

    // Leia o valor da posição correta
    unsigned int value;
    fscanf(dataMemoryFile, "%u", &value);

    printf("Valor lido = %u\n", value);

    // Feche o arquivo "data_memory.txt"
    fclose(dataMemoryFile);
}

int main() {
    // Abra o arquivo "addresses_16b.txt" para leitura
    FILE *addressesFile = fopen("C:/Users/jeyso/OneDrive/Área de Trabalho/Trabalho viel/addresses_16b.txt", "r");
    if (addressesFile == NULL) {
        perror("Erro ao abrir addresses_16b.txt");
        return 1;
    }

    unsigned int virtualAddress;

    while (fscanf(addressesFile, "%u", &virtualAddress) != EOF) {
        translateAddress(virtualAddress, PAGE_SIZE);
    }

    // Feche o arquivo "addresses_16b.txt"
    fclose(addressesFile);

    return 0;
}
