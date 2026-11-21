#include <iostream>
#include <string>
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
    Node* start;
    Node* end;

    List() {
        start = new Node();
        end = new Node();
    }
    ~List() {
        Node* q = start;
        while (q != NULL) {
            Node* p = q;
            q = q->next;
            delete p;
        }
        q = end;
        while (q != NULL) {
            Node* p = q;
            q = q->next;
            delete p;
        }
        start = NULL;
        end = NULL;
    }

    void add(int x);
    void finsh();
    void cancel();
    void query(int type);
};

void List::add(int x) {
    Node* p = start;
    while (p->next != NULL) {
        p = p->next;
    }
    Node* q = new Node(x);
    p->next = q;
}

void List::finsh() {
    if (start->next == NULL) {
        cout << "Invalid" << endl;
        return;
    }
    Node* x = start->next;
    int val = x->data;
    start->next = x->next;
    delete x;

    Node* q = end;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = new Node(val);
}

void List::cancel() {
    if (end->next == NULL) {
        cout << "Invalid" << endl;
        return;
    }
    Node* pre = end;
    while (pre->next->next != NULL) {
        pre = pre->next;
    }
    Node* p = pre->next;
    int val = p->data;

    pre->next = NULL;
    delete p;

    Node* q = start;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = new Node(val);
}

void List::query(int type) {
    if (type == 1) {
        if (start->next == NULL) {
            cout << "Invalid" << endl;
            return;
        }
        cout << start->next->data << endl;
    } else {
        if (end->next == NULL) {
            cout << "Invalid" << endl;
            return;
        }
        Node* q = end;
        while (q->next != NULL) {
            q = q->next;
        }
        cout << q->data << endl;
    }
}

int main() {
    int n;
    cin >> n;
    List a;
    while (n--) {
        string s;
        cin >> s;
        if (s == "ADD") {
            int x;
            cin >> x;
            a.add(x);
        } else if (s == "FINISH") {
            a.finsh();
        } else if (s == "CANCEL") {
            a.cancel();
        } else if (s == "QUERY") {
            int x;
            cin >> x;
            a.query(x);
        }
    }
    return 0;
}