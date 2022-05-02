//************************//
//**** SATYAM  ANAND *****//
//************************//

#pragma GCC optimize("O2")

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int d) : data(d), next(NULL) {}
};

node* buildList(){
    int d;
    cin >> d;
    if(d == -1) return NULL;
    node *n = new node(d);
    n->next = buildList();
    return n;
}

void push_back(node *&head, int d){
    node *n = new node(d);
    if(head == NULL){
        head = n;
        return;
    }
    node *tp = head;
    while(tp->next != NULL){
        tp = tp->next;
    }
    tp->next = n;
    return;
}

void push_front(node *&head, int d){
    node *n = new node(d);
    n->next = head;
    head = n;
    return;
}

void insertNthPos(node *&head, int d, int pos){
    node *n = new node(d);
    if(pos == 1){
        n->next = head;
        head = n;
    }
    else{
        node *tp = head;
        pos--;
        while(--pos){
            tp = tp->next;
        }
        n->next = tp->next;
        tp->next = n;   
    }
    return;
}

void printList(node *head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
    return;
}

void printListRev(node *&head){
    node *curr = head;
    node *prev = NULL;
    while(curr != NULL){
        curr = curr->next;
        head->next = prev;
        prev = head;
        if(curr != NULL)    head = curr;
    }
    return;
}

void findValue(node *head, int key){
    bool find = false;
    while(head != NULL){
        if(key == head->data){
            find = true;
            break;
        }
        head = head->next;
    }
    if(find == true)  cout << "Key Find\n";
    else  cout << "Key Not Find\n";  
    return;
}

void deleteNthPos(node *&head, int pos){
    if(pos == 1){
        node *tp = head;
        head = tp->next;
        delete tp;
    }
    else{
        node *tp = head;
        pos--;
        while(--pos){
            tp = tp->next;
        }
        tp->next = tp->next->next;
        delete tp->next;
    }
    return;
}

node* revNode(node *head){
    if(head == NULL or head->next == NULL) {
        return head;
    }
    node *tp = revNode(head->next);
    head->next->next = head;
    head->next = NULL;
    return tp;
}

void checkLoop(node *head){
    map<node *, int> hash;
    bool find = false;
    while(head != NULL){
        hash[head]++;
        if(hash[head] > 1){
            find = true;
            break;
        }
        head = head->next;
    }
    if(find){
        auto it = hash.rbegin();
        it->first->next = NULL;
        return;
    }
    return;
}

node* foldAndMerge(node *head){
    if(head == NULL)    return head;
    int ct = 0;
    node *tp = head;
    while(tp != NULL){
        tp = tp->next;
        ct++;
    }
    ct /= 2;
    stack<int> s;
    while(ct--){
        s.push(head->data);
        head = head->next;
    }
    node *newHead = new node(-1);
    node *ans = newHead;
    while(head != NULL){
        int x = s.top();
        int y = head->data;
        newHead->next = new node(x*y);
        newHead = newHead->next;
        s.pop();
        head = head->next;
    }
    return ans->next;
}

int midElementLinklist(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

bool loopFind(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)    return true;
    }
    return false;
}

void arrange(node* head){
    if(head == NULL or head->next == NULL or head->next->next == NULL)  return;
    node* first = head; node* second = head->next; node* curr = head->next->next; second->next = NULL; 
    int ct = 1; 
    while(curr){
        node* tp = curr->next;
        if(ct&1){
            curr->next = first->next; first->next = curr; first = curr;
        }
        else{
            curr->next = second->next; second->next = curr; second = curr;
        }
        curr = tp; ct++;
    }
}

node* evenOddChange(node* head){
    if(head == NULL or head->next == NULL)    return head;
    node* even = NULL; node* odd = NULL; node* curr = head; node* first_even = NULL; node* first_odd = NULL;
    while(curr){
        node* tp = curr->next;
        if((curr->data)&1){
            if(odd == NULL){
                first_odd = odd = curr; odd->next = NULL;
            }
            else{
                curr->next = odd->next; odd->next = curr; odd = curr;
            }
        }
        else{
            if(even == NULL){
                first_even = even = curr; even->next = first_odd;
            }
            else{
                curr->next = even->next; even->next = curr; even = curr;
            }
        }
        curr = tp;
    }
    return first_even == NULL ? first_odd : first_even;
}

int main(){
    node *head = buildList();
    printList(head);
    //arrange(head);
    head = evenOddChange(head);
    printList(head);
    return 0;
}
