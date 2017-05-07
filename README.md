# N-Queens Solver

This program uses the [hill climbing algorithm](https://en.wikibooks.org/wiki/Artificial_Intelligence/Search/Iterative_Improvement/Hill_Climbing) in order to find a solution for the N-Queens Problem. As heuristic cost for the algorithm, it was used the number of pair of queens that can attack each other.

It was developed as an exercise for the 2016 Artificial Intelligence subject from the Computer Engineering undergraduate course at ITA - Instituto Tecnológico de Aeronáutica.

## The N-Queens Problem
```
Given an integer N > 3, place N queens in an NxN board in such a way that no
queen can attack* another queen.

* A queen is able to attack another queen if both occupy the same row, column
or diagonal on the board. Just like in chess.
```

## Usage

Choose the C++ IDE you like the most (e.g. CodeLite, Code::Blocks, Visual Studio), create a new project and import the header and the source files. Build and run, and the program will ask you for the dimension of the board, which should be an integer greater than 3.

## Example of output

![N-Queens Solver example](http://i.imgur.com/RI36c8l.png)

## License

This project is licensed under the MIT License - see the [LICENSE.txt](./LICENSE.txt) file for details.
