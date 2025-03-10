#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win() {
    printf("Congratulations! You've successfully exploited the buffer overflow.\n");
    printf("Flag: Nexus{Buffer_Overflow_Success}\n");
    exit(0);
}

void vulnerable_function() {
    char buffer[64];
    printf("Enter your input: ");
    gets(buffer); // Vulnerable function
    printf("You entered: %s\n", buffer);
}

int main() {
    vulnerable_function();
    printf("Returned to main safely.\n");
    return 0;
}

//gcc -fno-stack-protector -z execstack -no-pie -o vuln vuln.c