#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class SphereProducer
{
public:
	SphereProducer() {};
	~SphereProducer() {};

	bool produce();

public:
	vector<vector<float>> centers = { {1,1} };
	float sumArea = 3.14;
};