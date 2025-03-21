/*Создать структуру для хранения данных о названии и цене товара. Считать из входного файла данные о товарах. 
Написать функцию для сортировки товаров по цене. Вывести отсортированные данные в выходной файл.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} 

Product;

// Функция сравнения для qsort, сравнивающая продукты по их ценам
int comparePrices(const void *a, const void *b) {
    const Product *productA = (const Product *)a;
    const Product *productB = (const Product *)b;

    // Если цена продукта A меньше цены продукта B, возвращаем -1
    // Если цена продукта A больше цены продукта B, возвращаем 1
    // Если цены равны, возвращаем 0
    if (productA->price < productB->price) {
        return -1;
    } else if (productA->price > productB->price) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *inputFile = "input.txt";
    char *outputFile = "output.txt";
    // Открываем файл для чтения
    FILE *file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("error\n");
        return 1;
    }

    int size;
    // Читаем количество продуктов из файла
    fscanf(file, "%d", &size);
    // Выделяем память под массив продуктов
    Product *products = (Product *)malloc(size * sizeof(Product));

    // Читаем информацию о продуктах из файла
    for (int i = 0; i < size; i++) {
        fscanf(file, "%s %f", products[i].name, &products[i].price);
    }

    // Закрываем файл
    fclose(file);

    // Выводим несортированную информацию о продуктах
    printf("before:\n");
    for (int i = 0; i < size; i++) {
        printf("product: %s, price: %.2f\n", products[i].name, products[i].price);
    }

    // Сортируем продукты по цене с использованием qsort
    qsort(products, size, sizeof(Product), comparePrices);

    // Выводим отсортированную информацию о продуктах
    printf("after:\n");
    for (int i = 0; i < size; i++) {
        printf("product: %s, price: %.2f\n", products[i].name, products[i].price);
    }

    // Открываем файл для записи отсортированной информации о продуктах
    FILE *file2 = fopen(outputFile, "w");
    if (file2 == NULL) {
        printf("error \n");
        return 1;
    }

    // Записываем отсортированную информацию о продуктах в файл
    for (int i = 0; i < size; i++) {
        fprintf(file2, "product: %s, price: %.2f\n", products[i].name, products[i].price);
    }

    // Закрываем файл вывода
    fclose(file2);
    // Выводим сообщение о том, что отсортированные данные записаны в выходной файл
    printf("sorted written to '%s'.\n", outputFile);

    // Освобождаем выделенную память для массива продуктов
    free(products);

    return 0;
}