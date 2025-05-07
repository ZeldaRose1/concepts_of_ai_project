# concepts_of_ai_project
This is the code directory for the semester long project in my Concepts of Artificial Intelligence class.
Compilation of the program and running the tests is simple. Just run "make test" from the source
directory. The Makefile will clean the folder, if it has anything that needs to be deleted, compile the
test file, and run the test file for you. If this fails to compile you can run "make debug" to stop at
compilation. This way you may run your debugger and check to see where the problem is.

For the other programs, you can run "make program_name" in lowercase to compile the program.

The board files must have the following format:
    First line: board positions with 1's or W representing white pieces,
        -1's or B representing black pieces, and 0's or x representing empty
    Second line: Single int with a 1 for white's turn and 0 for black's
    Third line: Single int with a 0 for opening phase, 1 for midgame,
        and 2 for endgame
    Fourth line: Single int with the number of turns played