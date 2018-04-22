# Programming Rhythm Game
## Turing Machine
An array of 256 bytes
### Instructions
Each instruction is one case-insensitive byte,
followed by two bytes
```
+ *arg1=*arg1+*arg2
- *arg1=*arg1-*arg2
* *arg1=*arg1*(*arg2)
/ *arg1=*arg1/*arg2
% *arg1=*arg1%*arg2
c *arg1=*arg2
= *arg1=arg2
z if !*arg1, *0+=arg2
Else, NOP
```

### Special Addresses
9 of them:
0 is Current Instruction
1 through 8 are the beats, 0=silence, anything else=hit!
### Editing Code
Four Columns:
* Address
* Val as Instruction
* Val as Uint
* Any info about address (is it special?)