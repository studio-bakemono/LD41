// Turing.cpp : A Turing Machine that beat boxes
//

#include "Turing.h"

Turing::Turing(std::vector<unsigned char> tape) : tape(tape){
    tape.resize(256);
}

BS Turing::tick()
{
	for(int iter=0; iter<STEPSPERTICK; iter++){
		switch(tape[tape[0]]){
			case '+':{
				tape[tape[tape[0]+1]]+=tape[tape[tape[0]+2]];
				break;
			}
			case '-':{
				tape[tape[tape[0]+1]]-=tape[tape[tape[0]+2]];
				break;
			}
            case '*':{
				tape[tape[tape[0]+1]]*=tape[tape[tape[0]+2]];
				break;
			}
            case '/':{
				tape[tape[tape[0]+1]]/=tape[tape[tape[0]+2]];
				break;
			}
            case '%':{
				tape[tape[tape[0]+1]]%=tape[tape[tape[0]+2]];
				break;
			}
			case 'c':{
				tape[tape[tape[0]+1]]=tape[tape[tape[0]+2]];
				break;
			}
			case '=':{
				tape[tape[tape[0]+1]]=tape[tape[0]+2];
				break;
			}
			case 'z':{
				if(tape[tape[tape[0]+1]]==0){
					tape[0]+=tape[tape[0]+2];
				}
				break;
			}
		}
		tape[0]+=3;
	}
    BS set;
    for(char x=0;x<BEATCOUNT;x++){
		// Just to test
		if (rand() % 3 == 0) {
			set.set(x, 1);
		}
		else {
			set.set(x, 0);
		}
        //set.set(x,tape[x+1]);
    }
	return set;
}