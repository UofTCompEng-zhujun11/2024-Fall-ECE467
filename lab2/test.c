#include "scio.h"

// Function to calculate factorial of a number
int factorial(int n) {
    int result = 1;
    int i = 1;
    
    // Loop to multiply numbers from 1 to n
    while (i <= n) {
        result = result * i;
        i = i + 1;
    }
    
    return result;
}

// Function to check if a number is prime
int is_prime(int n) {
    int i = 2;
    
    if (n < 2) {
        return 0; // Numbers less than 2 are not prime
    }
    
    // Loop to check divisibility by numbers up to n / 2
    while (i <= n / 2) {
        if (n % i == 0) {
            return 0; // If divisible, not prime
        }
        i = i + 1;
    }
    
    return 1; // If no divisors, it is prime
}

// Main function
int main() {
    int number;
    
    // Get input from user
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    
    // Calculate factorial of the number
    int fact = factorial(number);
    
    // Check if the number is prime
    int prime = is_prime(number);
    
    // Output results
    printf("Factorial of %d is: %d\n", number, fact);
    
    if (prime == 1) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }
    
    return 0; // Exit program
}
