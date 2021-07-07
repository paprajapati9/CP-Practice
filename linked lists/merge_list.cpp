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

		void merge(Node  * &head1, Node * &head2){
			Node *h1, *h2, *prev1 = NULL, *temp;
			h1 = head1, h2 = head2;
			while(h1 != NULL && h2 != NULL){
				if(h1->data > h2->data){
					temp = h2;
					if(prev1 != NULL){
						prev1->next = h2;
						h2 = h2->next;
						temp->next = h1;
					}else{
						h2 = h2->next;
						temp->next = h1;
						head1 = temp;
					}
					h1 = temp;
				}else{
					prev1 = h1;
					h1 = h1->next;
				}
			}
			if(h1 == NULL){
				prev1->next = h2;
			}
		}

};

int main(int argc, char const *argv[])
{
	LinkedList ll1, ll2;
	ll1.insert(120);
	ll1.insert(80);
	ll1.insert(50);
	ll1.insert(15);
	ll2.insert(110);
	ll2.insert(90);
	ll2.insert(50);
	ll2.insert(5);
	ll1.print();
	ll2.print();
	ll1.merge(ll1.head, ll2.head);
	ll1.print();
	return 0;
}
