cmake_minimum_required(VERSION 3.26.4)


project(TPL13)


set {Headers
	Factory.h
	Furniture.h
	Car.h
	Worker.h
	Keeper.h
	Menu.h
}



add_executable(TPL13 TPL13.cpp)

target_sources(TPL13 PRIVATE ${Headers})