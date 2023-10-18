cmake_minimum_required(VERSION 3.21.4)

project(TPL13)


set(SOURCES
	TPL13/main.cpp
)

set(Headers
	TPL13/Factory.h
	TPL13/Furniture.h
	TPL13/Car.h
	TPL13/Worker.h
	TPL13/Keeper.h
	TPL13/Menu.h
)



add_executable(TPL13 ${SOURCES})

target_sources(TPL13 PRIVATE ${Headers})