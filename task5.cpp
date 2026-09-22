#include <iostream>
using namespace std;

int main()
{
    int computers[2][3][5] = {
        {
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {1, 0, 0, 1, 1}
        },
        {
            {0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 1}
        }
    };

    int available = 0;
    int inUse = 0;

    // Display all computers
    for (int i = 0; i < 2; i++)
    {
        cout << "\nLab " << i + 1 << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Row " << j + 1 << ": ";

            for (int k = 0; k < 5; k++)
            {
                cout << computers[i][j][k] << " ";
            }

            cout << endl;
        }
    }

    // Count available and in-use computers
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (computers[i][j][k] == 0)
                {
                    available++;
                }
                else
                {
                    inUse++;
                }
            }
        }
    }

    cout << "\nTotal Available Computers = " << available << endl;
    cout << "Total Computers In Use = " << inUse << endl;

    // Available computers in each lab
    cout << "\nAvailable Computers in Each Lab:" << endl;

    for (int i = 0; i < 2; i++)
    {
        int labAvailable = 0;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (computers[i][j][k] == 0)
                {
                    labAvailable++;
                }
            }
        }

        cout << "Lab " << i + 1 << " = " << labAvailable << endl;
    }

    // Ask user for lab, row and computer
    int lab, row, computer;

    cout << "\nEnter lab number (1-2): ";
    cin >> lab;

    cout << "Enter row number (1-3): ";
    cin >> row;

    cout << "Enter computer number (1-5): ";
    cin >> computer;

    // Check selected computer
    if (computers[lab - 1][row - 1][computer - 1] == 0)
    {
        cout << "The computer is Available." << endl;
    }
    else
    {
        cout << "The computer is In Use." << endl;
    }

    return 0;
}