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

int addLists(Node* l1, Node* l2, Node* &head1) {
	int sum=0;
    if(l1->next == NULL){
    	sum = l1->data + l2->data;
    	l1->data = sum%10;
    	return sum/10; //carry
    }

    sum = l1->data + l2->data + addLists(l1->next, l2->next, head1);
    l1->data = sum%10;
    if(l1 == head1){
    	if(sum/10 > 0){
    		Node * element = new Node(sum/10);
			element->next = head1;
			head1 = element;
			return 0;
	    }else{
	    	return 0;
	    }
    }else{
    	return sum/10;
    }
    
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

int listLength(Node* curr) {
	int listLength = 0;
	while(curr != NULL){
		listLength++;
		curr = curr->next;
	}
	return listLength;
}

void addZeros(Node * &head, int zeros) {
	while(zeros--){
		Node * element = new Node(0);
		element->next = head;
		head = element;
	}
}

int main(int argc, char const *argv[])
{
	LinkedList ll1, ll2;
	ll1.insert(1);
	ll1.insert(8);
	ll1.insert(5);
	ll1.insert(9);
	ll2.insert(1);
	ll2.insert(9);
	ll2.insert(5);
	int len1, len2;
	len1 = listLength(ll1.head);
	len2 = listLength(ll2.head);
	if(len1 > len2){
		addZeros(ll2.head, len1-len2);
	}else{
		addZeros(ll1.head, len2-len1);
	}
	// if(!l1){
 //        return l2;
 //    }
 //    if(!l2)
 //        return l1;
 //    if(!l1 && !l2){
 //        return NULL;
 //    }
	ll1.print();
	ll2.print();
	addLists(ll1.head, ll2.head, ll1.head);
	ll1.print();
	return 0;
}
