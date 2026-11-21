#include <iostream>
using namespace std;

class Node {
   public:
    int exp;
    int data;
    Node* next;
    Node(int val, int i) {
        exp = i;
        data = val;
        next = NULL;
    }
    Node() {
        next = NULL;
    }
};

class List {
   public:
    Node* head;
    List() {
        head = new Node();
    }
    ~List();
    void set(int n);
    void display();
    void insert(int val, int exp);
};

List::~List() {
    Node* p = head;
    while (p != NULL) {
        Node* q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}

void List::insert(int val, int exp) {
    Node* p = head;
    while (p->next != NULL && p->next->exp < exp) {
        p = p->next;
    }
    if (p->next != NULL && p->next->exp == exp) {
        p->next->data += val;
        return;
    }
    Node* q = new Node(val, exp);
    q->next = p->next;
    p->next = q;
}

void List::set(int n) {
    for (int i = 0; i < n; i++) {
        int val, exp;
        cin >> val >> exp;
        insert(val, exp);
    }
}

void List::display() {
    Node* p = head->next;
    bool first = true;
    while (p != NULL) {
        if (p->data == 0) {
            p = p->next;
            continue;
        }
        if (!first)
            cout << " + ";

        if (p->data < 0)
            cout << "(" << p->data << ")";
        else
            cout << p->data;

        if (p->exp != 0) {
            cout << "x^";
            if (p->exp < 0)
                cout << "(" << p->exp << ")";
            else
                cout << p->exp;
        }

        first = false;
        p = p->next;
    }
    cout << endl;
}

void add(List& a, List& b, List& result) {
    Node* pa = a.head->next;
    Node* pb = b.head->next;
    Node* tail = result.head;
    while (pa != NULL && pb != NULL) {
        if (pa->exp < pb->exp) {
            tail->next = new Node(pa->data, pa->exp);
            tail = tail->next;
            pa = pa->next;
        } else if (pa->exp > pb->exp) {
            tail->next = new Node(pb->data, pb->exp);
            tail = tail->next;
            pb = pb->next;
        } else {
            int sum = pa->data + pb->data;
            if (sum != 0) {
                tail->next = new Node(sum, pa->exp);
                tail = tail->next;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    while (pa != NULL) {
        tail->next = new Node(pa->data, pa->exp);
        tail = tail->next;
        pa = pa->next;
    }
    while (pb != NULL) {
        tail->next = new Node(pb->data, pb->exp);
        tail = tail->next;
        pb = pb->next;
    }
    tail->next = NULL;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        List A;
        A.set(n);

        int m;
        cin >> m;
        List B;
        B.set(m);

        A.display();
        B.display();

        List C;
        add(A, B, C);
        C.display();
    }
    return 0;
}