#include <stdio.h>

#define max_ans 5
#define max_txt 100

struct questions
{
    int corr;
    int numAnsw; // вообще-то всегда равно 4
    char txt[max_txt];
    char answers[max_ans][max_txt];
};

#define max_quest 10
struct questions test [max_quest];

int main()
{
    FILE *testing = fopen("Extask19-in.txt", "r");
    int nq;
    fscanf(testing, "%d", &nq);

    for(int i = 0; i < nq; i++)
    {
        fscanf(testing, "%d %d\n", &test[i].numAnsw, &test[i].corr);
        fgets(test[i].txt, max_txt, testing); // считывает конец строки после чисел, если не перейти на след строку
        for(int j = 0; j < test[i].numAnsw; j++)
            fgets(test[i].answers[j], max_txt, testing);
    }

    fclose(testing);

    for(int i = 0; i < nq; i++)
    {
        printf(test[i].txt);
        for(int j = 0; j < test[i].numAnsw; j++)
            printf(test[i].answers[j]);
        int c;
        scanf("%d", &c);
        if(c == test[i].corr)
            puts("correct");
        else
            puts("wrong");
    }

    return 0;
}