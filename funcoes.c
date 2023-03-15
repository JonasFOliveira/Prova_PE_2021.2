/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
//>================== LIMPEZA E ORGANIZACAO DO CODIGO: ==================

/*Funcao clear realiza a limpeza nas notas. 
Notas maiores que 10 transforma em 10 e notas menores que 0 em 0
    > int *notas = array de notas 
    > int n = tamanho do array
*/
void clear(int *notas, int n){
    for (int i = 0; i < n; i++){
        if (notas[i] > 10){
            notas[i] = 10;
        }
        if (notas[i] < 0){
            notas[i] = 0;
        }
    }
}

/*Utilizando o metodo de bubble sorte a funcao ord organiza o array de notas por ordem crescente
    > int *notas = array de notas 
    > int n = tamanho do array
*/
void ord(int *notas, int n){
    int temp = 0;
    int troca;
    do{
        troca = 0; //a variavel troca indica se houve uma troca de valores na ordencao (inicia False)
        for(int i = 0; i < n-1; i++){ //percorre todos os elementos do array 
            if (notas[i] > notas[i+1]){ //se o valor do array for menor que o proximo ele realiza a troca
                temp = notas[i];
                notas[i] = notas[i+1];
                notas[i+1] = temp;
                troca = 1; //como houve troca a variavel "troca" recebe True
            }
        }
    }while(troca);  //enquanto houver trocas essa ordenacao e executada
}

//>================== FUNCOES MATEMATICAS: ==================

/*Esta funcao realiza o calculo do desvio padrao 
(sqrt((somatorio((valor individual - valor medio)^2))/numero de valores))
    > int *notas = array de notas 
    > int n = tamanho do array
*/
float desvio_padrao(int *notas, int n){
    //int *notas = array de notas | int n = tamanho do array
    float soma = 0, m;
    m = media(notas, n);

    for (int i=0; i<n; i++)
        soma += pow((notas[i]-m), 2);
    
    soma /= n;

    return sqrt(soma);
}

/*Retorna a media dos valores do array
    > int *notas = array de notas 
    > int n = tamanho do array
*/
float media(int *notas, int n){
    float soma = 0;

    for (int i = 0; i < n; i++)
        soma += notas[i];
    
    return soma/n;
}

/*Essa funcao retorna o valor da mediana
    > int *notas = array de notas 
    > int n = tamanho do array
*/
float mediana(int *notas, int n){
    if (n%2 == 0)
        return (notas[n/2-1] + notas[n/2])/2.0;//Se o array for de tamanho par retorna a media entre os valores centrais do array
    if (n%2 == 1)
        return notas[n/2]; //Se o array for de tamanho impar retorna a valor central do array
}

/*Essa funcao retorna um array constando a quantidade de repetições de um numero apos ele em um array
    Ex.: (1,2,2,3,5) => (0,1,0,0,0) *o numero 2 repete-se uma vez no array
    > *notas =  array de notas 
    > int i = index a ser analizado
*/ 
int repeticoes_nota(int *notas, int i){
    //int 
    if (notas[i] != notas[i+1]) // verificando se o proximo valor e igual o anterior, se nao, return 0
        return 0;
    if (notas[i] == notas[i+1]) // se o valor for igual ele testa o proximo erealiza a soma de todos os valores iguais apos esse
        return 1 + repeticoes_nota(notas, i+1);
}


