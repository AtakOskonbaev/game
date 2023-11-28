#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    srand(time(NULL));
    cout << "Welcome to the Memore Game!" << endl;
    int n;
    do
    {
        cout << "Enter the even size of an array (6-20): ";
        cin >> n;
    } while (n % 2 != 0 || n < 6 || n > 20);

    int arr[20];
    string que[20];
    int match = 0;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        que[i] = "?";
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[i] = 1 + rand() % 10;
    }
    for (int i = n / 2; i < n; i++)
    {
        arr[i] = arr[i - n / 2];
    }
    random_shuffle(&arr[0], &arr[n]);

    while (true)
    {
        cout << "Here is an array:";

        for (int i = 0; i < n; i++)
        {
            cout << que[i] << " ";
        }
        if (match == (n / 2))
        {
            break;
        }
        int num;
        int num2;
        cout << endl
             << "Enter the index to show: ";
        cin >> num;
        cout << "The card at index " << num << " is " << arr[num - 1] << endl;
        cout << endl
             << "Enter the second index to show: ";
        cin >> num2;
        cout << "The card at index " << num2 << " is " << arr[num2 - 1] << endl;
        if (arr[num - 1] == arr[num2 - 1])
        {
            cout << "Great! The cards are matched. Continue..." << endl
                 << endl;
            match++;
            total++;
            que[num - 1] = to_string(arr[num - 1]);
            que[num2 - 1] = to_string(arr[num2 - 1]);
            cout << "Press Enter to continue...";
            getchar();
            getchar();
        }
        else
        {
            cout << "The cards do not match. Try again!" << endl
                 << endl;
            total++;
            cout << "Press Enter to continue...";
            getchar();
            getchar();
        }
        system("cls");
    }
    system("cls");

    cout << "You win!" << endl;
    cout << "Total moves: " << total;
}