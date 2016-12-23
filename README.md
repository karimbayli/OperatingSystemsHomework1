# OperatingSystemsHomework1
Write a C program "diff.c" that is finding the
difference of two sets of words. The program will take 3 filenames as parameters
from command line: two filenames for two input files and one filename for output
file. An input file will include a large number of unique words (one word per line).
The program will read the file and will generate a linked list from it: each word in the
file will be a different entry in the linked list. Two such lists (sets), set A and set B,
will be generated from two input files. Then the program will compute the difference
(A - B) of these lists (sets). The difference will be written out to an output file (one
word per line). The output file will be in sorted order (ascending order; use strcmp()
to decide which word comes earlier). Before taking the difference, you can sort the
lists if you wish. Maximum wordsize will be 256 (including the NULL character at
the end of the word).
