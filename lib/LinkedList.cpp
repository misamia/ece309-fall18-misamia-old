#include <stdio.h>

// Holds a string
class Item {

public:

  const char * str;
  Item(const char *as = "") { 
    str = as;
  }
};


class List {

private:

  class ListNode { 							// ListNode represents each node of the list

  private:
  
    Item item; 								// data in the list
    ListNode *next;	

  public:

    ListNode(Item a) { 
      item = a; 
      next=NULL; 							// automatically serves as a list tail
    }

    ListNode* getNext() { 
      return next; 
    }

    void setNext(ListNode *n) { 
      next = n; 
	 }

    Item getItem() { 
      return item; 
    }

  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

public:
  List();
  void push_back(Item a);    
  Item remove_front(Item &a); 
  int length();
  Item get(int y);
  bool empty(); 
  ~List();

};

List::List(){ 								// default constructor; start with an empty list
  head = NULL;
  tail = NULL;
}

void List::push_back(Item a){ 				// add string to the tail of the list
	
  ListNode *node = new ListNode(a);
  if (head == NULL){ 						// list is empty
      head = node;
      tail = node;
    }

  else {
      tail->setNext(node);
      tail = node;
    }
}

Item List::remove_front(Item &copy) {

  if (!empty()) {							// if list is not empty 

      copy = head->getItem(); 				// return copy
      ListNode *tmp = head->getNext();
      delete head; 							// delete the node
      head = tmp;  							// update the head
      if (tmp==NULL){ 						// removed last element, empty list
			tail = NULL;
		}
      return copy;
    }
	
	return NULL; 							// if list is empty

}

int List::length(){							// get number of items in the list
	ListNode *tmp = head;
	for(int m = 1; tmp != NULL; m++){		// basic traversal 
	tmp = tmp -> next;
	}
	return m;
}

Item List::get(int y){						// get item in the list
	ListNode *tmp = head;
	if( y <= length()){						// check if y is within range
		for(int m = 1; m <= y; m++){		// basic traversal 
		tmp = tmp -> next;
		Item nterm = tmp -> getItem();
		return nterm;
	}
	return NULL;
}

bool List::empty(){
	
  return head==NULL;
}

List::~List(){								// Free all of the ListNodes in the list

	Item copy;								// ? is it copy
	  while(!empty()) {

      remove_front(copy);
      printf("Next thing removed: %s\n",copy.str);
	}
}


int main(){
  List l;
  
  l.push_back(Item("milk"));
  l.push_back(Item("eggs"));
  l.push_back(Item("bread"));
  l.push_back(Item("potato chips"));
  l.push_back(Item("toothpaste"));


  return 0;
}