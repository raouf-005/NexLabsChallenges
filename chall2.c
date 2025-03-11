#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win() {
    printf("Congratulations! You've successfully exploited the format string vulnerability.\n");
    printf("Flag: Nexus{Format_String_Leak}\n");
    exit(0);
}

void vulnerable_function() {
    char buffer[64];
    char secret[] = "Nexus{Format_String_Leak}"; // Secret value to leak
    printf("Enter your input: ");
    fgets(buffer, sizeof(buffer), stdin); // Safer alternative, but still vulnerable to format strings
    printf(buffer); // Vulnerable format string
    printf("\n");
}

int main() {
    vulnerable_function();
    printf("Returned to main safely.\n");
    return 0;
}
//gcc -fno-stack-protector -o chall2 chall2.c -Wno-implicit-function-declaration

