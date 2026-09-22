#include <iostream>
using namespace std;

int main()
{
    int marks[6][4] = {
        {75, 80, 85, 90},
        {60, 70, 65, 75},
        {90, 85, 95, 88},
        {55, 65, 70, 60},
        {80, 75, 85, 80},
        {70, 85, 75, 90}
    };

    int total;
    float average;
    int highest;
    int highestTotal = 0;
    int highestStudent = 0;

    // Display marks table
    cout << "Marks Table:" << endl;
    cout << "Student\tEnglish\tMath\tProgramming\tAI" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << "\t";

        for (int j = 0; j < 4; j++)
        {
            cout << marks[i][j] << "\t";
        }

        cout << endl;
    }

    // Total and average of each student
    cout << "\nTotal and Average Marks:" << endl;

    for (int i = 0; i < 6; i++)
    {
        total = 0;

        for (int j = 0; j < 4; j++)
        {
            total = total + marks[i][j];
        }

        average = total / 4.0;

        cout << "Student " << i + 1 << " Total = " << total << endl;
        cout << "Student " << i + 1 << " Average = " << average << endl;

        if (total > highestTotal)
        {
            highestTotal = total;
            highestStudent = i + 1;
        }
    }

    // Highest marks in each subject
    cout << "\nHighest Marks in Each Subject:" << endl;

    for (int j = 0; j < 4; j++)
    {
        highest = marks[0][j];

        for (int i = 1; i < 6; i++)
        {
            if (marks[i][j] > highest)
            {
                highest = marks[i][j];
            }
        }

        if (j == 0)
            cout << "English = " << highest << endl;

        if (j == 1)
            cout << "Mathematics = " << highest << endl;

        if (j == 2)
            cout << "Programming = " << highest << endl;

        if (j == 3)
            cout << "AI = " << highest << endl;
    }

    // Student with highest total
    cout << "\nStudent with Highest Total Marks:" << endl;
    cout << "Student " << highestStudent << " = " << highestTotal << endl;

    return 0;
}