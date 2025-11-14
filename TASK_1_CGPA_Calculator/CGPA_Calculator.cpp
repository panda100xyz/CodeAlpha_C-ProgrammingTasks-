#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to convert letter grade to grade points
double gradeToPoint(string grade) {
    if (grade == "A") return 4.0;
    if (grade == "A-") return 3.7;
    if (grade == "B+") return 3.3;
    if (grade == "B") return 3.0;
    if (grade == "B-") return 2.7;
    if (grade == "C+") return 2.3;
    if (grade == "C") return 2.0;
    if (grade == "C-") return 1.7;
    if (grade == "D+") return 1.3;
    if (grade == "D") return 1.0;
    return 0.0; // F or invalid grade
}

// Function to calculate GPA for a semester
double calculateGPA(vector<int> credits, vector<string> grades) {
    double totalPoints = 0;
    int totalCredits = 0;
    for (size_t i = 0; i < credits.size(); i++) {
        totalPoints += credits[i] * gradeToPoint(grades[i]);
        totalCredits += credits[i];
    }
    return totalPoints / totalCredits;
}

int main() {
    int semesters;
    cout << "Enter number of semesters: ";
    cin >> semesters;

    double overallPoints = 0;
    int overallCredits = 0;

    for (int s = 1; s <= semesters; s++) {
        int courses;
        cout << "\nSemester " << s << ":\n";
        cout << "Enter number of courses: ";
        cin >> courses;

        vector<int> credits(courses);
        vector<string> grades(courses);

        for (int i = 0; i < courses; i++) {
            cout << "Course " << i+1 << " - Enter credit and grade (e.g., 3 A): ";
            cin >> credits[i] >> grades[i];
        }

        double gpa = calculateGPA(credits, grades);
        cout << "Semester " << s << " GPA: " << fixed << setprecision(2) << gpa << endl;

        for (int i = 0; i < courses; i++) {
            overallPoints += credits[i] * gradeToPoint(grades[i]);
            overallCredits += credits[i];
        }
    }

    double cgpa = overallPoints / overallCredits;
    cout << "\nOverall CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
