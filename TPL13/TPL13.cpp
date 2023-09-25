﻿/*
Работать необходимо с динамическим выделением памяти............................
● Не использовать STL контейнеры для реализации программы..................
● Реализовать полное пользовательское меню согласно заданию. Не должно............
быть аргументов, которые явно задаются в исходном коде, пользователь..............
имеет максимальные возможности при работе с программой, все параметры,...........
которые могут быть введены пользователем, вводятся с клавиатуры.....................
● У пользователя должен быть доступ для взаимодействия с каждым из...........
объектов-наследников: добавлять, удалять, выводить на экран, изменять...........
данные и пр........................................................................
● Создать все конструкторы (с параметрами, без параметров и копирования) и.......
деструктор, использовать переопределение операторов. Каждый вызов...............
конструктора и деструктора должен сопровождаться выводом этой.................
информации пользователю (какой объект, какой конструктор или деструктор..........
вызван)..............................................................................
● Определить в классе методы для просмотра и установки значений (set и get........
функции).................................................................................
● Определить исключения (exceptions) и применить в программе. Каждое
исключение должно сопровождаться текстом, поясняющим возникшую
исключительную ситуацию.
● Классы-наследники от базового класса должны определять свою сущность по...............
переменным и методам для работы с ними. Например, у животного есть тип,........
пол, возраст, имя, хозяин, описание и т.д. В задании определено некоторое.........
описание характеристик............................................................
● По списку студент определяет свой порядковый номер и этому номеру...............
соответствует номер задания в таблице. Общее задание расположено перед.........
таблицей..........................................................................
● Необходимо выполнить разделение на h и cpp файлы для каждого класса. h.........
файлы содержат определение, cpp файлы содержат реализацию. Функция.........
main обязана располагаться в отдельном cpp файле.............................

Разработать класс Keeper, который реализует контейнер для хранения и обработки..........
объектов. Класс Keeper должен обеспечивать следующие функции:.........................
▪ добавление и удаление производных объектов абстрактного класса Base (базовый......
класс определяется согласно варианту задания);.......................................
▪ полное сохранение себя в файле;......................................................
▪ полное восстановление себя из файла..................................................

Класс Фабрика хранит данные о мебели, работниках и машинах.Для мебели...........
определено: тип мебели, габариты (высота, ширина, глубина), цвет, материал,.........
стоимость. Для работника определено: ФИО, должность, заработная плата,............
адрес проживания, телефон. Для машины определено: марка, модель,................
гос.номер........................................................................
*/
#include "Factory.h"
#include "Furniture.h"
#include "Worker.h"
#include "Car.h"
#include "Menu.h"
#include "Keeper.h"

int main() {
	try {
		Menu();
	}
	catch (...) {
		std::cout << "ВЫ пидарас\n";
	}
	return 0;
}