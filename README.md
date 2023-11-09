# Brainfuck Interpreter in C

This is a simple Brainfuck interpreter written in C.

## Features

- Increment (`+`)
- Decrement (`-`)
- Input (`,`)
- Output (`.`)
- Move left (`<`)
- Move right (`>`)
- Loop support (`[]`)

## Usage

Pass name of a file as a command line argument to compiled application.

```bash
./main.out hello_world.bf
```

## Examples

Hello World:

```brainfuck
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

## Contributing

Feel free to contribute to improve this Brainfuck interpreter. Fork the repository and submit a pull request.
