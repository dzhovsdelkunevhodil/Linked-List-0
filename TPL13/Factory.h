#pragma once
#include <iostream>
#include <string>

class Factory {		//абстрактный базовый класс
public:
	
	virtual void setData() = 0;
	virtual ~Factory() {};

private:
	
};