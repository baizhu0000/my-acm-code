#include <iostream>
using namespace std;
class Node {
   public:
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class List {
   public:
    int len;
    Node* head;
    List() {
        len = 0;
        head = new Node();
    }
    ~List() {
        Node* p = head;
        while (p != NULL) {
            Node* q = p;
            p = p->next;
            delete q;
        }
    }
    void set(int n);
    void reserve(int left, int right);
    void display();
};
void List::set(int n) {
    Node* p = head;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p->next = new Node(x);
        p = p->next;
    }
}
void List::reserve(int left, int right) {
    if (left >= right) {
        return;
    }
    Node* pre = head;
    for (int i = 1; i < left; i++) {
        pre = pre->next;
    }

    Node* cur = pre->next;
    for (int i = 0; i < right - left; i++) {
        Node* nxt = cur->next;
        cur->next = nxt->next;
        nxt->next = pre->next;
        pre->next = nxt;
    }
}
void List::display() {
    Node* p = head->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        List list;
        list.set(n);
        int l, r;
        cin >> l >> r;
        list.reserve(l, r);
        list.display();
    }
    return 0;
}