# Stealth Programming LDJAM
## Two Modes
- Individual Level Solve (Score: Script Tokens, Instruction Callcount, Time)
- Jack-of-all-levels
## Scripting
Code is memory.
### Instructions
0x00 is Current Instruction

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
### Editing Code
A dual view, shows 