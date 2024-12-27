#include<iostream>
#include<string>
#include"Student.h"
#include<fstream>
#include<Windows.h>
#include"List.h"

List task(List list)
{
    ptrNODE ptr = list.get_head();
	while (ptr && ptr->info.count_twos() >= 3) {
		ptr = ptr->next;
		list.del_from_head();
	}
    return list; // Возвращаем измененный список
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
		std::cout << "у всех студентов была задолженность с 3ём или более долгам.\n";
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