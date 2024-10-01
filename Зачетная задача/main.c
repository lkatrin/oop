/*
Вычислить сумму выплат Сидорову
in.txt:
Ivanov  100
Petrov  200
Ivanov  300
Sidorov 150
Petrov  50
Sidorov 200
Sidorov 1000

out.txt:
1350
*/
#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

int main()
{
    FILE *inputFile, *outputFile;
    char line [MAX_LINE_LENGTH];
    int sum = 0;
    
    inputFile = fopen("in.txt", "r");
    if (inputFile == NULL){
        printf("Ошибка открытия файла in.txt\n");
        return 1;
    }
    
    while(fgets(line, MAX_LINE_LENGTH, inputFile) != NULL){
        char surname[50];
        int number;
        
        sscanf(line, "%s %d", surname, &number);
        if (strcmp(surname, "Sidorov") == 0){
            sum += number;
        }
    }
    
    fclose(inputFile);
    
    outputFile = fopen("out.txt", "w");
    if (outputFile == NULL){
        printf("Ошибка открытия файла out.txt\n");
        return 1;
    }
    fprintf(outputFile, "%d\n", sum);
    fclose(outputFile);
    return 0;
}
