#include<iostream>
#include<string>
#include"Student.h"
#include<fstream>
#include<Windows.h>
#include"List.h"

List task(const List& list)
{
	List new_list;
	ptrNODE ptr = list.get_head();
	bool fg = false;

	while (ptr && !fg)
	{
		// Проверяем количество двоек у студента
		if (!ptr->info.count_twos_more_than_2()) // Если двоек меньше 3, добавляем в новый список
		{
			new_list.add_to_tail(ptr->info);
		}
		else
			fg = true;
		ptr = ptr->next; // Переход к следующему узлу
	}

	return new_list; // Возвращаем новый список без студентов с задолженностями
}

int main()
{
	SetConsoleOutputCP(1251);

	std::ifstream file("data.txt");//инициализирующий конструктор
	List list(file);
	list.print();
	std::cout << "------------------------------------------------\n";

	List list2 = list;//конструктор копирования
	list2.print();
	std::cout << "-------------------------------------------------\n";

	List list3(file);
	list3 = list;//оператор копирования
	list3.print();
	std::cout << "-------------------------------------------------\n";

	List list4 = std::move(task(list));//конструктор перемещения
	if (list4.get_head() == nullptr)
		std::cout << "У всех студентов была задолженность с 3ём или более долгам.\n";
	else
		list4.print();
	std::cout << "-------------------------------------------------\n";

	list3 = task(list);// оператор перемещения 
	if (list3.get_head() == nullptr)
		std::cout << "У всех студентов была задолженность с 3ём или более долгам.\n";
	else
		list3.print();

	std::cin.ignore();
	return 0;
}