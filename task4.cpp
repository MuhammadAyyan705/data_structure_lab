#include <iostream>
using namespace std;

int main()
{
    int beds[3][3][4] = {
        {
            {1, 0, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 1}
        },
        {
            {0, 0, 1, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}
        },
        {
            {1, 0, 0, 1},
            {0, 1, 0, 1},
            {1, 1, 1, 0}
        }
    };

    int occupied = 0;
    int available = 0;

    // Display bed status
    for (int i = 0; i < 3; i++)
    {
        cout << "\nFloor " << i + 1 << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Ward " << j + 1 << ": ";

            for (int k = 0; k < 4; k++)
            {
                cout << beds[i][j][k] << " ";
            }

            cout << endl;
        }
    }

    // Count occupied and available beds
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (beds[i][j][k] == 1)
                {
                    occupied++;
                }
                else
                {
                    available++;
                }
            }
        }
    }

    cout << "\nTotal Occupied Beds = " << occupied << endl;
    cout << "Total Available Beds = " << available << endl;

    // Occupied beds on each floor
    cout << "\nOccupied Beds on Each Floor:" << endl;

    for (int i = 0; i < 3; i++)
    {
        int floorOccupied = 0;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (beds[i][j][k] == 1)
                {
                    floorOccupied++;
                }
            }
        }

        cout << "Floor " << i + 1 << " = " << floorOccupied << endl;
    }

    // Ask user for floor, ward and bed
    int floor, ward, bed;

    cout << "\nEnter floor number (1-3): ";
    cin >> floor;

    cout << "Enter ward number (1-3): ";
    cin >> ward;

    cout << "Enter bed number (1-4): ";
    cin >> bed;

    // Check selected bed
    if (beds[floor - 1][ward - 1][bed - 1] == 0)
    {
        cout << "The bed is available." << endl;
    }
    else
    {
        cout << "The bed is occupied." << endl;
    }

    return 0;
}