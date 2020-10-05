#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_usage();
void process_operation(float x, float y);

int addFlag = 0, mulFlag = 0, subFlag = 0, divFlag = 0;

int main(int argc, char** argv) {
    if(argc < 4) {
        print_usage();
        return 0;
    }
    int opt;
    float x, y;
    while((opt = getopt(argc, argv, ":asmdhx:y:")) != -1) {
        switch(opt) {
            case 'a':
                addFlag = 1;
                break;
            case 's':
                subFlag = 1;
                break;
            case 'm':
                mulFlag = 1;
                break;
            case 'd':
                divFlag = 1;
                break;
            case 'x': 
                x = atof(optarg);
                break;
            case 'y':
                y = atof(optarg);
                break;
            case 'h':
            default:
                print_usage();
                return 0;
        }
    }
    process_operation(x, y);
    return 0;
}

void process_operation(float x, float y) {
    if(addFlag) {
        printf("%0.2f + %0.2f = %0.2f\n", x, y, x+y);
    }
   if(subFlag) {
        printf("%0.2f - %0.2f = %0.2f\n", x, y, x-y);
    }
    if(mulFlag) {
        printf("%0.2f * %0.2f = %0.2f\n", x, y, x*y);
    }
    if(divFlag) {
        printf("%0.2f / %0.2f = %0.2f\n", x, y, x/y);
    }
}

void print_usage() {
    printf("usage: calc [operation] [-x num1] [-y num2]\n");
    printf("Operations:\n");
    printf("-a\tAddition\n");
    printf("-s\tSubstraction\n");
    printf("-m\tMultiplication\n");
    printf("-d\tDivision\n");
}