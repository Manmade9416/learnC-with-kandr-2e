# Word Counting

Counts words, lines and characters from input.
Words are determined by if we've seen atleast one character
before a space, tab or newline.
Lines are determined by \n, we see that we count 1 line.
Characters are just the actual characters themselves, we 
count them all if we see them.

It does the same work but it is not identical as the solution
implemented in the book.

# usage
```
~/ $ cat test.txt | ./wc

Characters = 2371
Words = 365
Lines = 15
```
