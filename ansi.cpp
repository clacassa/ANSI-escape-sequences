/*
 * 2022 Cyprien Lacassagne
 * <https://en.wikipedia.org/wiki/ANSI_escape_code>
 */
#include <iostream>
#include <string>
#include <vector>

// Pangramm written by Georges and Claudine Ottavj
const std::string pangramm("Le vif zephir jubile sur les kumquats du clown gracieux.");
typedef std::vector<std::string> SgrDoc;
void set_sgr_doc(SgrDoc& vec);

// Select Graphic Rendition (SGR)
void SGR(SgrDoc vec);
// 4-bit Standard Colors
void Colors_4_bits();
// 8-bit Standard Colros
void Colors_8_bits();

int main() {
	SgrDoc sgr(76, "");
	set_sgr_doc(sgr);
	SGR(sgr);
	Colors_4_bits();
	Colors_8_bits();
    std::cout << "\n";
	return 0;
}

void SGR(SgrDoc vec) {
    std::cout << "\n";
	std::cout << "Select Graphic Rendition (SGR)\tCSI n m\n";
    std::cout << "------------------------------\n";
	for (unsigned i(1); i < 10; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "   |  " + vec[i] + "\n";
	}
	for (unsigned i(10); i < 22; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "  |  " + vec[i] + "\n";
	}
	std::cout << "\x1b[26m" + pangramm + "\x1b[0m" "  |  26  |  " + vec[26] + "\n";
	for (unsigned i(51); i < 54; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "  |  " + vec[i] + "\n";
	}
	for (unsigned i(73); i < 75; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "  |  " + vec[i] + "\n";
	}
}

void Colors_4_bits() {
	std::cout << "\n4-bit (16 colors)\n";
	for (unsigned i(30); i < 38; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "\n";
	}
	for (unsigned i(90); i < 98; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "\n";
	}
	for (unsigned i(40); i < 48; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "\n";
	}
	for (unsigned i(100); i < 108; ++i) {
		std::cout << "\x1b[" << i << "m" + pangramm + "\x1b[0m" "  |  " << i << "\n";
	}
}

void Colors_8_bits() {
    std::cout << "\n";
	std::cout << "8-bit (256 colors)\tforeground CSI 38;5;n m\tbackground CSI 48;5;n m\n";
    std::cout << "------------------\n";
	std::string code;
	unsigned intcode;
	for (unsigned i(0); i < 16; ++i) {
		for (unsigned j(0); j < 16; ++j) {
			intcode = i * 16 + j;
			code = std::to_string(intcode);
			if (intcode < 10) {
				std::cout << "\x1b[38;5;" << intcode << "m" + code + "   ";
				continue;
			}
			if (intcode < 100) {
				std::cout << "\x1b[38;5;" << intcode << "m" + code + "  ";
				continue;
			}
			std::cout << "\x1b[38;5;" << intcode << "m" + code + " ";
		}
		std::cout << "\n";
	}
	for (unsigned i(0); i < 16; ++i) {
		for (unsigned j(0); j < 16; ++j) {
			intcode = i * 16 + j;
			code = std::to_string(intcode);
			if (intcode < 10) {
				std::cout << "\x1b[48;5;" << intcode << "m" + code + "   \x1b[0m";
				continue;
			}
			if (intcode < 100) {
				std::cout << "\x1b[48;5;" << intcode << "m" + code + "  \x1b[0m";
				continue;
			}
			std::cout << "\x1b[48;5;" << intcode << "m" + code + " \x1b[0m";
		}
		std::cout << "\n";
	}
	std::cout << "Grayscale colors:\n";
	for (unsigned i(232); i < 244; ++i) {
		std::cout << "\x1b[38;5;" << i << "m" << i << " \x1b[0m";
	}
	for (unsigned i(244); i < 256; ++i) {
		std::cout << "\x1b[38;5;" << i << "m" << i << " \x1b[0m";
	}
	std::cout << "\n";
	for (unsigned i(232); i < 244; ++i) {
		std::cout << "\x1b[48;5;" << i << "m" << i << " \x1b[0m";
	}
	for (unsigned i(244); i < 256; ++i) {
		std::cout << "\x1b[48;5;" << i << "m" << i << " \x1b[0m";
	}
}

void set_sgr_doc(SgrDoc& vec) {
	vec[0] = "Normal";
	vec[1] = "Bold/increased intensity";
	vec[2] = "Faint/decreased intensity";
	vec[3] = "Italic";
	vec[4] = "Underlined";
	vec[5] = "Slow blink";
	vec[6] = "Rapid blink";
	vec[7] = "Reverse video";
	vec[8] = "Conceal";
	vec[9] = "Crossed-out";
	vec[10] = "Default font";
	for (unsigned i(11); i < 20; ++i) {
		vec[i] = "Alternative font";
	}
	vec[20] = "Gothic";
	vec[21] = "Double-underline/not bold";
	vec[26] = "Proportional spacing";
	vec[51] = "Framed";
	vec[52] = "Circled";
	vec[53] = "Overlined";
	vec[73] = "Superscript";
	vec[74] = "Underscript";
}
