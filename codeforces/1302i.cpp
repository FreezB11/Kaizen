#include <iostream>
#include <string>



int main(){
 
    int n,k;
    std::cin >> n >> k;
    std::string input_str; 
    int arr[n][k];
    std::cin >> input_str;
    int y = 0;

    for (size_t i = 0; i < n-k+1; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            arr[i][j] = input_str[j+y];
            std::cout << arr[i][j] << std::endl;
            y++;
        }
        
    }

    return 0;
}