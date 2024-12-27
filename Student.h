#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#pragma once
class Student
{
private:
    std::string FIO; // ФИО
    int course; // Курс
    std::string group; // Группа
    std::string education_form; // Форма обучения (договор, бюджет)
    int grades[5]; // Успеваемость - 5 экзаменов за последнюю сессию

public:
    // Конструктор по умолчанию
    Student() : course(0), group(""), education_form(""), grades{ 0 } {}

    // Конструктор с параметрами
    Student(const std::string& FIO, int course, const std::string& group, const std::string& education_form, const int grades[5])
        : FIO(FIO), course(course), group(group), education_form(education_form) {
        for (int i = 0; i < 5; ++i) {
            this->grades[i] = grades[i];
        }
    }

    // Геттеры
    std::string get_FIO() const {
        return FIO;
    }

    int get_course() const {
        return course;
    }

    std::string get_group() const {
        return group;
    }

    std::string get_education_form() const {
        return education_form;
    }

    const int* get_grades() const {
        return grades;
    }
    friend std::istream& operator>>(std::istream& in, Student& t);
    friend std::ostream& operator<<(std::ostream& out, const Student& t);
    int count_twos() const;
    bool operator<(const Student& Student);
    bool operator>=(const Student& Student);
    bool operator<=(const Student& Student);
    bool operator==(const Student& Student);
    bool operator >(const Student& Student);
    bool operator !=(const Student& Student);
};
