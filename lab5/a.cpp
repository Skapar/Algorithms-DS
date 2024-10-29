#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild, rightChild, smallest;
        while (true) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            smallest = index;

            if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            return -1;
        }
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> array_lengths(N);

    for (int i = 0; i < N; i++) {
        cin >> array_lengths[i];
    }

    MinHeap min_heap;

    for (int i = 0; i < N; i++) {
        min_heap.push(array_lengths[i]);
    }

    int total_cost = 0;

    while (!min_heap.empty()) {
        int first = min_heap.pop();
        int second = min_heap.pop();

        if (second == -1) {
            break;
        }

        int cost = first + second;
        total_cost += cost;

        min_heap.push(cost);
    }

    cout << total_cost << endl;

    return 0;
}
