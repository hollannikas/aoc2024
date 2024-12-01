#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readLine(FILE *pFile);
int compare (const void * a, const void * b);
int findOccurrences(int value, const int array[1000]);

const int MAX_FILE_ROWS = 1000;

int main(void) {
    FILE *file = fopen("data/day1.txt", "r");

    int firsts[MAX_FILE_ROWS];
    int seconds[MAX_FILE_ROWS];

    int ctr = 0;
    while (!feof(file)) {
        char *line = readLine(file);
        char *token = strtok(line, "   ");
        char *endptr;

        int f = (int) strtol(token, &endptr, 10);
        int s = (int) strtol(strtok(NULL, "   "), &endptr, 10);

        firsts[ctr] = f;
        seconds[ctr] = s;

        ctr++;
        free(line);
    }

    qsort (firsts, MAX_FILE_ROWS, sizeof(int), compare);
    qsort (seconds, MAX_FILE_ROWS, sizeof(int), compare);

    int sum = 0;
    for (int n=0; n < MAX_FILE_ROWS; n++)
        sum += abs(firsts[n] - seconds[n]);

    printf("Total distance: %d\n", sum);

    sum = 0;
    for (int n=0; n < MAX_FILE_ROWS; n++) {
        int first = firsts[n];
        int occurrences = findOccurrences(first, seconds);
        sum += first * occurrences;
    }

    printf("Total similarity score: %d\n", sum);

    return 0;
}

int findOccurrences(int value, const int array[MAX_FILE_ROWS]) {
    int count = 0;
    if (array != NULL) {
        for (int i = 0; i < MAX_FILE_ROWS; i++) {
            if (array[i] == value) {
                count++;
            }
        }
    }
    return count;
}

char *readLine(FILE *pFile) {
    char *line = NULL;
    size_t len = 0;

    if ((getline(&line, &len, pFile)) != -1) {
        return line;
    }

    return NULL;
}

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}