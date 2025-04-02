#include <stdio.h>
#include <time.h>

// Função para mesclar dois subarrays ordenados
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Tamanho do subarray esquerdo
    int n2 = right - mid;    // Tamanho do subarray direito
    int L[n1], R[n2];       // Arrays temporários para armazenar os elementos
    
    // Copia os elementos para os subarrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Mescla os subarrays de volta no array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para aplicar Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calcula o meio do array
        // Chama recursivamente para as duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // Ordenação básica
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Array original:\n");
    printArray(arr1, size1);
    mergeSort(arr1, 0, size1 - 1);
    printf("Array ordenado:\n");
    printArray(arr1, size1);
    
    // Verificar tempo de execução com 1000 elementos no pior caso
    int arr2[1000];
    for (int i = 0; i < 1000; i++)
        arr2[i] = 1000 - i; // Preenchendo com valores em ordem reversa (pior caso)
    
    clock_t start2, end2;
    double cpu_time_used2;
    
    printf("\nMedindo o tempo de execução do Merge Sort em um array de 1000 elementos...\n");
    start2 = clock();
    mergeSort(arr2, 0, 999);
    end2 = clock();
    
    cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução: %.3f milissegundos\n", cpu_time_used2);

    // Verificar tempo de execução com 10000 elementos no pior caso
    int arr3[10000];
    for (int i = 0; i < 10000; i++)
        arr3[i] = 10000 - i; // Preenchendo com valores em ordem reversa (pior caso)
    
    clock_t start3, end3;
    double cpu_time_used3;
    
    printf("\nMedindo o tempo de execução do Merge Sort em um array de 10000 elementos...\n");
    start3 = clock();
    mergeSort(arr3, 0, 9999);
    end3 = clock();
    
    cpu_time_used3 = ((double) (end3 - start3)) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução: %.3f milissegundos\n", cpu_time_used3);

    // Verificar tempo de execução com 100000 elementos no pior caso
    int arr7[100000];
    for (int i = 0; i < 100000; i++)
        arr7[i] = 100000 - i; // Preenchendo com valores em ordem reversa (pior caso)
    
    clock_t start, end;
    double cpu_time_used;
    
    printf("\nMedindo o tempo de execução do Merge Sort em um array de 100000 elementos...\n");
    start = clock();
    mergeSort(arr7, 0, 99999);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução: %.3f milissegundos\n", cpu_time_used);
    
    return 0;
}