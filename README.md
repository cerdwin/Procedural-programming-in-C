# Procedural-programming-in-C
C 
Mostly coursework for a C course, obtained 90% in final exam consisting of both theory and 4-hour programming exam
covering load/save of jpeg and ppm images, parsing image dimensions from jpeg/ppm header, swapping, flipping/ mirroring image 
pixels as per parsed instructions in a text file and animation.

Contains:

1. ASCII art - simple drawing of a house, if called with two parameters ( 7 6):
                                                                                         X
                                                                                        X X
                                                                                       X   X
                                                                                      XXXXXXX
                                                                                      X     X
                                                                                      X     X
                                                                                      XXXXXXX
 if with three, where first two are identical (9 9 6):
                                                                                              X
                                                                                             X X
                                                                                            X   X
                                                                                           X     X
                                                                                          XXXXXXXXX
                                                                                          Xo*o*o*oX
                                                                                          X*o*o*o*X
                                                                                          Xo*o*o*oX-|-|-|
                                                                                          X*o*o*o*X | | |
                                                                                          Xo*o*o*oX | | |
                                                                                          X*o*o*o*X | | |
                                                                                          Xo*o*o*oX | | |
                                                                                          XXXXXXXXX-|-|-|
2. Prime number factorisation, employing Eratosthenes sieve algorithm
  input in stdin in form: each number on a single line, followed by newline, end of stdin demarcated by a zero on a new line.
  
3. Caesar's cipher- two sentences on input - one encrypted (e.g. xUbbemehbT), the other a misheard transcript (e.g. XYlloworld). Program
   yields a string wich matches the misheard sentence the most, in terms of a constant shift along the alphabet with respect to the first string (e.g. Hello World).
   
4. Matrix calculator - first line of stdin contains 2 numbers: row number and column number, following input contains matrix cells'
   filling, followed by an operation sign and the same format of input for the second matrix.
   
5. Implementation of Bash grep command in C.

6. Implementation of a circular FIFO queue employing structs.

7. Loading/saving of a graph to/from a binary/text file.

8. Code integration - implementation of a Dijkstra shortest - path finding algorithm using a priority queue.
                                                                                          
 
 
