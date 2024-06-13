#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long long ull;

// Function to calculate the initial hash value of a substring
ull calculateHash(const char *s, int start, int k, ull base, ull modulus) {
    ull hash = 0;
    for (int i = 0; i < k; ++i) {
        hash = (hash * base + (s[start + i] - '0')) % modulus;
    }
    return hash;
}

// Function to count distinct substrings of length k
int countDistinctSubstrings(int n, int k, const char *s) {
    ull base = 2;
    ull modulus = pow(2, 64);

    // Compute the hash value of the first substring of length k
    ull current_hash = calculateHash(s, 0, k, base, modulus);

    // Use a simple hash table for storing unique hash values
    // Note: A more sophisticated hash table implementation may be needed for large inputs
    int hashTableSize = n - k + 1;
    ull *hashTable = (ull *)malloc(hashTableSize * sizeof(ull));
    int hashTableCount = 0;

    // Add the first hash to the hash table
    hashTable[hashTableCount++] = current_hash;

    // Precompute base^k % modulus
    ull base_k = 1;
    for (int i = 0; i < k; ++i) {
        base_k = (base_k * base) % modulus;
    }

    // Rolling hash: slide the window of length k over the string s
    for (int i = 1; i <= n - k; ++i) {
        current_hash = (current_hash * base - (s[i - 1] - '0') * base_k + (s[i + k - 1] - '0')) % modulus;

        // Check if the current hash is already in the hash table
        int is_unique = 1;
        for (int j = 0; j < hashTableCount; ++j) {
            if (hashTable[j] == current_hash) {
                is_unique = 0;
                break;
            }
        }

        // If unique, add to the hash table
        if (is_unique) {
            hashTable[hashTableCount++] = current_hash;
        }
    }

    int distinctCount = hashTableCount;

    // Free allocated memory
    free(hashTable);

    return distinctCount;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char *s = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", s);

    printf("%d\n", countDistinctSubstrings(n, k, s));

    // Free allocated memory
    free(s);

    return 0;
}
