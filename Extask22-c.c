#include <stdio.h>
#include <string.h>

struct table_row
{
    char title[50];
    char mfg[100];
    short year;
    int price;
};
#define row_count 3
struct table_row row[row_count];

void fillTable()
{
    strcpy(row[0].title, "V Adapter");
    strcpy(row[0].mfg, "Nvidia");
    row[0].year = 2020;
    row[0].price = 40000;

    strcpy(row[1].title, "Hard Drive");
    strcpy(row[1].mfg, "WestDig");
    row[1].year = 2019;
    row[1].price = 5000;

    strcpy(row[2].title, "Sound card");
    strcpy(row[2].mfg, "Realtek");
    row[2].year = 2015;
    row[2].price = 1000;

    FILE *f = fopen("Extask22.bin", "wb+");
    fwrite(row, sizeof(struct table_row), 3, f);
    fclose(f);

    FILE *ff = fopen("Extask22.bin", "rb+");
    fread(row, sizeof(struct table_row), 3, ff);
    fclose(ff);
}
void watchTable()
{
    printf("Title\t\tCompany\tYear\tPrice\n");
    for(int i = 0; i < row_count; i++)
        printf("%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);

}
void getTxtFile()
{
    FILE *txtFile = fopen("Extask22.txt", "w");
    fprintf(txtFile, "Title\t\tCompany\tYear\tPrice\n");
    for(int i = 0; i < row_count; i++)
        fprintf(txtFile, "%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
        
    fclose(txtFile);
}
void findVAdapter()
{
    char *temp = "V Adapter";

    printf("Company\tYear\tPrice\n");
    for(int i = 0; i < row_count; i++)
    {
        if(strcmp(row[i].title, temp) == 0)
             printf("%s\t%d\t%d\n", row[i].mfg, row[i].year, row[i].price);
    }
}
void findHardDrive()
{
    char *temp = "Hard Drive";

    printf("Company\tYear\tPrice\n");
    for(int i = 0; i < row_count; i++)
    {
        if(strcmp(row[i].title, temp) == 0)
             printf("%s\t%d\t%d\n", row[i].mfg, row[i].year, row[i].price);
    }
}
void findSoundCard()
{
    char *temp = "Sound card";

    printf("Company\tYear\tPrice\n");
    for(int i = 0; i < row_count; i++)
    {
        if(strcmp(row[i].title, temp) == 0)
             printf("%s\t%d\t%d\n", row[i].mfg, row[i].year, row[i].price);
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nЗаполнить БД: 1\n");
        printf("Посмотреть БД: 2\n");
        printf("Вывести БД в txt файл: 3\n");
        printf("Найти Видеоадаптер: 4\n");
        printf("Найти Жёсткий диск: 5\n");
        printf("Найти Звуковую карту: 6\n");
        printf("Выйти из программы: 0\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                fillTable();
                break;
            case 2:
                watchTable();
                break;
            case 3:
                getTxtFile();
                break;
            case 4:
                findVAdapter();
                break;
            case 5:
                findHardDrive();
                break;
            case 6:
                findSoundCard();
                break;
        }
    }
    while(choice != 0);

    return 0;
}