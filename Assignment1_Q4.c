#include <stdio.h> 
#include <string.h> 

int main() { 
    char greeting[] = "Hello, World!"; 
    char target = 'o'; 

    printf("%s", strchr(greeting, target)); 

    return 0; 
}
