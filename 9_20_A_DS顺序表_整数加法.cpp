#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
    Node() {
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
        head = NULL;
    }
    void set(int n);
    void insert(int val);
    int addx(Node* p, int& x);
    void display();
    void add(int x);
};

void List::set(int n) {
    Node* p = head;
    int limit = (n > 1000) ? 1000 : n;  //
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i <= limit) {
            Node* q = new Node(x);
            p->next = q;
            p = p->next;
            len++;
        }
    }
}

void List::insert(int val) {
    Node* q = new Node(val);
    q->next = head->next;
    head->next = q;
    len++;
}

int List::addx(Node* p, int& x) {
    if (p == NULL) return 0;
    int temp = addx(p->next, x);
    int d = 0;
    if (x > 0) {
        d = x % 10;
        x /= 10;
    }
    int sum = p->data + d + temp;
    p->data = sum % 10;
    return sum / 10;
}

void List::add(int x) {
    int temp = addx(head->next, x);
    while (x > 0) {
        int d = x % 10;
        x /= 10;
        int sum = d + temp;
        insert(sum % 10);
        temp = sum / 10;
    }
    if (temp > 0) {
        insert(temp);
    }
}

void List::display() {
    cout << len << " ";
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
        int x;
        cin >> x;
        list.add(x);
        list.display();
    }
    return 0;
}