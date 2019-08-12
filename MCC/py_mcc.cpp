#include "py_mcc.h"

float match_xyt(std::string &buffer1, std::string &buffer2) {
  	MCC a1;
	MCC a2;

	// unsigned int Ns = 8;
	// unsigned int consolidation = 3;
	// bool convexhull = true;
	// bool bit = false;
	// MCC::configureAlgorithm(Ns, consolidation, convexhull, 0, bit);

	std::vector<char*> cstrings;
	string name = "./mcc";
	cstrings.push_back(const_cast<char*>(name.c_str()));
	cstrings.push_back("1");  // dummy argument 1
	cstrings.push_back("2");  // dummy argument 2

	MCC::configureAlgorithm(3, cstrings.data());
	if(a1.readXYTBuffer(buffer1)) {
			cout << "Error opening fingerprint buffer 1 " << endl;
			return 0;
	}

	if(a2.readXYTBuffer(buffer2)) {
			cout << "Error opening fingerprint buffer 2 " << endl;
			return 0;
	}

	a1.initialize();
	a2.initialize();

	float score = a1.match(a2);
	
	return score;
}

float match_iso(char * buffer1, char *buffer2)
{
    	MCC a1;
	MCC a2;

	// unsigned int Ns = 8;
	// unsigned int consolidation = 3;
	// bool convexhull = true;
	// bool bit = false;
	// MCC::configureAlgorithm(Ns, consolidation, convexhull, 0, bit);

	std::vector<char*> cstrings;
	string name = "./mcc";
	cstrings.push_back(const_cast<char*>(name.c_str()));
	cstrings.push_back("1");  // dummy argument 1
	cstrings.push_back("2");  // dummy argument 2

	MCC::configureAlgorithm(3, cstrings.data());
	if(a1.read19794buffer(buffer1)) {
			cout << "Error opening fingerprint buffer 1 " << endl;
			return 0;
	}

	if(a2.read19794buffer(buffer2)) {
			cout << "Error opening fingerprint buffer 2 " << endl;
			return 0;
	}

	a1.initialize();
	a2.initialize();

	float score = a1.match(a2);
	
	return score;
}

extern "C" {
  extern float match_xyt_buffer(char *arg1, char *arg2) {
    std::string str1 = arg1;
    std::string str2 = arg2;
    return match_xyt(str1, str2);
  }

  extern float match_iso_buffer(char *arg1, char *arg2) {
    return match_iso(arg1, arg2);
  }
}
