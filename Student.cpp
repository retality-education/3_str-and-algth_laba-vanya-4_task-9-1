#pragma once
#include "Student.h"

// ����� ��� �������� ���������� �����
int Student::count_twos() const {
	int count = 0;
	for (int grade : grades) {
		if (grade == 2) {
			count++;
		}
	}
	return count;
}

// ���������� ���������� ��� ����� � ������
std::istream& operator>>(std::istream& in, Student& s) {
	std::getline(in, s.FIO);
	in >> s.course;
	in.ignore(255, '\n');
	std::getline(in, s.group);
	std::getline(in, s.education_form);
	for (int i = 0; i < 5; ++i) {
		in >> s.grades[i];
	}
	in.ignore(255, '\n');
	return in;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
	out << "���: " << s.FIO << ", ����: " << s.course
		<< ", ������: " << s.group << ", ����� ��������: "
		<< s.education_form << ", ������������: ";
	for (const auto& grade : s.grades) {
		out << grade << " ";
	}
	return out;
}
// ��������� ��������� �� ���������� �����
bool Student::operator<(const Student& student)  {
	return this->count_twos() < student.count_twos(); // ������ ����� - ����
}

bool Student::operator>=(const Student& student){
	return !(*this < student);
}

bool Student::operator<=(const Student& student) {
	return *this < student || *this == student;
}

bool Student::operator==(const Student& student)  {
	return  this->count_twos() == student.count_twos(); // ��������� �� ���
}

bool Student::operator>(const Student& student) {
	return !(*this <= student);
}

bool Student::operator!=(const Student& student) {
	return !(*this == student);
}