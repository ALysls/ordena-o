/* Apresente uma função em C++ que implementa o algoritmo de intercalação do 
   método de ordenação por intercalação. A função deve ordenar os dados de um 
   vetor em ordem crescente e deve apresentar para o usuário todas as trocas realizadas. */

#include <iostream>
using namespace std;

void ord(int vetor[], int inicio, int meio, int fim, int tamanho)
{
    int sub1 = meio - inicio + 1;
    int sub2 = fim - meio;
    
    int l[sub1 + 1];   // subarranjo com dado final infinito 
    int r[sub2 + 1];
    
    for (int i = 0; i < sub1; i++)
    {
        l[i] = vetor[inicio + i];   // copia os dados para o sub l
    }
    
    for (int j = 0; j < sub2; j++)
    {
        r[j] = vetor[meio + 1 + j];   // copia os dados para o sub r
    }
    
    // definir o valor da ultima posição de cada um dos subs com função que define o maior valor em c++
    l[sub1] = numeric_limits<int>::max();
    r[sub2] = numeric_limits<int>::max();  
    
    // definir os indices começando para começar a comparação
    int i = 0; 
    int j = 0;
    int k = inicio;
    
    while (i < sub1 && j < sub2)
    {      
        // a cada execução vai ser comparado um dado de l com um dado de r 
        if (l[i] <= r[j])
        {
            vetor[k] = l[i];
            cout << "\n";
            for (int i = 0; i < tamanho; i++)
            {
              cout << vetor[i] << " - ";
            }
            i++;   
        }
        else 
        {
            vetor[k] = r[j];
            cout << "\n";
            for (int i = 0; i < tamanho; i++)
            {
              cout << vetor[i] << " - ";
            }
            j++;
        }
        k++;
    }
// copiar os elementos restantes
    while (i < sub1)
    {
        vetor[k] = l[i];
        i++;
        cout << "\n";
        for (int i = 0; i < tamanho; i++)
        {
          cout << vetor[i] << " - ";
        }
        k++;
    }
    while (j < sub2)
    {
        vetor[k] = r[j];
        j++;
        cout << "\n";
        for (int i = 0; i < tamanho; i++)
        {
          cout << vetor[i] << " - ";
        }
        k++;
    }
}

void saidaVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << " - ";
    }
}

void mergeSort(int vetor[], int inicio, int fim, int tamanho)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio)/2;
        
        mergeSort(vetor, inicio, meio, tamanho);
        mergeSort(vetor, meio + 1, fim, tamanho);

        ord(vetor, inicio, meio, fim, tamanho);
    }
}

int main()
{  
    int a[] = {3, 9, 19, 7, 3, 1};
    int tam = sizeof(a)/sizeof(a[0]);

    cout << "\nVetor desordenado: \n";
    saidaVetor(a, tam);

    cout << "\n\nOrdenando... \n";
    mergeSort(a, 0, tam - 1, tam);
    
    cout << "\n\nVetor ordenado por intercalacao: \n";
    saidaVetor(a, tam);    
}


/* Apresente uma função em C++ que implementa o método de ordenação por inserção. 
   A função deve ordenar os dados de um vetor em ordem crescente e deve apresentar para o usuário todas as trocas realizadas.*/


#include <iostream>
using namespace std;

void insertion_sort (int vetor[], int tam){  // arranjo de dados e tamanho do vetor
    
    int key, j;
    
    cout << "\n\nOrdenando... \n";
    
    for (int i = 1; i < tam; i++){   // começa no segundo dado do vetor, indice 1
        
        key = vetor[i];    // armazena a chave que está sendo verificada
        j = i - 1;     // checagem com o indice anterior 
        
        while ((j >= 0) && (vetor[j] > key)){    // enquanto o anterior for menor ele passa pra frente
            
            vetor[j+1] = vetor[j];
            j--;
            
            cout << "\n";
            for (int i = 0; i < tam; i++)
            {
              cout << vetor[i] << " - ";
            }
            
        }
        
        vetor[j+1] = key;   // colocar o dado chave na posição correta
        
        cout << "\n";
        for (int i = 0; i < tam; i++)
        {
          cout << vetor[i] << " - ";
        }
    }
}


void saidaVetor(int vetor[], int tamanho)
{
     for (int i = 0; i < tamanho; i++){
      cout << vetor[i] << " - ";
    }
}



int main(){
  
    int a[] = {3, 9, 0, 7, 4, 1};
    int tam = sizeof(a)/sizeof(a[0]);

    cout << "\nVetor desordenado: \n";
    saidaVetor(a, tam);
    
    insertion_sort(a, tam);
    
    cout << "\n\nVetor ordenado por insercao: \n";
    saidaVetor(a, tam);
    
    
  }





// Aula 14

// ordenação por inserção
void insertion_sort (int *& vetor, int tam){  // arranjo de dados e tamanho do vetor
    
    int key, j;
    
    for (int i = 1; i < tam; i++){   // começa no segundo dado do vetor, indice 1
        
        key = vetor[i];    // armazena a chave que está sendo verificada
        j = i - 1;     // checagem com o indice anterior 
        
        while ((j >= 0) && (vetor[j] > key)){    // enquanto o anterior for menor ele passa pra frente
            
            vetor[j+1] = vetor[j];
            j--;
            
        }
        
        vetor[j+1] = key;   // colocar o dado chave na posição correta
    }
}

// Aula 16

// ordenação por intercalação
// divide a sequência de n elementos em 2 subseq de n/2 elementos; 
// ordena as 2 sub recursivamente, utilizando a ordenação por intercalação
// intercala as 2 sub ordenadas

// é algoritmo que recebe um conjunto de dados A, composto por n elementos
// recebe 3 info: p = armazena o índice do 1º dado do arranjo; q = índice do meio; r = índice final;
// p <= q < r;
// A[p...q] e A[q+1...r] ordenados, serão intercalados 

void ord_intercalacao (int *& vetor, int inicio, int meio, int fim){
    
    int sub1 = meio - inicio + 1;
    int sub2 = fim - meio;
    
    int * l = new int [sub1 + 1];   // subarranjo com dado final infinito 
    int * r = new int [sub2 + 1];
    
    for (int i = 0; i < sub1; i++){
        l[i] = vetor[inicio + i];   // copia um dado do vetor A para o sub l
    }
    
    for (int j = 0; j < sub2; j++){
        r[j] = vetor[meio + j];   // copia os dados para o sub r
    }
    
    // definir o valor de infinito na ultima posição de cada um dos subs
    l[sub1] = numeric_limits<int>::max();
    r[sub2] = numeric_limits<int>::max();   // função que define o maior valor de c++
    
    // definir os indices começando para começar a comparação
    int i = 0; 
    int j = 0;
    
    for (int k = inicio; k <= fim; k++){   // variando do indice final ao inicial
        
        // a cada execução vai ser comparado um dado de l com um dado de r
        
        if (l[i] <= r[j]){
            vetor[k] = l[i];
            i++;
        }
        
        else {
            vetor[k] = r[j];
            j++;
        }
    }
}
