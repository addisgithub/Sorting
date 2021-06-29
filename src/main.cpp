/**
 * @file main.cpp
 * @brief This is a quick sorting.
 * @author Addis Bogale
 * @date 4/15/2021
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Sorting{
private:
    vector<int> vect;
public: 
    Sorting(vector<int> v){
        vect = v;
    }

void quickSort(vector<int> &a) {
        quickSort(a, 0, a.size());
}
void quickSort(vector<int> &a, int i, int n) {
        if (n <= 1) return;
        int x = a[i + rand()%n];
        int p = i-1, j = i, q = i+n;
        // a[i..p]<x, a[p+1..q-1]??x, a[q..i+n-1]>x
        while (j < q) {
            int comp = a[j] - x;
            if (comp < 0) { // move to beginning of array
                iter_swap(a.begin() + j++, a.begin() + (++p));
            } else if (comp > 0) {
                iter_swap(a.begin() + j,a.begin() + --q); // move to end of array
            } else {
                j++; // keep in the middle
            }
        }
        // a[i..p]<x, a[p+1..q-1]=x, a[q..i+n-1]>x
        quickSort(a, i, p-i+1);
        quickSort(a, q, n-(q-i));
}

void printArray(vector<int> c)
{
    int i;
    for (i=0; i < c.size(); i++)
        printf("%d ", c[i]);
    printf("\n");
} 
};


int main(int, char**) {
    vector<int> value = {3,8,5,6,9};
    Sorting test(value);
    cout << "Sort this vector using quick sort" << endl;
    test.printArray(value);
    
    cout << "Sorted vector" << endl;
    test.quickSort(value);
    test.printArray(value);
    
}
