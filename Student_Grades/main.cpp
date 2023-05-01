// have bug
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int TESTS = 3;
const int STUDENTS = 1;

void getStudentGrades(int studentGrades[][TESTS]){
    int grade = 0;
    for(int student = 0; student < STUDENTS; student++){
        cout << "\nEnter grades for student " << student + 1 << "\n";

        for(int test = 0; test < TESTS; test++){
            cout << "Enter grade on test " << test + 1  << " (0-100): ";
            cin >> grade;

            while(grade < 0 || grade > 100){
                cout << "\nError: Please enter grade int the range 0-100\n";

                cout << "Enter grade " << test + 1 << ": ";
                cin >> grade;
            }

            studentGrades[student][test] = grade;
        }
    }
}

void displayGrades(int studentGrades[][TESTS]){
    double studentTotal = 0.0;
    double testTotal = 0.0;
    double classTotal = 0.0;

    cout << "\nGrade summary\n";
    cout << "--------------\n";
    cout << left << setw(14) << "Student number"
            << right << setw(8) << right << "Test 1"
            << setw(8) << "Test 2"
            << setw(8) << "Test 3"
            << setw(9) << "Average\n";

    for(int student = 0; student << STUDENTS; student++){
        cout << left << setw(14) << student + 1;

        for(int test = 0; test < TESTS; test++){
            int grade = studentGrades[student][test];
            cout << right << setw(8) << grade;

            studentTotal += grade;
            classTotal += grade;
        }
        cout << right << setw(9) << studentTotal / TESTS << "\n";
        studentTotal = 0.0;
    }
    cout << "\n" << left << setw(14) << "Test averages";

    for(int test = 0; test < TESTS; test++){
        for(int student = 0; student < STUDENTS; student++){
            testTotal += studentGrades[student][test];
        }
        cout << right << setw(8) << testTotal / STUDENTS;
        testTotal = 0.0;
    }
    cout << "\n";

    double classAverage = classTotal / (STUDENTS * TESTS);
    cout << "\nClass average: " << classAverage << "\n\n";
}
int main(){

    int studentGrades[STUDENTS][TESTS] = {0};

    getStudentGrades(studentGrades);
    cout << fixed << setprecision(1);
    displayGrades(studentGrades);

    return 0;
}