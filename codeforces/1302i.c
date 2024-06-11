#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int count_unique_substrings(const char* s, int n, int k) {

    char** substrings = (char**)malloc((n - k + 1) * sizeof(char*));
    int count = 0;

    for (int i = 0; i <= n - k; ++i) {
        substrings[count] = (char*)malloc((k + 1) * sizeof(char));
        strncpy(substrings[count], s + i, k);
        substrings[count][k] = '\0'; 
        count++;
    }

    qsort(substrings, count, sizeof(char*), compare_strings);

    int unique_count = 1;  
    for (int i = 1; i < count; ++i) {
        if (strcmp(substrings[i], substrings[i - 1]) != 0) {
            unique_count++;
        }
    }
    for (int i = 0; i < count; ++i) {
        free(substrings[i]);
    }
    free(substrings);

    return unique_count;
}

int main() {
    int n, k;
    char* s;
   
    scanf("%d %d", &n,&k);
    s = (char*)malloc((n + 1) * sizeof(char));


    scanf("%s", s);
    int result = count_unique_substrings(s, n, k);

    printf("%d\n",result);
    free(s);

    return 0;
}
