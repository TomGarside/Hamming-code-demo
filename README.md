# Hamming-code-demo
demo of hamming code 
demonstrates hamming error correction on a single byte 
provided by user as a number between 0-255 

example output for 255
```
Bit                      0  1  2  3  4  5  6  7  8  9  10 11 
                        -------------------------------------
Initial                 | *| *| 1| *| 1| 0| 1| *| 0| 1| 1| 1|
                        -------------------------------------
Parity bits calculated  | 0| 0| 1| 0| 1| 0| 1| 1| 0| 1| 1| 1|
                        -------------------------------------
Random error added  :4  | 0| 0| 1| 0| 0| 0| 1| 1| 0| 1| 1| 1|
                        -------------------------------------
Error Corrected         | 0| 0| 1| 0| 1| 0| 1| 1| 0| 1| 1| 1|
                        -------------------------------------
Error calculated at :4
```
