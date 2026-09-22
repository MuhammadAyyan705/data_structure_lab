#include <iostream>
using namespace std;

int main()
{
    int parking[4][5] = {
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 0, 1, 1}
    };

    int occupied = 0;
    int empty = 0;
    int row, column;

    // Display parking layout
    cout << "Parking Layout:" << endl;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << parking[i][j] << " ";
        }

        cout << endl;
    }

    // Count occupied and empty spaces
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (parking[i][j] == 1)
            {
                occupied++;
            }
            else
            {
                empty++;
            }
        }
    }

    cout << "\nTotal Occupied Spaces = " << occupied << endl;
    cout << "Total Empty Spaces = " << empty << endl;

    // Ask user for row and column
    cout << "\nEnter row number (1-4): ";
    cin >> row;

    cout << "Enter column number (1-5): ";
    cin >> column;

    // Check selected space
    if (parking[row - 1][column - 1] == 0)
    {
        cout << "The parking space is available." << endl;
    }
    else
    {
        cout << "The parking space is occupied." << endl;
    }

    // Display parking capacity and occupancy
    cout << "\nTotal Parking Capacity = 20" << endl;
    cout << "Current Occupancy = " << occupied << endl;

    return 0;
}