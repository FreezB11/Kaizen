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
        // printf("%s\n",substrings[count]);
        count++;
    }

    qsort(substrings, count, sizeof(char*), compare_strings);

    for(int i =0; i<= n-k;++i){
        printf("%s\n",substrings[i]);
    }

    int unique_count = 0;  
    for (int i = 1; i < count; ++i) {
        if (strcmp(substrings[i], substrings[i-1]) == 0) {
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
    int n, k;  // n = length of the string && k = length of the substring
    char* s;   // s = string of zero's && one's of length n
   
    scanf("%d %d", &n,&k);
    s = (char*)malloc((n+1) * sizeof(char));


    scanf("%s", s);
    int result = count_unique_substrings(s, n, k);

    printf("%d\n",result);
    free(s);

    return 0;
}
