#pragma once
#include <iostream>
#include <string>
#define DEBUG
class Factory {		//абстрактный базовый класс
public:
	
	virtual void setData() = 0;
	virtual void getData(std::ofstream& out) = 0;
	virtual void FsetData(std::ifstream& in) = 0;

	virtual ~Factory() {
#ifdef DEBUG
		std::cout << "Destructor Factory\n";
#endif // DEBUG	
	};
};