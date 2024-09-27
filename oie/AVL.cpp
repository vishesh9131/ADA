#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < size() && heap[left] > heap[largest])
            largest = left;

        if (right < size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return (2 * index + 1); }
    int rightChild(int index) { return (2 * index + 2); }

public:
    unsigned int size() { return heap.size(); }
    bool empty() { return size() == 0; }

    void insert(int key) {
        heap.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    void removeMax() {
        if (size() == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() {
        if (size() == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap.front();
    }
};

int main() {
    MaxHeap h;
    h.insert(3);
    h.insert(1);
    h.insert(4);
    h.insert(1);
    h.insert(5);
    h.insert(9);
    h.insert(2);
    h.insert(6);
    h.insert(5);

    cout << "Max element: " << h.getMax() << endl;

    h.removeMax();
    cout << "Max element after removal: " << h.getMax() << endl;

    return 0;
}