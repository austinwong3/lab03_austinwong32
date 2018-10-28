#include <string>
#include "studentRoll.h"

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

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node *temp = orig.head;
  while(temp != NULL)
  {
    Student* s = new Student(*temp->s);
    this->insertAtTail(*s);
    temp= temp->next;
    delete s;
  }
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
    Student* s = new Student(*temp->s);
    this->insertAtTail(*s);
    temp= temp->next;
    delete s;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





