#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Resident
{
	char* _name;

public:
	Resident();
	Resident(const char* name);
	Resident(const Resident& objCopy);
	Resident& operator = (const Resident& objCopy);
	~Resident();

	void setName(const char* name);
	const char* getName()const;

	void showName()const;
};

