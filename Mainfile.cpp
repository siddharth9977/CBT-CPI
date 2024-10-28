#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std; 

class Student {
public:
    string name;
    int rollNo;
    string course;
    string specialisation;
    float marks;
    long long phoneNumber;
    string address;
};

void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
bool isUnique(const vector<Student>& students, int rollNo);
void saveToFile(const vector<Student>& students);
void loadFromFile(vector<Student>& students);

//To add new student 
void addStudent(vector<Student>& students) {
    Student newStudent;
    
    cout << "Enter student name: ";
    cin.ignore(); 
    getline(cin, newStudent.name); 

    do {
        cout << "Enter Roll No.: ";
        cin >> newStudent.rollNo;
        if (!isUnique(students, newStudent.rollNo)) {
            cout << "Roll number already exists. Please enter a unique RollNo: ";
        }
    } while (!isUnique(students, newStudent.rollNo));
    
    cout << "Enter course: ";
    cin.ignore();
    getline(cin, newStudent.course); 
    
    cout << "Enter Specialization: ";
    getline(cin, newStudent.specialisation); 
    
    cout << "Enter marks: ";
    cin >> newStudent.marks;

    cout << "Enter Phone Number: ";
    cin >> newStudent.phoneNumber;

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, newStudent.address);

    students.push_back(newStudent);
    cout << "Student added successfully !!!\n";
}

// Roll No. must be unique
bool isUnique(const vector<Student>& students, int rollNo) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].rollNo == rollNo) return false;
    }
    return true;
}

// To display student data 
void displayStudents(const vector<Student>& students) {
    cout << left; 
    cout << setw(25) << "Name" 
         << setw(15) << "Roll Number" 
         << setw(20) << "Course" 
         << setw(20) << "Specialization" 
         << setw(10) << "Marks" 
         << setw(15) << "Phone Number" 
         << setw(30) << "Address" << "\n";
    
    cout << string(125, '-') << "\n"; 
    
    for (int i = 0; i < students.size(); ++i) {
        cout << setw(25) << students[i].name 
             << setw(15) << students[i].rollNo
             << setw(20) << students[i].course 
             << setw(20) << students[i].specialisation
             << setw(10) << students[i].marks
             << setw(15) << students[i].phoneNumber 
             << setw(30) << students[i].address << "\n";
    }
}

// To save the name into a file
void saveToFile(const vector<Student>& students) {
    ofstream outFile("students2.txt");
    for (int i = 0; i < students.size(); ++i) {
        outFile << students[i].name << " " << students[i].rollNo << " " 
                << students[i].course << " " << students[i].specialisation << " "
                << students[i].marks << " " << students[i].phoneNumber << 
                students[i].address <<"\n";
    }
    outFile.close();
}

// to extract the data from file
void loadFromFile(vector<Student>& students) {
    ifstream inFile("students2.txt");
    Student student;
    while (inFile >> student.name >> student.rollNo >> student.course >> student.specialisation >> student.marks >> student.phoneNumber >>student.address) {
        students.push_back(student);
    }
    inFile.close();
}

int main() {
    vector<Student> students;
    int choice;

    loadFromFile(students);

    do {
        cout << "*** Student Record Management System ***\n";
        cout << "1. Add Student \n";
        cout << "2. Display Students \n";
        cout << "3. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                saveToFile(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                cout << "Exiting the system. \n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
