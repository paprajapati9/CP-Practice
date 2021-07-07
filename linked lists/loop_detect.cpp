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

		void groupReverse(int groupSize){
			Node * curr, *prev, *temphead, *temptail;
			curr = head;
			temphead = head;
			temptail = NULL;
			prev = NULL;
			int i = groupSize, cycles=0;
			while(curr != NULL && groupSize > 1){
				cout<<"i "<<i<<endl;
				cout<<"current "<<curr->data<<endl;
				Node *next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
				i--;
				if(i==0 || curr == NULL){
					i = groupSize;
					cycles++;
					if(cycles == 1){
						head = prev;
					}
					else{
						temptail->next = prev;

					}
					temptail = temphead;
					temphead->next = curr;
					temphead = curr;
					prev = NULL;

				}
			}
		}

};

int main(int argc, char const *argv[])
{
	LinkedList ll;
	ll.insert(20);
	ll.insert(40);
	ll.insert(60);
	ll.insert(50);
	ll.insert(10);
	ll.insert(90);
	ll.print();
	//ll.remove(20);
	ll.groupReverse(2);
	ll.print();
	return 0;
}
