
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Course {
public:
    string name;
    double grade;
    int credits;
};

int main() {
    int n;
    double totalCredits = 0;
    double totalGradePoints = 0;

    vector<Course> courses;

    cout << "===== CGPA CALCULATOR =====\n";

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        Course c;

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> c.name;

        cout << "Enter grade point (0-10): ";
        cin >> c.grade;

        cout << "Enter credit hours: ";
        cin >> c.credits;

        if (c.grade < 0 || c.grade > 10 || c.credits <= 0) {
            cout << "Invalid grade or credits!\n";
            return 0;
        }

        courses.push_back(c);

        totalCredits += c.credits;
        totalGradePoints += c.grade * c.credits;
    }

    double gpa = totalGradePoints / totalCredits;

    cout << "\n===== RESULT =====\n";

    cout << left << setw(15) << "Course"
         << setw(15) << "Grade"
         << "Credits\n";

    for (const Course &c : courses) {
        cout << left << setw(15) << c.name
             << setw(15) << c.grade
             << c.credits << endl;
    }

    cout << fixed << setprecision(2);

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nSemester GPA: " << gpa;
    cout << "\nOverall CGPA: " << gpa << endl;

    return 0;
}
