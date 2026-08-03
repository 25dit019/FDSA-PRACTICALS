#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, high, target);

    return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main()
{
    int n;
    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted book codes:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter target code: ";
    cin >> target;

    int iterative = binarySearch(arr, n, target);
    int recursive = recursiveBinarySearch(arr, 0, n - 1, target);

    if (iterative != -1)
        cout << "\nIterative Binary Search: Found at position " << iterative;
    else
        cout << "\nIterative Binary Search: Not Found";

    if (recursive != -1)
        cout << "\nRecursive Binary Search: Found at position " << recursive;
    else
        cout << "\nRecursive Binary Search: Not Found";

    return 0;
}
