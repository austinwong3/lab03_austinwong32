#include <string>
#include "studentRoll.h"
#include <iostream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *temp = new Node;
  temp->s = new Student(s);
  temp->next = NULL;
  if(this->head == NULL)
  {
    this->head = this->tail = temp;
  }
  else{
    this->tail->next = temp;
    this->tail = temp;
  }

}

std::string StudentRoll::toString() const {
  std::string c = "[";
  if(this->head != NULL)
  {

    Node *temp = head;
    while(temp != NULL)
    {

      c += (temp->s)->toString();
      if (temp->next != NULL)
        c += ",";
      temp = temp->next;

    }
  }
  c += "]";
  return c;
}

Student StudentRoll::getHeadS()
{
  return *this->head->s;
}
StudentRoll::StudentRoll(const StudentRoll &orig) {
  Node *temp = orig.head;
  while(temp != NULL)
  {
    this->insertAtTail(*temp->s);
    temp= temp->next;
  }

  
  
  /*if (orig.head == NULL)
    this->head = this->tail = NULL;
  else{
    Node* n = new Node;
    Node *temp = orig.head;
    std::cout<<"huh1"<<std::endl;
    n->s = temp->s;
    std::cout<<"huh2"<<std::endl;
    n->next = new Node;
    std::cout<<"huh3"<<std::endl;
    this->head = n;
    std::cout<<"huh4"<<std::endl;
    n = n->next;
    std::cout<<"huh5"<<std::endl;
    temp = temp->next;
    std::cout<<"huh6"<<std::endl;
    if(temp == NULL)
    {
      std::cout<<"into if"<<std::endl;
      n = NULL;
      this->head = this->tail;
    }
    else{
      std::cout<<"into else"<<std::endl;
      while (temp->next!=NULL)
      {
        std::cout<<"into while"<<std::endl;
        n->s = temp->s;
        n->next= new Node;
        n = n->next;
        temp = temp->next;
      }
      n->s= temp->s;
      n->next = NULL;
      this->tail = n;
      delete n;
    }
  }*/
}

StudentRoll::~StudentRoll() {
  Node *temp = head;
  while(temp != NULL)
  {
    Node * d = temp;
    temp = temp->next;
    delete d->s;
    delete d;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  
  Node *temp = right.head;
  while(temp != NULL)
  {
    this->insertAtTail(*temp->s);
    temp= temp->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





