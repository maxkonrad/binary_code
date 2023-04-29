#include <stdio.h>
#include <time.h>
#define MIN 3
#define MAX 10

int power(int base, int exponent);
long int int2int(unsigned int k);

int main(){
    clock_t start, end, start_i, end_i;
    double time_passed = 0;
    long int n, i;
    FILE *file_pointer;
    file_pointer = fopen("./OUTPUT_binarycode.txt", "w");

    fprintf(file_pointer, "\nBINARY CODE\n");
    fprintf(file_pointer, "\nOVERALL EXECUTION IN THE END\n");
    start = clock();
    for(n = 3; n <= MAX; n++){
        start_i = clock();
        for (i = 0; i < power(2, n); i++){
            fprintf(file_pointer, "\n%ldth binary code in %ld bit is %010ld", i, n, int2int(i));
        }
        end_i = clock();
        time_passed = ((double) (end_i - start_i) / CLOCKS_PER_SEC);
        fprintf(file_pointer, "\n\nTIME PASSED WHILE GENERATION OF %ld BITS OF BINARY CODE = %f", n, time_passed);
    }
    end = clock();

    time_passed = ((double) (end - start) / CLOCKS_PER_SEC);

    fprintf(file_pointer, "\nTIME PASSED DURING OVERALL EXECUTION: %f\n", time_passed);
    printf("\nTIME PASSED DURING OVERALL EXECUTION: %f\n", time_passed);
} 

int power(int base, int exponent){
    int res = 1;
    for(exponent; exponent > 0; exponent--) res = res * base;
    return res;
}

long int int2int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int2int(k / 2)));
}