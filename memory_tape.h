//
// Created by Imran Jabrayilov on 11/9/2023.
//

#ifndef BFINTERPRETER_MEMORY_TAPE_H
#define BFINTERPRETER_MEMORY_TAPE_H

enum Command {
    INCR,
    DECR,
    IN,
    OUT,
    LEFT,
    RIGHT
};

void executeCommand(enum Command command);

void parseLoop(FILE *file);

#endif //BFINTERPRETER_MEMORY_TAPE_H