/*Retorna um array com a(s) moda(s) dos valores de nota e seu tamanho
    > int *notas  array de notas 
    > int n = tamanho do array 
    > int *tm = ponteiro que informa o tamanho do array moda
*/
int *moda(int *notas, int n, int *tm){

    int modas[n], *modas_limpas, counts[n], maior_repeticao = 0, repeticoes = 0;

    // Preenchendo o array counts com a quantidade de vezes que cada número se repete no array notas
    
    for(int i=0; i<n-1; i++)
        counts[i] = repeticoes_nota(notas, i);
    counts[n-1] = 0;

    // Verificando qual é a maior repetição que ocorre no array

    for(int i=0; i<n; i++)
        if (counts[i] > maior_repeticao)
            maior_repeticao = counts[i];

    // Verificando quantos valores de nota se repetem mais
    // e adicionando-os a um array de modas

    for(int i=0; i<n; i++){
        if (counts[i] == maior_repeticao){
            modas[i] = notas[i];
            repeticoes++;
        }
        else modas[i] = -1;
    }

    // A variavel repeticoes representa o tamanho do array final
    // Retornando-a para a função main usando um ponteiro

    *tm = repeticoes; 
    
    // Criando o array final que a função retorna
    
    modas_limpas = malloc(sizeof(int)*repeticoes);

    for(int i=0, j=0; i<n; i++){
        if (modas[i] != -1){
            modas_limpas[j] = modas[i];
            j++;
        }
    }

    return modas_limpas;
}

/*Verifica qual o maior valor do array
    > int *notas = array de notas
    > int n = tamanho do array
*/
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

/*Verifica qual o menor valor do array
    > int *notas = array de notas
    > int n = tamanho do array
*/
int valor_minimo(int *notas, int n){
    int menor = 10;

    for (int i = 0; i < n; i++){
        if (notas[i] == 0) // Como 0 e o menor valor, ao encontrar um 0 ele encerra a funcao e retorna 0
            return 0;
        if (notas[i] < menor) //Se nao, ele retorna o menor valor encontrado
            menor = notas[i];
        }
    return menor;
}   

//>================== VISUALIZACAO: ==================

/*Exibe na tela um histograma dos valores fornecidos no array
    > int *notas = array de notas que ter a o histograma apresentado 
    > int n = tamanho do array de notas 
    > int axis = orientacao da tabela (0 para vertical, 1 para horizontal) 
*/
void plot_hist(int *notas, int n, int axis){
    int freq[11] = {0}; //Criando um array que vai possuir as frequencia das notas que variam de 0 a 10
    for(int i = 0; i < n; i++){
        freq[notas[i]]++; // Incrementa na posicaoreferente a nota no array freq 
    }
    printf("--------- Histograma ---------\n"); // Insere o histograma na tela

    if(axis){
        int hist[11][11];

        for(int i = 0; i < 11; i++){
            for (int j = 0; j < freq[i]; j++){
                hist[i][j] = 1;
            }
            for (int j = freq[i]; j < 11; j++){
                hist[i][j] = 0;
            }
        }
        
        for (int i = valor_maximo(freq, 11), j; i >= 0; i--){
            printf("\t");
            for (j = 0; j < 11; j++){
                if(hist[j][i])
                    printf("◼ ");
                else
                    printf("  ");

            }
            printf("\n");
        }
        printf("notas\t");
        for (int i = 0; i < 11; i++)
        {
            printf("%d ", i);
        }
    
    }else{
        for (int i = 0; i < 6; i++){ 
            printf("%.2d|",i); // Insere a nota que tera sua frequencia exibida
            for (int j = 0; j < freq[i]; j++){
                printf("◼"); // Insere um "◼" para cada contador da frequencia
                //Ex.: 1 (aparecendo 5 vezes)| ◼◼◼◼◼
            }
            printf("\t(:c)\n"); //Notas abaixo de 6 recebem  rostinhos tristes
        }
        // Insere a frequencia do restante dos valores
        for (int i = 6; i < 11; i++){
        printf("%.2d|",i);
        for (int j = 0; j < freq[i]; j++){
            printf("◼");
        }
        printf("\t(:D)\n"); //Notas a partir de 6 recebem um rostinho feliz
        }
    }
}

/*Funcao que printa qualquer array de uma dimensao na tela
    > int *array = array de uma dimensao que sera mostrado na tela 
    > int n = tamanho do array
*/ 
void printar_arrays(int *array, int n){
    // int *array = array a ser printado | int n = tamanho do array
    for(int i=0; i<n; i++)
        printf("%d ", array[i]);
    putchar('\n');
}