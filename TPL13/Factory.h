#pragma once


#include <iostream>

#define DEBUG

class Factory {		//
public:
	virtual void operator<< (std::ostream& out) = 0;
	virtual void setData() = 0;
	virtual void getData() = 0;
	virtual void FsetData(std::ifstream& in) = 0;

	virtual ~Factory() {
#ifdef DEBUG
		std::cout << "Деструктор Factory\n";
#endif // DEBUG	
	};


};