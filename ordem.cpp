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

