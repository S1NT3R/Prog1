#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function(char* p, int x){
    printf("p is %s and x is %d\n", p, x);
}

int main(){
    printf("Hello World!\n");
    const char* hello = "Hello";
    const char* world = "world!";
    char* helloworld = (char*) malloc(strlen(hello) + strlen(world) + 2);
    strcpy(helloworld, hello);
    helloworld[strlen(hello)] = ' ';
    strcpy(helloworld + strlen(world), world);
    printf("%s\n", helloworld);

    function("foo", 7);
    function("program", 83);

    return 0;
}