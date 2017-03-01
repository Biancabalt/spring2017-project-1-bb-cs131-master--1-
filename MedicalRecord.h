#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;


class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		
		length = 200000;
		babyWeights = new int[length];
		babyNames = new string[length];
		count = 0;
		lowBabyWeight = 0;
		sNames = 0;

	}

	// destructor
	~MedicalRecord() {
		delete[] babyWeights;
		delete[] babyNames;


	}

	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);
		if (count == 0){
			tempHolder = filename;
		}

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			if(tempHolder == filename) {
				while (myfile >> name >> weight) {
					// cout << name << " " << weight << endl;
					Baby b(name, weight);
					addEntry(b);
				}
			} else
			{
				count = 0;
				sNames = 0;
				lowBabyWeight = 0;
				tempHolder = filename; 
				while (myfile >> name >> weight) {
					// cout << name << " " << weight << endl;
					Baby b(name, weight);
					addEntry(b);
				}
			}

			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	string mostPopularName() {
		string nameHolder;
		string commonName;
		int firstCount = 1, tempCount;
		for (int i = 0; i < (count-1); i++) {
			nameHolder = babyNames[i];
			tempCount = 0;
			for (int j = i + 1; j < count; j++) { 
				if (nameHolder == babyNames[j]) {
					tempCount++;
				}
				if (firstCount < tempCount) {
					commonName = nameHolder;
					firstCount = tempCount;
				}
			}
		}

		return commonName; 
	}

	// Return the number of baby records loaded from the text file
	int numberOfBirths() {

		return count; 
	}

	// Return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		for(int i = 0; i < count; i++) {
			if (babyWeights[i] < 2500) {
				lowBabyWeight = lowBabyWeight + 1;
			}
		}

		return lowBabyWeight; 
	}

	// Return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {

		for (int i = 0; i <= count; i++) {
			if (s == babyNames[i]) {
				sNames++;
			}
		}

		return sNames;
	}

private:
	// Update the data structure with information contained in Baby object
	void addEntry(Baby b) { 

		babyNames[count] = b.getName();
		babyWeights[count] = b.getWeight();
		count++;

	}
	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
	int *babyWeights;
	string *babyNames;
	int length;
	string tempHolder;
	int count;
	int lowBabyWeight;
	int sNames;

};
