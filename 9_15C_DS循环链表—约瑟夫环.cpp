#include <iostream>
using namespace std;
class ListNode {
   public:
    int date;
    ListNode* next;

    ListNode(int val) {
        date = val;
        next = NULL;
    }
};
class List {
   public:
    ListNode* head;
    int len;

    List();
    ~List();
    void set(int n);
    void ans(int k, int s);
};
List::List() {
    head = NULL;
    len = 0;
}
List::~List() {
    if (head == NULL) {
        return;
    }
    ListNode* p = head;
    while (p->next != head) {
        p = p->next;
    }
    p->next = NULL;
    p = head;
    while (p != NULL) {
        ListNode* q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
    len = 0;
}
void List::set(int n) {
    head = new ListNode(1);
    ListNode* tail = head;
    for (int i = 2; i <= n; i++) {
        ListNode* s = new ListNode(i);
        tail->next = s;
        tail = s;
    }
    tail->next = head;
    len = n;
}
void List::ans(int k, int s) {
    if (head == NULL) {
        return;
    }
    ListNode* p = head;
    ListNode* pre = head;
    while (pre->next != head) {
        pre = pre->next;
    }
    for (int i = 1; i < s; i++) {
        pre = p;
        p = p->next;
    }

    while (p->next != p) {
        for (int i = 1; i < k; i++) {
            pre = p;
            p = p->next;
        }
        cout << p->date << " ";
        pre->next = p->next;
        delete p;
        p = pre->next;
        len--;
    }

    cout << p->date << " ";
    delete p;
    head = NULL;
    len = 0;

    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, s;
        cin >> n >> k >> s;

        List c;
        c.set(n);
        c.ans(k, s);
    }
    return 0;
}