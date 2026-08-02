#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of rotations: ";
    cin >> h;

    h = h % n;

    for(int k=0; k<h; k++)
    {
        int first = arr[0];

        for(int i=0; i<n-1; i++)
        {
            arr[i] = arr[i+1];
        }

        arr[n-1] = first;
    }

    cout << "Final Array:\n";

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
