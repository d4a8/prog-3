#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#define N 1e3

using namespace std;
using namespace chrono;

long long c=0;

void shell_sort(vector <int> &x)
{
    for (int gap = N/2; gap > 0; gap = gap/2)
    {
        c++;

        for (int i = gap; i < N; i++)
        {
            c++;

            int temp = x[i];
            int j = i;

            while (j >= gap && temp < x[j - gap])
            {
                x[j] = x[j - gap];
                j -= gap;

                c++;
            }

            x[j] = temp;
        }
    }
}

int main()
{
    int avgc = 0, avgt = 0;
    int a = 1;

    for (int check = 0; check < a; check++)
    {
        srand(time(NULL));
        vector <int> x(N);
        for (int i = 0; i < N; i++) x[i] = rand();

        auto start = high_resolution_clock::now();
        shell_sort(x);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast < microseconds > (end - start);

        avgc += c;
        avgt += duration.count();

        c=0;
    }

    avgc /= a;
    avgt /= a;

    cout << "Iterations: " << avgc << "\n";
    cout << "Time: " << avgt << " microseconds";

    return 0;
}