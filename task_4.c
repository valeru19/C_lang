#include <stdlib.h>
#include <stdio.h>

// Структура для узла (Node) в стеке
struct Node_tag {
    int value; // Значение узла
    struct Node_tag *next; // Указатель на следующий узел
};

// Структура для представления стека
struct Stack {
    struct Node_tag *head; // Указатель на вершину стека (голову)
    int size; // Размер стека
};

// Функция для добавления элемента в стек (push)
void push(struct Stack *stack, int value, int maxsize) {
    if (stack->size >= maxsize) {
        perror("overflow"); // Ошибка при переполнении стека
    } else {
    struct Node_tag *newNode = malloc(sizeof(struct Node_tag));
    newNode->next = stack->head;
    newNode->value = value;
    stack->head = newNode;
    stack->size++;
    }
}

// Функция для создания нового стека
struct Stack *createStack() {
    struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
    if (newStack == NULL) {
        perror("allocation error");
    } else {
        newStack->head = NULL;
        newStack->size = 0;
        return newStack;
    }
}

// Функция для удаления элемента из стека (pop)
int pop(struct Stack *stack) {
    if (stack->head == NULL) {
        perror("empty"); // Ошибка при попытке извлечь элемент из пустого стека
    } else {
        struct Node_tag *removedNode = stack->head;
        stack->head = stack->head->next;
        int value = removedNode->value;
        free(removedNode);
        stack->size--;
        return value;
    }
}

// Функция для просмотра верхнего элемента стека (без удаления)
int peek(const struct Stack *stack) {
    if (stack->head == NULL) {
        perror("empty");
    } else {
        return stack->head->value;
    }
}

// Главная функция main
void main() {
    int maxsize;
    printf("input stack size: ");
    scanf("%d", &maxsize);

    // Создание нового стека
    struct Stack *stack = createStack();

    // Добавление элементов в стек
    for (int i = 0; i < 10; i++) {
        push(stack, i, maxsize);
    }

    // Извлечение и вывод элементов из стека
    while (stack->head) {
        printf("peek:%d\n", peek(stack));
        printf("pop:%d\n", pop(stack));
    }
}