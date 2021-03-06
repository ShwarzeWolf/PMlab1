#include "stdafx.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "Functions.h"

using namespace std;

const int numberOfValues = 100;

int main(){
	ifstream inputFile;
	inputFile.open("input.txt");

	vector<int> values;
	values.reserve (numberOfValues * sizeof (int));

	int currentValue;

	for (int i = 0; i < numberOfValues; ++i) {
		inputFile >> currentValue;
		values.push_back (currentValue);
	};

	inputFile.close();

	sort (values.begin (), values.end ());

	system ("pause");
    return 0;
}

