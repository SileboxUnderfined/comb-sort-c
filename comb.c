#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int rand_max, length;
    double factor;

    printf("Enter max random integer: ");
    scanf("%d", &rand_max);
    printf("Enter array length: ");
    scanf("%d", &length);
    printf("Enter shrink factor: ");
    scanf("%lf", &factor);

    int* numbers = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
        numbers[i] = rand() % rand_max + 1;
    }

    printf("Initial array: ");
    print_array(numbers, length);

    clock_t start_time = clock();
    int count = sort(numbers, length, factor);
    clock_t end_time = clock();

    double result_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    print_array(numbers, length);
    printf("Count of iterations: %d\n", count);
    printf("The array was sorted in %f ms", result_time);

    return 0;
}

int sort(int* numbers, int length, double factor) {
    int step = length;
    unsigned char swapped = 0;

    int counter = 0;
    while (swapped == 0 || step > 1) {
        swapped = 1;
        for (int i = 0; i + step < length; i++) {
            if (numbers[i] > numbers[i+step]) {
                int temp = numbers[i];
                numbers[i] = numbers[i+step];
                numbers[i+step] = temp;

                swapped = 0;
            }
        }

        step = (int)(step / factor);
        if (step < 1) step = 1;

        counter++;
    }

    return counter;
}

void print_array(int* numbers, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}