//
// Created by Imran Jabrayilov on 11/9/2023.
//

#include <stdio.h>
#include "memory_tape.h"


int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        puts("Couldn't open file.");
        return 0;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        switch (c) {
            case '+': executeCommand(INCR);  break;
            case '-': executeCommand(DECR);  break;
            case ',': executeCommand(IN);    break;
            case '.': executeCommand(OUT);   break;
            case '<': executeCommand(LEFT);  break;
            case '>': executeCommand(RIGHT); break;
            case '[': parseLoop(file);       break;
            default: break;
        }
        // printState();
    }

    fclose(file);
    return 0;
}