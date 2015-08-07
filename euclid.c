// This program calculates the GCD
//#include <stdio.h>

int gcd (int a, int b) {
    while(b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//int main() {
//    printf("GCD of %d and %b is: %d", 8, 2, gcd(8,2));
//    return 0;
//}
