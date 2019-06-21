#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* node){
	if (!node) os << "nullptr";
	else {
		os << "DATA: " << node->data; ///< " NEXT: " << node->next;
	}
	return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (!head) {
		head = new Node(d, nullptr);
	}
	else {
		add_at_end(head->next, d);
	}
}



/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
	os << head << "; ";
	if (head) print_list(os,head->next);
	//recursion!
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int dt){
	head = new Node(dt, head);
	
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head){
	if(!head) return nullptr;
	else if (!head->next) return head;
	//recursion
	else return last(head->next);
}

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head){
	if (!head){
		return false;
	}else{
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& curr){
	if (!curr){
		return false;
	} else{
		if (curr->next==nullptr){
			delete curr;
			curr = nullptr;
		} else{
			del_tail(curr->next);
		}
	}
	
}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head){
	if (!head){
		return nullptr;
	} else{
		head = head->next;
		return duplicate(new Node(head->data,head->next));
	}
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next){
	if (!curr){
		return nullptr;
	} else{
		return reverse(curr->next,new Node(curr->data,new_next));
	}
}

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2){
	last(list1)->next = list2;
	return list1;
}

