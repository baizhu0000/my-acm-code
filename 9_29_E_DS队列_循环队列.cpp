#include <iostream>
#include <string>
using namespace std;

class MyCircularQueue {
   private:
    int* data;
    int cap;
    int front;
    int count;

   public:
    MyCircularQueue(int k) {
        cap = k;
        data = new int[cap];
        front = 0;
        count = 0;
    }

    ~MyCircularQueue() {
        delete[] data;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[(front + count - 1) % cap];
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        data[(front + count) % cap] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        count--;
        return true;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == cap;
    }
};

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    MyCircularQueue q(k);

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "enQueue") {
            int v;
            cin >> v;
            cout << (q.enQueue(v) ? "true" : "false") << endl;
        } else if (op == "deQueue") {
            cout << (q.deQueue() ? "true" : "false") << endl;
        } else if (op == "Front") {
            cout << q.Front() << endl;
        } else if (op == "Rear") {
            cout << q.Rear() << endl;
        } else if (op == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << endl;
        } else if (op == "isFull") {
            cout << (q.isFull() ? "true" : "false") << endl;
        }
    }

    return 0;
}
