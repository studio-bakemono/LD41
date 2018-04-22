# Programming Rhythm Game
## Turing Machine
### Instructions
Each instruction is one case-insensitive byte,
followed by two bytes
```
  Space is NOP
+ *arg1=*arg1+*arg2
- *arg1=*arg1-*arg2
= *arg1=*arg2
& *arg1=arg2
. *arg1=arg1+arg2
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