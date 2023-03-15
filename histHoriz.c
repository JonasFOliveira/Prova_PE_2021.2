#include <stdio.h>

//>> funcao clear realiza a limpeza nas notas. Notas maiores que 10 transforma em 10 enotas menor que 0 em 0
void clear(int *notas, int n){
    //int *notas = array de notas | int n = tamanho do array
    for (int i = 0; i < n; i++){
        if (notas[i] > 10){
            notas[i] = 10;
        }
        if (notas[i] < 0){
            notas[i] = 0;
        }
    }
}

int valor_maximo(int *notas, int n){
    //int *notas = array de notas | int n = tamanho do array
    int maior = 0;

    for (int i = 0; i < n; i++){
        if (notas[i] == 10) // Como 10 e o maior valor, ele retorna 10 e encerra a funcao
            return 10;
        if (notas[i] > maior) // Se nao houver um 10 ele vai retornar o maior valor presete no array
            maior = notas[i];
    }

    return maior;
}

void Horiz(int *notas, int n){
//int *notas = array de notas que ter a o histograma apresentado | int n = tamanho do array de notas
    int freq[11] = {0}; //Criando um array que vai possuir as frequencia das notas que variam de 0 a 10
    for(int i = 0; i < n; i++){
        freq[notas[i]]++; // Incrementa na posicaoreferente a nota no array freq 
    }

    int hist[n][n];

    for(int i = 0; i < n; i++){
        for (int j = 0; j < freq[i]; j++){
            hist[i][j] = 1;
        }
        for (int j = freq[i]; j < n; j++){
            hist[i][j] = 0;
        }
    }
    
    for (int i = n-(n-valor_maximo(freq, 11)), j; i >= 0; i--){
        printf("\t");
        for (j = 0; j < n; j++){
            if(hist[j][i])
                printf("◼ ");
            else
                printf("  ");

        }
        printf("\n");
    }
    printf("notas\t");
    for (int i = 0; i < 11; i++){
        printf("%d ", i);
    }

}


int main(){
    int notas[13] = {5, 3, 3, 8, 7, 10, 10, -5, 2, 7, 12, 9, 10};
    int *modas;
    int n = 13; //tamanho do array notas

    clear(notas, n);
    plot_histHoriz(notas, n);
}