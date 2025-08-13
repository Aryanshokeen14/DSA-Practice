#include <iostream>
#include <list>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop_front()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void printlist(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool iscycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "mil gya ";
            return true;
        }
    }
    cout << "na krti" << endl;
    return false;
}

void removecycle(Node *head)
{
    // detect cycle
    Node *slow = head;
    Node *fast = head;
    bool iscycle = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "mil gya ";
            iscycle = true;
            break;
        }
    }
    if (!iscycle)
    {
        cout << "cycle nhi hai";
        return;
    }
    slow = head;
    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        Node *prev = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}

Node *splitatmid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    List ans;
    Node *i = left;
    Node *j = right;
    while (i != NULL && j != NULL)
    {
        if (i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    // may be i is not fully traversed and j is finished
    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }
    // may be j is not fully traversed and i is finished
    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rightHead = splitatmid(head);
    Node *left = mergeSort(head);       // left head
    Node *right = mergeSort(rightHead); // right head
    return merge(left, right);
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // prev is head of reverse ll
}
Node* zigzag(Node* head)
{
    Node *righthead = splitatmid(head);
    Node *rightheadrev = reverse(righthead);

    // alternate merging
    Node *left = head;
    Node *right = rightheadrev;
    Node *tail = NULL;
    while (left != NULL && right != NULL)
    {
        Node *nextleft = left->next;
        Node *nextright = right->next;
        left->next = right;
        right->next = nextleft;

        tail = right;
        left = nextleft;
        right = nextright;
    }
    if (right != NULL)
    {
        tail->next = right;
    }
    return head;
}

int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(4); 
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    printlist(ll.head);
    // ll.tail->next=ll.head;
    // iscycle(ll.head);

    // removecycle(ll.head);
    // ll.head = mergeSort(ll.head);

    ll.head=zigzag(ll.head);
    printlist(ll.head);
}