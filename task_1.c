/*Написать программу, которая генерирует массив из псевдослучайных целых чисел
 и выводит его в консоль в прямом порядке, и записывает в файл в обратном порядке.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для вывода элементов массива
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    // Запрос пользователя на ввод размера массива
    printf("Input array length: ");
    scanf("%d", &size);

    // Выделение динамической памяти под массив
    int *arr = (int *)malloc(size * sizeof(int));

    // Инициализация генератора случайных чисел текущим временем
    srand(time(0));

    // Заполнение массива случайными числами от 0 до 99
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; 
    }

    // Вывод исходного массива
    printf("Original order:\n");
    printArray(arr, size);

    // Имя файла для записи данных
    char *filename = "output.txt";

    // Открытие файла для записи
    FILE *file = fopen(filename, "w");

    // Проверка успешного открытия файла
    if (file == NULL) {
        printf("ERROR: Unable to open the file\n");
        exit(EXIT_FAILURE);
    }

    // Запись элементов массива в обратном порядке в файл
    for (int i = size - 1; i >= 0; i--) {
        fprintf(file, "%d ", arr[i]);
    }

    // Закрытие файла
    fclose(file);

    // Вывод сообщения об успешной записи в файл
    printf("Data written to '%s' in reversed order\n", filename);

    // Освобождение выделенной памяти для массива
    free(arr);

    return 0;
}
