// Turing.cpp : A Turing Machine that beat boxes
//

#include "Turing.h"

#include <bitset>

Turing::Turing(){
    tape.resize(256);
}

std::bitset<8> Turing::tick()
{
	for(int iter=0; iter<16; iter++){
		switch(tape[tape[0]]){
			case '+':{
				tape[tape[tape[0]+1]]+=tape[tape[tape[0]+2]];
				break;
			}
			case '=':{
				tape[tape[tape[0]+1]]=tape[tape[0]+2];
				break;
			}
			case 'c':{
				tape[tape[tape[0]+1]]=tape[tape[tape[0]+2]];
				break;
			}
			case 'z':{
				if(tape[tape[tape[0]+1]]==0){
					tape[0]+=tape[tape[0]+2];
				}
				break;
			}
		}
		if(tape[0]!=0){
			tape[0]+=3;
		}
	}
    std::bitset<8> set;
    for(char x=0;x<8;x++){
        set.set(x,tape[x+1]);
    }
	return set;
}