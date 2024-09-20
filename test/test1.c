#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_GROUPS 100

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    char groups[MAX_GROUPS][10];  // массив для хранения названий групп
    int groupCount = 0;
    int isUnique;

    // Открываем входной файл для чтения
    inputFile = fopen("C:\Users\student.ACADEMY\Desktop\test\in", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла in.txt\n");
        return 1;
    }

    // Чтение построчно и обработка данных
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        char surname[50], group[10];
        // Парсинг строки
        sscanf(line, "%s %s", surname, group);

        // Проверяем, есть ли уже такая группа
        isUnique = 1;
        for (int i = 0; i < groupCount; i++) {
            if (strcmp(groups[i], group) == 0) {
                isUnique = 0;
                break;
            }
        }

        // Если группа уникальна, добавляем её в массив
        if (isUnique) {
            strcpy(groups[groupCount], group);
            groupCount++;
        }
    }

    // Закрываем входной файл
    fclose(inputFile);

    // Открываем выходной файл для записи
    outputFile = fopen("C:\Users\student.ACADEMY\Desktop\test\out", "w");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла out.txt\n");
        return 1;
    }

    // Записываем количество уникальных групп в файл
    fprintf(outputFile, "%d\n", groupCount);

    // Закрываем выходной файл
    fclose(outputFile);

    return 0;
}
