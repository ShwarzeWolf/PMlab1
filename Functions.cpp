#include <iostream> 
#include <vector>
#include <tuple>
#include "Functions.h"
//#include <iomanip> 

using namespace std;

const int numberOfValues = 100;

float findAverageValue (const vector<int> & values) {
	float sum = 0.0;

	for (auto i = values.begin (); i != values.end (); ++i)
		sum += *i;

	return sum / numberOfValues;
}

float findDispersion (const vector<int> & values) {
	float averageValue = findAverageValue (values);

	float dispersionSumSquare = 0.0;

	for (auto i = values.begin (); i != values.end (); ++i)
		dispersionSumSquare += pow (*i - averageValue, 2) / numberOfValues;


	return dispersionSumSquare;
}

float findMedian (const vector<int> & values) {
	return (values.at (numberOfValues / 2 - 1) + values.at (numberOfValues / 2)) / 2.0;
}
 
int findFashion (const vector <int> & values) {
	int amountOfNum = 0, result = 0, resultValue = 0;

	for (auto i = values.begin (); i != values.end () - 1; ++i)
	{
		if (*i == *(i + 1))
			amountOfNum++;
		else
		{
			if (amountOfNum > result)
			{
				result = amountOfNum;
				resultValue = *i;
			}
			amountOfNum = 0;
		}
	}
	return resultValue;
}

int findMax (const vector <int> & values) {
	return values.at (numberOfValues - 1);
}

int findMin (const vector <int> & values) {
	return values.at (0);
}

tuple<int, int, int> findQuartiles (const vector <int> & values) {
	int firstQuartile = values.at (0.25 * (numberOfValues));
	int secondQuartile = values.at (0.5 * (numberOfValues));
	int thirdQuartile = values.at (0.75 * (numberOfValues));

	return (make_tuple (firstQuartile, secondQuartile, thirdQuartile));
}

float findSampleVariance (const vector<int> & values) {
	float sampleVariance = 0.0;
	float averageValue = findAverageValue (values);

	for (auto i = values.begin(); i != values.end(); ++i) 
		sampleVariance += pow ((*i - averageValue), 2);
	
	return sampleVariance / 100.0;
}

int findModa (const vector<int> & values) {
	int moda = 0;
	int modaQuantity = 0;

	int counter = 0;
	bool sameAmount = false;

	for (auto i = values.begin () + 1; i != values.end (); ++i) {
		if (*i == *(i - 1) )
			++counter;
		else {
			if (counter > modaQuantity) {
				modaQuantity = counter;
				moda = *(i - 1);
				sameAmount = false;
			}
			else if (modaQuantity == counter)
				sameAmount = true;

			counter = 0;
		}
	}

	return sameAmount ? -1 : moda;
}

float findExcess (const vector<int> & values) {
	float excess = 0.0;
	float averageValue = findAverageValue (values);

	for (auto i = values.begin (); i != values.end (); ++i)
		excess += pow ((*i - averageValue), 4);
	
	return excess / 100.0 / pow (findStandartDeviation (values), 4);
}

float findAsimetria (const vector<int> & values) {
	float asimetria = 0.0;
	float averageValue = 0.0;

	for (auto i = values.begin (); i != values.end (); ++i) 
		asimetria += pow ((*i - averageValue), 3);
	
	//îòêóäà ýòè magic numbers? 
	return asimetria / 100.0 / pow (findStandartDeviation (values), 3) - 3;
}


float findStandartError (const vector<int> & values) {
	return sqrt(findDispersion (values) / (numberOfValues));
}

float findStandartDeviation (const vector<int> & values) {
	float standartDeviation = 0.0;
	float averageValue = findAverageValue (values);

	for (auto i = values.begin (); i != values.end (); ++i)
		standartDeviation = standartDeviation + pow ((*i - averageValue), 2);

	return sqrt (standartDeviation / 99.0);
}


void printConfidenceIntervalMat (const vector<int> & values) {
	const float styudentCoefficient = 1.9842;
	float averageValue = findAverageValue (values);
	float standartDeviation = findStandartDeviation (values);

	float x1 = averageValue - styudentCoefficient * sqrt (standartDeviation) / sqrt (numberOfValues);
	float x2 = averageValue + styudentCoefficient * sqrt (standartDeviation) / sqrt (numberOfValues);

	cout << x1 << ' ' << x2 << endl;
}

void printConfidenceIntervalSrkv (const vector<int> & values) {
	const float coeff = 0.143;
	float standartDeviation = findStandartDeviation (values);

	float x1 = sqrt (standartDeviation) * (1.0 - coeff);
	float x2 = sqrt (standartDeviation) * (1.0 + coeff);

	cout << x1 << ' ' << x2 << endl;

}

void
pirson (int a[100])
{
  double PirsonKr = 65.41016;
  double b[6][47];
  SortArray (a);
  b[0][0] = a[0];
  int k = 0;
  int n = 1;
  double aver = average (a);
  for (int i = 1; i < 100; ++i)
    {
      if (a[i] != b[0][k])
	{
	  b[1][k] = n;
	  ++k;
	  b[0][k] = a[i];
	  n = 0;
	}

      if (a[i] == b[0][k])
	++n;
    }
  b[1][46] = n;

  for (int i = 0; i < 47; ++i)
    {
      b[2][i] = (b[0][i] - aver) / standart_deviation (a);
      b[3][i] = 1 / sqrt (2 * M_PI) * pow (M_E, -pow ((b[2][i]), 2) / 2);
      b[4][i] = 100 / standart_deviation (a) * b[3][i];
      b[5][i] = pow ((b[1][i] - b[4][i]), 2) / b[4][i];
    }

  double PirsonNab = 0;

  for (int i = 0; i < 47; ++i)
    PirsonNab = PirsonNab + b[5][i];
  if (PirsonNab < PirsonKr)
    cout B +"Satisfy";

  else
    cout B +"Does not satisfy";


}
