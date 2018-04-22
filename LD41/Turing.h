// Turing.h : A Turing Machine that beat boxes
//
#include <bitset>

class Turing{
    std::vector<unsigned char> tape = {
		0x06, 0x00, 0x04,
		0x00, 0x01, 0x00,
		'+',  0x01, 0x02,
		'+',  0x03, 0x04,
		'z',  0x01, 0x03,
		'=',  0x00, 0x03,
		'=',  0x00, 0x00,
    };
    public:
    Turing();
    std::bitset<8> tick();
}