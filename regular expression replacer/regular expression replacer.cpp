#include "regular expression replacer.h"

using namespace std;

bool fileca(char*, char*, char*, char*);

void autowhile(ifstream&, ofstream&, regex&, char*);

int main(int argc, char* argv[]) {
	cout << initxt << endl;
	if (argc > argsneeded) {
		if (argc > argsneeded + 1) {
			if (!fileca(argv[0 + toappendcount], argv[2 + toappendcount], argv[1 + toappendcount], argv[3 + toappendcount])) {
				return -1;
			}
			else {
				cout << enccode << endl;
			}
		}
		else {
			if (!fileca(argv[0 + toappendcount], argv[2 + toappendcount], argv[1 + toappendcount], nothing)) {
				return -1;
			}
			else {
				cout << enccode << endl;
			}
		}
	}
	else {
		cout << helpstr << endl;
	}
	return 0;
}

bool fileca(char* filename, char* regexp, char* outfile, char* tolll) {
	ifstream infile(filename);
	ofstream data(outfile, ios::trunc);
	if (infile.fail()) {
		cerr << errtext << filename << errtextb << "Reading" << endl;
		return false;
	}
	if (data.fail()) {
		cerr << errtext << outfile << errtextb << "Writing" << endl;
		return false;
	}
	regex e(regexp);
	autowhile(infile, data, e, tolll);
	data.close();
	infile.close();
	return true;
}

void autowhile(ifstream& inf, ofstream& dat, regex& e, char* toit) {
	string line;
	while (getline(inf, line)) {
		dat << regex_replace(line, e, toit) << endl;
	}
}
