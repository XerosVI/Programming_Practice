//power function for natural numbers
int power(int a, int n){
  if(n==0)
    return 1;
  int b=power(a,n/2);
  if(n%2==0)
    return b*b;
  else
    return b*b*a;
}

/*
iterative alternative:
int power(int a, int n) {
    if (n == 0) return 1;
    
    int b = a;
    while (n > 1) {
        if (n % 2 == 0) {
            b *= b;
            n /= 2;
        } else {
            b *= a;
            n--;
        }
    }
    return b;
}
*/
