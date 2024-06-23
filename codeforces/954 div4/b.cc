#include <iostream>
#define LOG(x) std::cout << x << std::endl;
#define ll long long

const int MOD = 1e9 + 7;




int main(){
    int t;
    std::cin >> t;

    while(t--){
        int n,m;

        std::cin >> n >> m;
        int **mat = (int **)malloc(n*m *(sizeof(int)));
        for (size_t na = 0; na < n; na++){
            for (size_t ma = 0; ma < m; ma++){
                std::cin >> mat[na][ma];
            }
            
        }

        for (size_t na = 0; na < n; na++){
            for (size_t ma = 0; ma < m; ma++){
                if (mat[na][ma] > mat[na+1][ma] && mat[na][ma] > mat[na][ma+1] && mat[na][ma] > mat[na][ma-1] && mat[na][ma] > mat[na-1][ma]){
                    mat[na][ma] -=1;
                }
                
            }
            
        }
        
        for (size_t na = 0; na < n; na++){
            for (size_t ma = 0; ma < m; ma++){
                std::cout << mat[na][ma] << " ";
            }
            
        }

    }

    return 0;
}