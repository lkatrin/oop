#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_GROUPS 100

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    char groups[MAX_GROUPS][10];  // ������ ��� �������� �������� �����
    int groupCount = 0;
    int isUnique;

    // ��������� ������� ���� ��� ������
    inputFile = fopen("C:\Users\student.ACADEMY\Desktop\test\in", "r");
    if (inputFile == NULL) {
        printf("������ �������� ����� in.txt\n");
        return 1;
    }

    // ������ ��������� � ��������� ������
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        char surname[50], group[10];
        // ������� ������
        sscanf(line, "%s %s", surname, group);

        // ���������, ���� �� ��� ����� ������
        isUnique = 1;
        for (int i = 0; i < groupCount; i++) {
            if (strcmp(groups[i], group) == 0) {
                isUnique = 0;
                break;
            }
        }

        // ���� ������ ���������, ��������� � � ������
        if (isUnique) {
            strcpy(groups[groupCount], group);
            groupCount++;
        }
    }

    // ��������� ������� ����
    fclose(inputFile);

    // ��������� �������� ���� ��� ������
    outputFile = fopen("C:\Users\student.ACADEMY\Desktop\test\out", "w");
    if (outputFile == NULL) {
        printf("������ �������� ����� out.txt\n");
        return 1;
    }

    // ���������� ���������� ���������� ����� � ����
    fprintf(outputFile, "%d\n", groupCount);

    // ��������� �������� ����
    fclose(outputFile);

    return 0;
}
