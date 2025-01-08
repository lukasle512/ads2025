#include<stdio.h>
#include <stdlib.h>
#include <math.h>

//Find Highest common factor of two natural number using prime factorization
// 495 = 3*3*5*11 ; 60 = 2*2*3*5
//HCF is to check whether the smaller value is divisible by the prime factors of the bigger value
// HCF(495,60) = 3*5=15 where 60 is divisible by 3 and 5 which are factors of 495
//A function to complete the prime factorization for a natural. Prime factors can be stored in an array. (3pts)
//A function to check whether the smaller value is divisible by found prime factors of the bigger value. Another array can be used to store these prime divisors. (3 pts)
//A function to calculate the product of the common prime factors and return HCF.(3pts)
//A main function to test the above functions (3 pts)
//Calculate the complexity of the proposed algorithm. (2pts)
int is_prime(int num){
    if ( num <2) return 0;
    for (int i = 2; i <= sqrt(num); i++){
        if (num % i == 0) return 0;
    }
    return 1;
}
int prime_factor_re(int num,int factor[], int index,int divisor){
    if (num==1) return index;
    while(divisor <= num ){
        if (num % divisor == 0 && is_prime(divisor)){
            factor[index++] = divisor;
            return prime_factor_re(num/divisor,factor,index,divisor); // dont need to +1 because prime number can be repeat
            }
        divisor++;
    }
    return index;
}
int prime_factor(int num, int factor[]){
    return prime_factor_re(num,factor,0,2);
}
int find_common_prime_divisor(int factor1[],int count1, int factor2[],int count2, int common_factor[]){
    int index = 0;
    int i = 0 ;
    int j = 0;
    while ( i < count1&& j<count2){
        if (factor1[i] == factor2[j]) {
            common_factor[index++] = factor1[i];
            i++;
            j++;
            }else if(factor1[i]< factor2[j]){
                i++;
            }else{
                j++;
            }
    }
    return index;
}
int calculate_hcf(int commonfactor[],int count){
    int hcf = 1;
    for (int i = 0; i < count; i++) {
        hcf *= commonfactor[i];
    }
    return hcf;


}  
int main() {
    int num1 = 495;
    int num2 =60;

    // Arrays to store prime factors
    int factor1[100], factor2[100], common_factor[100];

    // Find prime factors of both numbers
    int count1 = prime_factor(num1, factor1);
    int count2 = prime_factor(num2, factor2);

    // Find common prime factors
    int common_count = find_common_prime_divisor(factor1, count1, factor2, count2, common_factor);

    // Calculate HCF
    int hcf = calculate_hcf(common_factor, common_count);

    // Output the result
    printf("The HCF of %d and %d is: %d\n", num1, num2, hcf);

    return 0;
} 
        