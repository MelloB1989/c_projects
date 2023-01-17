#include <stdio.h>

int check_prime();

int main() {

  int n, flag = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  flag = check_prime(n);
  if (flag == 0)
    printf("%d is a prime number.", n);
  else
    printf("%d is not a prime number.", n);

  return 0;
}

int check_prime(int n){
    int i, flag = 0;
    // 0 and 1 are not prime numbers
  // change flag to 1 for non-prime number
  if (n == 0 || n == 1)
    flag = 1;

  for (i = 2; i <= n / 2; ++i) {

    // if n is divisible by i, then n is not prime
    // change flag to 1 for non-prime number
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  // flag is 0 for prime numbers
  return flag;
}