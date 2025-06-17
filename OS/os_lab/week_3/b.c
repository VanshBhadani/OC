#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 3, m = 3; // 3 processes, 3 resources
    int allocation[3][3] = {{0,1,0}, {2,0,0}, {3,0,2}};
    int max[3][3] = {{7,5,3}, {3,2,2}, {9,0,2}};
    int available[3] = {10,5,7};
    int need[3][3], work[3], finish[3] = {0}, safe[3], count = 0;//
    
    // Calculate need matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    
    // Copy available to work
    for(int i = 0; i < m; i++) work[i] = available[i];
    
    // Find safe sequence
    while(count < n) {
        bool found = false;
        for(int p = 0; p < n; p++) {
            if(!finish[p]) {
                bool canProceed = true;
                for(int j = 0; j < m; j++)
                    if(need[p][j] > work[j]) { canProceed = false; break; }
                if(canProceed) {
                    for(int k = 0; k < m; k++) work[k] += allocation[p][k];
                    safe[count++] = p; finish[p] = 1; found = true;
                }
            }
        }
        if(!found) { printf("System is not in safe state\n"); return 0; }
    }
    
    printf("Safe sequence: ");
    for(int i = 0; i < n; i++) printf("P%d ", safe[i]);
    printf("\n");
    return 0;
}