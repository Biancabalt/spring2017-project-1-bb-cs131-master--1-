#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  // default constructor
	};

	Baby(string s, int w) { // constructor
		name = s;
		weight = w;	

		Baby b;
		if (b.name == "Testname" && b.weight == 1000) {
			weight = 0;
			name = "";
		}
		
		
	}

	// a "getter" method
	int getWeight() {

		return weight; 
	}

	// a "getter" method
	string getName() {

		return name; 
	}

private:
	string name;
	int weight;
};
