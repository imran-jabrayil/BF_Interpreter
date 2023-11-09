//
// Created by Imran Jabrayilov on 11/9/2023.
//

#include <stdio.h>
#include "memory_tape.h"
#define MAX_SIZE 300000


static struct MemoryTape mt;


struct MemoryTape {
    int _arr[MAX_SIZE];
    int _ci;
};


void executeCommand(enum Command command) {
    switch (command) {
        case INCR:  ++mt._arr[mt._ci];                          break;
        case DECR:  --mt._arr[mt._ci];                          break;
        case IN:    scanf("%d%*c", mt._arr + mt._ci);           break;
        case OUT:   printf("%c", mt._arr[mt._ci]);              break;
        case LEFT:  if (mt._ci != 0) --mt._ci;                  break;
        case RIGHT: if (mt._ci + 1 != MAX_SIZE) ++mt._ci;       break;
        default:                                                break;
    }
}

void parseLoop(FILE *file) {
    int loopStartIndex = ftell(file);

    char c;
    int counter = 0;
    while (true) {
        c = (char)fgetc(file);
        if (c == '[') {
            ++counter;
        }
        if (c == ']') {
            if (counter == 0)
                break;
            --counter;
        }
    }

    int loopEndIndex = ftell(file) - 1;
    int iterCount = loopEndIndex - loopStartIndex;

    while (mt._arr[mt._ci] != 0) {
        fseek(file, loopStartIndex, SEEK_SET);
        for (int _ = 0; _ < iterCount; ++_) {
            c = fgetc(file);
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
            if (c == ']')
                break;
        }


    }

    fseek(file, loopEndIndex + 1, SEEK_SET);
}
