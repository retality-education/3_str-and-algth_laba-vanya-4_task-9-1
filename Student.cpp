#include "Student.h"

// Метод для подсчета количества двоек
bool Student::count_twos_more_than_2() const {
	int count = 0;
	for (int grade : grades) {
		if (grade == 2) {
			count++;
		}
	}
	return count > 2;
}

// Перегрузка операторов для ввода и вывода
std::istream& operator>>(std::istream& in, Student& s) {
	in >> s.FIO >> s.course >> s.group >> s.education_form;
	for (int i = 0; i < 5; ++i) {
		in >> s.grades[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
	out << "ФИО: " << s.FIO << ", Курс: " << s.course
		<< ", Группа: " << s.group << ", Форма обучения: "
		<< s.education_form << ", Успеваемость: ";
	for (const auto& grade : s.grades) {
		out << grade << " ";
	}
	return out;
}
// Операторы сравнения по количеству двоек
bool Student::operator<(const Student& student)  {
	return this->count_twos_more_than_2() < student.count_twos_more_than_2(); // Меньше двоек - выше
}

bool Student::operator>=(const Student& student){
	return !(*this < student);
}

bool Student::operator<=(const Student& student) {
	return *this < student || *this == student;
}

bool Student::operator==(const Student& student)  {
	return  this->count_twos_more_than_2() == student.count_twos_more_than_2(); // Сравнение по ФИО
}

bool Student::operator>(const Student& student) {
	return !(*this <= student);
}

bool Student::operator!=(const Student& student) {
	return !(*this == student);
}