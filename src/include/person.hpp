#include <iostream>

using namespace std;

class Person {
    public:
        string profession;
        int age;

        Person() : profession("unemployed"), age(16) { }
        
        void display() {
            cout << "My profession is: " << profession << endl;
            cout << "My age is: " << age << endl;
            walk();
            talk();
        }

        void walk() { cout << "I can walk." << endl; }
        void talk() { cout << "I can talk." << endl; }
};

class MathsTeacher : public Person {
    public:
        void teachMaths() { cout << "I can teach Maths." << endl; }
};

class Footballer : public Person {
    public:
        void playFootball() { cout << "I can play football." << endl; }
};

void output() {
    
    cout << endl;

    cout << "Inheritance example with Person class." << endl;

    cout << endl;

    MathsTeacher teacher;
    teacher.profession = "Teacher";
    teacher.age = 23;
    teacher.display();
    teacher.teachMaths();

    cout << endl;

    Footballer footballer;
    footballer.profession = "Footballer";
    footballer.age = 19;
    footballer.display();
    footballer.playFootball();

    cout << endl;

    cout << "Inheritance example with Person class." << endl;

    cout << endl;

    cout << "End of file run." << endl;

    cout << endl;
}