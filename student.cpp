#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to represent a student
class Student {
public:
    string name;
    int rollNumber;
    string address;
    double gpa;

    // Function to input student details
    void inputDetails() {
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();  // Clear the input buffer

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter GPA: ";
        cin >> gpa;
    }

    // Function to display student details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Address: " << address << endl;
        cout << "GPA: " << gpa << endl;
    }
};

// Function to search for a student by roll number
int searchStudent(const vector<Student>& students, int rollNumber) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].rollNumber == rollNumber) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Record Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Student Details" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the input buffer

        switch (choice) {
            case 1: {
                Student newStudent;
                newStudent.inputDetails();
                students.push_back(newStudent);
                cout << "Student added successfully!" << endl;
                break;
            }

            case 2: {
                int rollNumber;
                cout << "Enter Roll Number to display details: ";
                cin >> rollNumber;
                int index = searchStudent(students, rollNumber);
                if (index != -1) {
                    students[index].displayDetails();
                } else {
                    cout << "Student not found!" << endl;
                }
                break;
            }

            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
