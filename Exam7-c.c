#include <stdio.h>
#include <stdlib.h>

float avgMark(int sum, int num)
{
    float avg = sum / (float) num;
    printf("Средний балл ученика: %.1f\n", avg);
    if(avg >= 4.6f)
        printf("Ученик может поступить в университет\n");
    else
        printf("Ученик не может поступить в университет\n");
    return 0;
} 

int main()
{
    int num;

    printf("Введите количество оценок аттестата: ");
    scanf("%d", &num);

    int *marks = (int*) malloc (num * sizeof(int));
    int sum = 0;

    printf("Введите оценки: ");
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &marks[i]);
        if(marks[i] < 2 || marks[i] > 5)
        {
            printf("Данные введены неправильно!");
            return 0;
        }
        sum += marks[i];
    }

    avgMark(sum, num);
    free(marks);
    return 0;
}