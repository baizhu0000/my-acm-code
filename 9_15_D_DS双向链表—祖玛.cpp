#include <iostream>
using namespace std;
class ListNode {
   public:
    char data;
    ListNode* next;
    ListNode(char val) {
        data = val;
        next = NULL;
    }
    ListNode() {
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
    void insert(int i, char val);
    void del(int i);
    void shan();
    void display();
};
List::List() {
    len = 0;
    head = new ListNode();
}
List::~List() {
    ListNode *p, *q;
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
}
void List::set(int n) {
    ListNode* p = head;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        ListNode* q = new ListNode(c);
        p->next = q;
        p = q;
        len++;
    }
}

void List::insert(int i, char val) {
    if (i < 1 || i > len + 1) {
        return;
    }
    ListNode* p = head;
    for (int j = 1; j < i; j++) {
        p = p->next;
    }
    ListNode* q = new ListNode(val);
    q->next = p->next;
    p->next = q;
    len++;
    shan();
}
void List::del(int i) {
    if (i < 1 || i > len) {
        return;
    }
    ListNode* p = head;
    for (int j = 1; j < i; j++) {
        p = p->next;
    }
    ListNode* q = p->next;
    p->next = q->next;
    delete q;
    len--;
}
void List::shan() {
    bool pd = true;
    while (pd) {
        pd = false;
        ListNode* p = head;
        while (p->next != NULL) {
            ListNode* start = p->next;
            ListNode* end = start;
            int cnt = 1;
            while (end->next != NULL && end->next->data == start->data) {
                end = end->next;
                cnt++;
            }
            if (cnt >= 3) {
                ListNode* nex = end->next;
                ListNode* cur = start;
                while (cur != end) {
                    ListNode* tmp = cur;
                    cur = cur->next;
                    delete tmp;
                    len--;
                }
                delete end;
                len--;
                p->next = nex;
                pd = true;
                break;
            } else {
                p = start;
            }
        }
    }
}
void List::display() {
    if (head->next == NULL) {
        cout << "-" << endl;
        return;
    }
    ListNode* p = head->next;
    while (p != NULL) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}
int main() {
    int n, t;
    cin >> n;
    List list;
    list.set(n);
    cin >> t;
    while (t--) {
        int i;
        char c;
        cin >> i >> c;
        list.insert(i + 1, c);
        list.display();
    }
    return 0;
}