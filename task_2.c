/*Написать программу, которая принимает размер произвольного массива, создает его, 
заполняет случайными числами с плавающей точкой в интервале (0, 1). 
Выводит этот массив в консоль и записывает в файл в отсортированном виде*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для вывода массива чисел с плавающей точкой в консоль
void printArray(float *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", arr[i]);  
    }
    printf("\n");
}

// Функция для записи массива чисел с плавающей точкой в файл
void writeArrayToFile(float *arr, int size, const char *filename) {
    // Открытие файла для записи в режиме "w"
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        // Вывод сообщения об ошибке и завершение программы, если не удалось открыть файл
        printf("ERROR of openning input file\n");
    exit(EXIT_FAILURE);
    }

    // Запись элементов массива в файл, каждый элемент с новой строки
    for (int i = 0; i < size; i++) {
        fprintf(file, "%f\n", arr[i]);
    }

    // Закрытие файла
    fclose(file);
}

// Функция для сравнения чисел с плавающей точкой для использования в qsort
int compareFloats(const void *a, const void *b) {
    float diff = *(float *)a - *(float *)b;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

// Главная функция программы
int main() {
    // Переменная для хранения размера массива
    int size;

    // Запрос у пользователя ввода длины массива
    printf("input array len: ");
    scanf("%d", &size);

    // Выделение памяти под массив с использованием malloc
    float *arr = (float *)malloc(size * sizeof(float));

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение массива случайными числами от 0 до 1 (числа с плавающей точкой)
    for (int i = 0; i < size; i++) {
        arr[i] = (float)rand() / RAND_MAX;
    }

    // Вывод массива случайных чисел в консоль
    printf("array of random nums:\n");
    printArray(arr, size);

    // Сортировка массива с использованием qsort
    qsort(arr, size, sizeof(float), compareFloats);

    // Имя файла для записи
    const char *filename = "output.txt";

    // Запись отсортированного массива в файл
    writeArrayToFile(arr, size, filename);

    // Вывод сообщения о том, что данные записаны в файл в отсортированном порядке
    printf("written to '%s' sorted\n", filename);

    // Освобождение выделенной памяти для массива
    free(arr);

    // Возврат из главной функции с кодом успешного завершения
    return 0;
}