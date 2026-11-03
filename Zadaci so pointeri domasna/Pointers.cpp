#include <iostream>
using namespace std;

void printarr(int *arr, int len)
{
    for (int i=0; i<len; i++, arr++)
    {
        cout << *arr << " ";
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printarr(arr, 10);

    return 0;
}





//1.2

#include <iostream>
using namespace std;

void swap_pointer (int *x, int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}

void swap_refrence (int &x, int &y)
{
    int t=x;
    x=y;
    y=t;
}

int main()
{
    int a=1, b=2;

    int *ap=&a, *bp=&b;

    swap_pointer(ap, bp);

    cout << a << " " << b;

    swap_refrence(a, b);

    cout << a << " " << b;

    return 0;
}






//1.3

#include <iostream>
using namespace std;

void bubble_sort(int *a, int len)
{
    int *x=a, *y=a;

for (int i=0; i < len; i++, x++)
{
for (int j = 0; j < len - i - 1; j++, y++)
{
if (*y > *(y+1))
{
int t = *y;
*y = *(y + 1);
*(y+1) = t;
}
}
y=a;
}
}

int main()
{
    int arr[10] = {5, 2, 10, 8, 9, 1, 7, 4, 6, 3};

    bubble_sort(arr, 10);

    int *p=arr;

    for (int i=0; i<10; i++, p++) cout << *p << " ";

return 0;
}








//1.4

#include <iostream>
using namespace std;

void bubble_sort(int *a, int len)
{
    int *x=a, *y=a;

for (int i=0; i < len; i++, x++)
{
for (int j = 0; j < len - i - 1; j++, y++)
{
if (*y > *(y+1))
{
int t = *y;
*y = *(y + 1);
*(y+1) = t;
}
}
y=a;
}
}

int bin_search_r(int *arr, int start, int end, int key)
{
    int r = -1;
    if (start > end) return r;
    else
    {
        int mid = (start + end) / 2;
        if (*(arr+mid) == key) return mid;
        if (*(arr+mid) > key) r = bin_search_r(arr, start, mid - 1, key);
        if (*(arr+mid) < key) r = bin_search_r(arr, mid + 1, end, key);

        return r;
    }
}

int bin_search(int *arr, int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (*(arr+mid) == key) return mid;
        if (*(arr+mid) > key) end = mid - 1;
        if (*(arr+mid) < key) start = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[10] = {5, 2, 10, 8, 9, 1, 7, 4, 6, 3};
    int key;
    cin >> key;
    bubble_sort(arr, 10);

    int x = bin_search(arr, 0, 9, key);
    if (x == -1) cout << "Not found" << "\n";
    else cout << x << "\n";

    int y = bin_search_r(arr, 0, 9, key);
    if (y == -1) cout << "Not found" << "\n";
    else cout << y << "\n";

return 0;
}