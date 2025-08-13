#include <iostream>
#include<queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete";
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (size > i)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void maxheapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i +1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxheapify(arr, n, largest);
    }
}

void minheapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;  // change
    int right = 2 * i + 2; // change
    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minheapify(arr, n, smallest);
    }
}

void heapSort(int arr[] , int n){
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheapify(arr, n, i);
    }
    for (int heapSize = n - 1; heapSize > 0; heapSize--) {
        swap(arr[0], arr[heapSize]);             // Move max to the end
        maxheapify(arr, heapSize, 0);            // Heapify the reduced heap
    }
    return;
}

int main()
{
    heap h;
    h.insert(20);
    h.insert(30);
    h.insert(10);

    // h.print();
    // h.deletefromHeap();
    // h.print();

    // int arr[5] = {54, 53, 55, 52, 50};
    // int n = 5;
    // for (int i = n / 2 -1; i >=0; i--)
    // {
    //     maxheapify(arr, n, i);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;




    // int arr2[5] = {54, 53, 55, 50, 52};
    // int m = 5;

    // for (int i = m / 2 - 1; i >= 0; i--)
    // {
    //     minheapify(arr2, m, i);
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     cout << arr2[i] << " ";
    // }




    // heapSort(arr,n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;


    // //maxheap
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(1);

    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // cout<<pq.size()<<endl;


    //minheap
    priority_queue<int , vector<int> , greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(1);

    cout<<minheap.top()<<endl;
    minheap.pop();
    cout<<minheap.top()<<endl;
    cout<<minheap.size()<<endl;
    return 0;
}