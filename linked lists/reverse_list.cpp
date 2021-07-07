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

		void reverse(){
			Node * curr, *prev;
			curr = head;
			prev = NULL;
			while(curr != NULL){
				Node *next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
		}

};

int main(int argc, char const *argv[])
{
	LinkedList ll;
	ll.insert(20);
	ll.insert(40);
	ll.insert(60);
	ll.print();
	ll.remove(20);
	ll.reverse();
	ll.print();
	return 0;
}
