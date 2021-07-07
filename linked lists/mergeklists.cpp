#include <bits/stdc++.h>

using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		Node(int dvalue){
			data = dvalue;
		}	
};

class LinkedList
{
	public:
		Node * head;
		LinkedList(){
			head=NULL;
		};

		void insert(int dvalue){
			Node * element = new Node(dvalue);
			element->next = head;
			head = element;
		}

		void print(){
			Node * curr;
			curr = head;
			while(curr != NULL){
				cout<<curr->data<<" -> ";
				curr = curr->next;
			}
			cout<<"NULL";
			cout<<endl;
		}

		void remove(int dvalue){
			Node *curr, *prev;
			curr = head;
			prev = NULL;
			while(curr != NULL){
				if(curr->data == dvalue){
					if(prev == NULL){
						head = curr->next;
					}
					else{
						prev->next = curr->next;
					}
					break;
				}
				prev = curr;
				curr = curr->next;
			}
		}
};

Node* mergeLists(Node* l1, Node* l2) {
    if(!l1){
        return l2;
    }
    if(!l2)
        return l1;
    if(!l1 && !l2){
        return NULL;
    }
    Node* result = new Node(0);
    if(l1->data < l2->data){
        result = l1;
        l1 = l1->next;
        
    }else{
        result = l2;
        l2 = l2->next;
    }
    Node* head = result;
    while(l1 && l2){
        if(l1->data < l2->data){
            result->next = l1;
            l1 = l1->next;
        }else{
            result->next = l2;
            l2 = l2->next;
        }
        result = result->next;
    }
    if(!l1){
        result->next = l2;
    }else{
        result->next = l1;
    }
    return head;
    
}

void print(Node * head){
	Node * curr;
	curr = head;
	while(curr != NULL){
		cout<<curr->data<<" -> ";
		curr = curr->next;
	}
	cout<<"NULL";
	cout<<endl;
}

Node* mergeKLists(vector<Node*> &lists) {
	int k = lists.size();
    while(k > 1){
        lists[1] = mergeLists(lists[0], lists[1]);
        lists.front() = std::move(lists.back());
    	lists.pop_back();
        k = lists.size();
    }
    print(lists[0]);
    return lists[0];
}

int main(int argc, char const *argv[])
{
	LinkedList ll1, ll2, ll3, ll4, ll5;
	vector<Node*> lists(5);
	ll1.insert(120);
	ll1.insert(80);
	ll1.insert(50);
	ll1.insert(15);
	ll2.insert(110);
	ll2.insert(90);
	ll2.insert(50);
	ll2.insert(5);
	ll3.insert(113);
	ll3.insert(94);
	ll3.insert(51);
	ll3.insert(5);
	ll3.insert(1);
	ll4.insert(96);
	ll4.insert(52);
	ll4.insert(14);
	//ll1.print();
	//ll2.print();
	lists[0] = ll1.head;
	lists[1] = ll2.head;
	lists[2] = ll3.head;
	lists[3] = ll4.head;
	lists[4] = ll5.head;
	mergeKLists(lists);

	ll1.merge(ll1.head, ll2.head);
	//ll1.print();
	return 0;
}
