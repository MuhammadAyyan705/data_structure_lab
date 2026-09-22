#include <iostream>
using namespace std;

int main()
{
    int numbers[2][2][2] = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    int search;
    bool found = false;

    cout << "3D Array:" << endl;

    // Display the 3D array
    for (int i = 0; i < 2; i++)
    {
        cout << "\nLayer " << i + 1 << ":" << endl;

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << numbers[i][j][k] << " ";
            }

            cout << endl;
        }
    }

    cout << "\nSearching for: ";
    cin >> search;

    // Search for the number
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (numbers[i][j][k] == search)
                {
                    cout << "\nElement found!" << endl;
                    cout << "Layer: " << i + 1 << endl;
                    cout << "Row: " << j + 1 << endl;
                    cout << "Column: " << k + 1 << endl;

                    found = true;
                }
            }
        }
    }

    if (found == false)
    {
        cout << "\nElement not found!" << endl;
    }

    return 0;
}