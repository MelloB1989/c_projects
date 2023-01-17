#include <stdio.h>

int check_prime();

int main() {

  int n1, n2, flag = 0, i;
  printf("Enter a starting positive integer: ");
  scanf("%d", &n1);
  printf("Enter a starting positive integer: ");
  scanf("%d", &n2);
  for(i=n1; i<=n2; i++){
    flag = check_prime(i);
    if (flag == 0)
        printf("%d is a prime number\n", i);
  }
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