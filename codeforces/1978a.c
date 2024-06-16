#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int t;
    scanf("%d", &t); 
    int alpha = t;
    int output[t];
    int y = 0;
    while (t--) {
        int n;
        scanf("%d", &n);  

        int *pages = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &pages[i]);  
        }

        int *mc = (int *)malloc((n-1) * sizeof(int));

        for(int i = 0 ; i<n-1 ;i++){
            mc[i] = (i+1) * pages[i] ;
        }

        int mm = mc[0];
        int index = 0;

        for (int i = 1; i < n-1; i++) {
            if (mc[i] > mm) {
                mm = mc[i];
                // printf("%d\n",mm);
                index = i;
            }
        }


        if( n == 2){
            output[y] =pages[0]+pages[1];
        }else{

            // qsort(pages, n, sizeof(int), compare);
            // printf("%d\n",mm);
            int max_pages = pages[n-1] + mm/(index+1);
            output[y] = max_pages;
            // printf("%d\n", max_pages);
        }
        free(pages);
        y++;
    }

    for(int i = 0;i<alpha;i++){
        printf("%d\n",output[i]);
    }

    return 0;
}
