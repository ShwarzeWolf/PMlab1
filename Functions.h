#pragma once

float findAverageValue (const std::vector<int> & values);

float findDispersion (const std::vector<int> & values);

float findMedian (const std::vector<int> & values);

int findFashion (const std::vector <int> & values);

int findMax (const std::vector <int> & values);

int findMin (const std::vector <int> & values);

std::tuple<int, int, int> findQuartiles (const std::vector <int> & values);

float findSampleVariance (const std::vector<int> & values);

int findModa (const std::vector<int> & values);

float findExcess (const std::vector<int> & values);

float findAsimetria (const std::vector<int> & values);

void printConfidenceIntervalMat (const std::vector<int> & values);

void printConfidenceIntervalSrkv (const std::vector<int> & values);

//choose best option
float findStandartError (const std::vector<int> & values);

float findStandartDeviation (const std::vector<int> & values);