# Wordgraph usage

```
~$ cat test.txt | ./wordgraphs
Word Length Histogram
━━━━━━━━━━━━━━━━━━━━━

      X
The   ┃███
old   ┃███
lig...┃██████████
stood ┃█████
sil...┃████████
aga...┃███████
the   ┃███
cra...┃████████
waves ┃█████
of    ┃██
the   ┃███
mid...┃████████
ocean.┃██████
Every ┃█████
few   ┃███
sec...┃████████
a     ┃█
pow...┃████████
beam  ┃████
of    ┃██
golden┃██████
light ┃█████
pie...┃███████
thr...┃███████
the   ┃███
thick,┃██████
salty ┃█████
mist, ┃█████
war...┃███████
dis...┃███████
sai...┃███████
of    ┃██
the   ┃███
jagged┃██████
rocks ┃█████
hidden┃██████
ben...┃███████
the   ┃███
chu...┃████████
foam. ┃█████
It    ┃██
was   ┃███
a     ┃█
lonely┃██████
sen...┃█████████
wea...┃█████████
by    ┃██
time  ┃████
and   ┃███
salt, ┃█████
yet   ┃███
ste...┃█████████
in    ┃██
its   ┃███
anc...┃███████
      ╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Y
      0          10          20          30          40
```

Counts n time a word appears in input and draws histogram,
can also read from stdin.

# Lettergraph usage

```
~$ cat test.txt | ./lettergraphh
Char appearance Histograam
━━━━━━━━━━━━━━━━━━━━━━━━━━

    X
T   ┃█
h   ┃██████████████████
e   ┃████████████████████████████████
    ┃███████████████████████████████████████████████████>50
o   ┃████████████████
l   ┃█████████████
d   ┃██████████████
i   ┃████████████████████
g   ┃███████████
t   ┃█████████████████████████████
u   ┃█████
s   ┃████████████████████
n   ┃█████████████████████
y   ┃███████
a   ┃██████████████████████
c   ┃████████
r   ┃██████████
w   ┃██████
v   ┃██
f   ┃███████
m   ┃█████
.   ┃███
E   ┃█
,   ┃█████
p   ┃██
b   ┃███
k   ┃██
j   ┃█
I   ┃█
    ╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Y
    0        10        20        30        40        50
```

Count n appearances for every unique char from input, Can
also read fron stdin and draws a histogram
