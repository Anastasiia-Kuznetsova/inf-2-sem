#include <iostream>
using namespace std;
void doubling(int** arr, unsigned int N);
void doubling(int **a, int N) {
    int* new_a = new int[2 * N];
    for (auto i = 0u; i < N; i++) new_a[i] = (*a)[i];
    delete[] *a;
    *a = new_a;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int up = 0; up < 5; up++)
    {
        for (int i = 0; i < n; i++)
            a[i] = n - i;
        doubling(&a, n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != n - i)
            {
                cout << "NOPE" << endl;
                return 0;
            }
        }
        n *= 2;
    }
    delete[] a;
    cout << "YEP" << endl;
    return 0;
}
