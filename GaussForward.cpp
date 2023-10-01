#include <bits/stdc++.h>
using namespace std;

int main()
{
    float a[10][10], x, u1, u, y;
    int i, j, n, n1, fact = 1;

    cout << "Enter the n: ";
    cin >> n;

    cout << "Enter the x: ";
    for (i = 0; i < n; i++)
        cin >> a[i][0];

    cout << "Enter the y: ";
    for (i = 0; i < n; i++)
        cin >> a[i][1];

    cout << "Enter the value to predict: ";
    cin >> x;

    for (j = 2; j < n + 1; j++)
    {
        for (i = 0; i < n - j + 1; i++)
        {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    cout << "The difference table is: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n - i; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }

    y = a[n / 2][1];
    cout << "\ny: " << y;

    u = (x - a[n / 2][0]) / (a[1][0] - a[0][0]);
    u1 = u;
    cout << "\n"
         << u1;

    for (i = 2; i <= n; i++)
    {
        y = y + (u1 / fact) * a[(n - 1) / i][i];
        cout << a[(n - 1) / i][i] << "\t";
        fact = fact * i;

        if (i % 2 == 0)
        {
            u1 = u1 * (u - (i / 2));
            cout << "\n"
                 << u1;
        }
        else
        {
            u1 = u1 * (u + (i / 2));
            cout << "\n"
                 << u1;
        }
    }

    cout << "\n\nThe desired value is: " << y << endl;
    return 0;
}

/*
Enter no. of rows  :-> 5
ENTER VALUE OF X :-> 0 4 8 12 16
ENTER VALUE OF Y :-> 14 24 32 35 40
ENTER THE VALUE TO PREDICT :->9
PRINTING THE DIFFERENCE TABLE :->
0 14 10 -2 -3 10
4 24 8 -5 7 6.92355e-310
8 32 3 2 0 0
12 35 5 0 0 0
16 40 0 0 0 0
y = 32
u = 0.25
Desired value :->33.0645 */
