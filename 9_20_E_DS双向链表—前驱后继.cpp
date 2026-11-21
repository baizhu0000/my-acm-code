#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DList {
   public:
    Node* head;
    Node* tail;
    int len;

    DList() {
        head = NULL;
        tail = NULL;
        len = 0;
    }

    ~DList() {
        Node* p = head;
        while (p != NULL) {
            Node* q = p;
            p = p->next;
            delete q;
        }
        head = NULL;
        tail = NULL;
    }

    void add(int x) {
        Node* q = new Node(x);
        if (head == NULL) {
            head = tail = q;
        } else {
            tail->next = q;
            q->prev = tail;
            tail = q;
        }
        len++;
    }

    Node* find(int key) {
        Node* p = head;
        while (p != NULL) {
            if (p->data == key)
                return p;
            p = p->next;
        }
        return NULL;
    }

    void query(int key) {
        Node* p = find(key);
        if (p == NULL) return;

        bool first = true;
        if (p->prev != NULL) {
            cout << p->prev->data;
            first = false;
        }
        if (p->next != NULL) {
            if (!first) cout << " ";
            cout << p->next->data;
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DList list;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.add(x);
    }

    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;
        list.query(key);
    }

    return 0;
}