#include <iostream>
#include <string>
using namespace std;

int linearSearch(string plates[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (plates[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    string plates[n];

    cout << "Enter license plates:\n";
    for (int i = 0; i < n; i++)
        cin >> plates[i];

    string target;
    cout << "Enter target plate: ";
    cin >> target;

    int pos = linearSearch(plates, n, target);

    if (pos != -1)
        cout << "Plate found at position: " << pos;
    else
        cout << "Plate not found";

    return 0;
}
