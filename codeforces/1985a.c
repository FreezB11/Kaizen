#include <stdio.h>
#include <string.h>

// Function to swap the first characters of two strings
void swapFirstChar(char *a, char *b) {
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
}

int main() {
    int t;
    scanf("%d", &t);
    
    char a[t][4], b[t][4];
    for (int i = 0; i < t; ++i) {
        scanf("%s %s", a[i], b[i]);
    }
    for (int i = 0; i < t; ++i) {
        swapFirstChar(a[i], b[i]);
    }

    for (int i = 0; i < t; ++i) {
        printf("%s %s\n", a[i], b[i]);
    }
    
    return 0;
}
