#include <stdio.h>
#include <stdlib.h>

void win() {
    printf("Congratulations! You've successfully exploited the format string vulnerability.\n");
    printf("Flag: Nexus{Format_String_PIE_Leak}\n");
    exit(0);
}

void vulnerable_function() {
    char buffer[64];
    printf("Enter your input: ");
    fgets(buffer, 100, stdin); 
    printf(buffer); 
    printf("\n");
}

int main() {
    vulnerable_function();
    printf("Returned to main safely.\n");
    return 0;
}

//gcc -fno-stack-protector -o vuln vuln.c -pie -fPIE